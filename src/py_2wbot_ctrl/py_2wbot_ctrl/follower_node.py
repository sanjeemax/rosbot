"""
#!/usr/bin/env python3
A ROS2 node used to control a differential drive robot with a camera,
so it follows the line in a Robotrace style track.
You may change the parameters to your liking.
"""
__author__ = "Gabriel Nascarella Hishida do Nascimento"

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import Pose, Twist
from std_srvs.srv import Empty
from gazebo_msgs.srv import SetEntityState
#from py_custom_state_msg.msg import CustomMsg
from more_interfaces.msg import CustomState
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Pose, Twist
from more_interfaces.srv import PilcoTwist
from py_2wbot_ctrl.gpr_rosbot import GPR_rosbot

import numpy as np
import cv2
import cv_bridge

# Create a bridge between ROS and OpenCV
bridge = cv_bridge.CvBridge()

## User-defined parameters: (Update these values to your liking)
# Minimum size for a contour to be considered anything
MIN_AREA = 500 

# Minimum size for a contour to be considered part of the track
MIN_AREA_TRACK = 5000

# Robot's speed when following the line
LINEAR_SPEED = 1.5

# Proportional constant to be applied on speed when turning 
# (Multiplied by the error value)
KP = 1.5/100 

# If the line is completely lost, the error value shall be compensated by:
LOSS_FACTOR = 1.2

# Send messages every $TIMER_PERIOD seconds
TIMER_PERIOD = 0.06

# When about to end the track, move for ~$FINALIZATION_PERIOD more seconds
FINALIZATION_PERIOD = 4

# The maximum error value for which the robot is still in a straight line
MAX_ERROR = 30

# BGR values to filter only the selected color range
#lower_bgr_values = np.array([31,  42,  53])
#upper_bgr_values = np.array([255, 255, 255])
lower_bgr_values = np.array([100, 50, 50])
upper_bgr_values = np.array([130, 255, 255])

def crop_size(height, width):
    """
    Get the measures to crop the image
    Output:
    (Height_upper_boundary, Height_lower_boundary,
     Width_left_boundary, Width_right_boundary)
    """
    ## Update these values to your liking.

    return (1*height//3, height, width//4, 3*width//4)


# Global vars. initial values
image_input = 0
error = 0
just_seen_line = False
just_seen_right_mark = False
should_move = False
right_mark_count = 0
finalization_countdown = None
pilco = False
state_stack = []
def reset_follower_callback(request, response):
    """
    Reset the robot.
    """
    # Create a Pose object representing the desired position and orientation
    pose = Pose()
    # Set the position (adjust the values as needed)-0.151427 -0 0.175
    pose.position.x = -0.151427
    pose.position.y = 0.0
    pose.position.z = 0.175
    # Set the orientation (adjust the values as needed)
    pose.orientation.x = 0.0
    pose.orientation.y = 0.0
    pose.orientation.z = 0.0
    pose.orientation.w = 1.0  # No rotation (identity quaternion)

    # Create a Twist object representing the desired linear and angular velocity
    twist = Twist()
    # Set linear velocity (optional)
    twist.linear.x = 0.0
    twist.linear.y = 0.0
    twist.linear.z = 0.0
    # Set angular velocity (optional)
    twist.angular.x = 0.0
    twist.angular.y = 0.0
    twist.angular.z = 0.0
    client = node.create_client(SetEntityState, '/gazebo/set_entity_state')

        # Create a SetEntityState request message
    request = SetEntityState.Request()
    request.state.name = '2wbot'  # Replace 'robot_name' with the name of your robot in Gazebo
    request.state.pose = pose
    request.state.twist = twist

    # Call the service
    future = client.call_async(request)
    rclpy.spin_until_future_complete(node, future)

    if future.result() is not None:
        print('Robot position reset successfully')
    else:
        print('Failed to reset robot position')

    print("start: move")
    return response

def start_pilco_mode_callback(request, response):
    """
    Start the pilco mode.
    In other words, allow it to move pilco mode
    """
    global pilco
    pilco = True
    print("start: pilco mode")
    return response


def start_follower_callback(request, response):
    """
    Start the robot.
    In other words, allow it to move (again)
    """
    global should_move
    global right_mark_count
    global finalization_countdown
    should_move = True
    right_mark_count = 0
    finalization_countdown = None
    print("start: move")
    return response

def stop_follower_callback(request, response):
    """
    Stop the robot
    """
    global should_move
    global finalization_countdown
    should_move = False
    finalization_countdown = None
    print("stop: move")
    return response

def image_callback(msg):
    """
    Function to be called whenever a new Image message arrives.
    Update the global variable 'image_input'
    """
    global image_input
    image_input = bridge.imgmsg_to_cv2(msg,desired_encoding='bgr8')
    # node.get_logger().info('Received image')

def get_contour_data(mask, out):
    """
    Return the centroid of the largest contour in
    the binary image 'mask' (the line) 
    and return the side in which the smaller contour is (the track mark) 
    (If there are any of these contours),
    and draw all contours on 'out' image
    """ 
    # get a list of contours
    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)

    mark = {}
    line = {}

    for contour in contours:
        
        M = cv2.moments(contour)
        # Search more about Image Moments on Wikipedia :)

        if M['m00'] > MIN_AREA:
        # if countor.area > MIN_AREA:

            if (M['m00'] > MIN_AREA_TRACK):
                # Contour is part of the track
                line['x'] = crop_w_start + int(M["m10"]/M["m00"])
                line['y'] = int(M["m01"]/M["m00"])

                # plot the area in light blue
                cv2.drawContours(out, contour, -1, (255,255,0), 1) 
                cv2.putText(out, str(M['m00']), (int(M["m10"]/M["m00"]), int(M["m01"]/M["m00"])),
                    cv2.FONT_HERSHEY_PLAIN, 2, (255,255,0), 2)
                #break
            
            else:
                # Contour is a track mark
                if (not mark) or (mark['y'] > int(M["m01"]/M["m00"])):
                    # if there are more than one mark, consider only 
                    # the one closest to the robot 
                    mark['y'] = int(M["m01"]/M["m00"])
                    mark['x'] = crop_w_start + int(M["m10"]/M["m00"])

                    # plot the area in pink
                    cv2.drawContours(out, contour, -1, (255,0,255), 1) 
                    cv2.putText(out, str(M['m00']), (int(M["m10"]/M["m00"]), int(M["m01"]/M["m00"])),
                        cv2.FONT_HERSHEY_PLAIN, 2, (255,0,255), 2)


    if mark and line:
    # if both contours exist
        if mark['x'] > line['x']:
            mark_side = "right"
        else:
            mark_side = "left"
    else:
        mark_side = None


    return (line, mark_side)

def timer_callback():
    """
    Function to be called when the timer ticks.
    According to an image 'image_input', determine the speed of the robot
    so it can follow the contour
    """

    global error
    global image_input
    global just_seen_line
    global just_seen_right_mark
    global should_move
    global right_mark_count
    global finalization_countdown
    global pilco

    message = Twist()
    #state_msg = CustomMsg()
    state_msg = CustomState()
    if not pilco:
        # Wait for the first image to be received
        if type(image_input) != np.ndarray:
            return

        height, width, _ = image_input.shape

        image = image_input.copy()

        global crop_w_start
        crop_h_start, crop_h_stop, crop_w_start, crop_w_stop = crop_size(height, width)

        # get the bottom part of the image (matrix slicing)
        crop = image[crop_h_start:crop_h_stop, crop_w_start:crop_w_stop]

        crop_hsv = cv2.cvtColor(crop, cv2.COLOR_BGR2HSV)
        
        # get a binary picture, where non-zero values represent the line.
        # (filter the color values so only the contour is seen)
        #mask = cv2.inRange(crop, lower_bgr_values, upper_bgr_values)
        mask = cv2.inRange(crop_hsv, lower_bgr_values, upper_bgr_values)

        # get the centroid of the biggest contour in the picture,
        # and plot its detail on the cropped part of the output image
        output = image
        line, mark_side = get_contour_data(mask, output[crop_h_start:crop_h_stop, crop_w_start:crop_w_stop])  
        # also get the side in which the track mark "is"
        

        
        if line:
        # if there even is a line in the image:
        # (as the camera could not be reading any lines)      
            x = line['x']

            # error:= The difference between the center of the image
            # and the center of the line
            error = x - width//2
            state_msg.err = float(error)

            message.linear.x = LINEAR_SPEED
            state_msg.linear_x = float(LINEAR_SPEED)
            just_seen_line = True

            # plot the line centroid on the image
            cv2.circle(output, (line['x'], crop_h_start + line['y']), 5, (0,255,0), 7)

        else:
            # There is no line in the image. 
            # Turn on the spot to find it again. 
            if just_seen_line:
                just_seen_line = False
                error = error * LOSS_FACTOR
            message.linear.x = 0.0

        if mark_side != None:
            print("mark_side: {}".format(mark_side))

            if (mark_side == "right") and (finalization_countdown == None) and \
                (abs(error) <= MAX_ERROR) and (not just_seen_right_mark):

                right_mark_count += 1

                if right_mark_count > 1:
                    # Start final countdown to stop the robot
                    finalization_countdown = int(FINALIZATION_PERIOD / TIMER_PERIOD) + 1
                    print("Finalization Process has begun!")

                
                just_seen_right_mark = True
        else:
            just_seen_right_mark = False

        
        # Determine the speed to turn and get the line in the center of the camera.
        message.angular.z = float(error) * -KP
        state_msg.angular_z = float(error) * -KP
        print("Error: {} | Angular Z: {}, Linear X: {}".format(error, message.angular.z, message.linear.x))

        # Plot the boundaries where the image was cropped
        cv2.rectangle(output, (crop_w_start, crop_h_start), (crop_w_stop, crop_h_stop), (0,0,255), 2)

        # Uncomment to show the binary picture
        #cv2.imshow("mask", mask)

        # Show the output image to the user
        cv2.imshow("output", output)
        # Print the image for 5milis, then resume execution
        cv2.waitKey(5)
    else:
        print("pilco mode")
        state = state_stack.pop()
        print(state)
        np_state = np.array(state)
        np_state_reshaped = np_state.reshape(1, -1)
        message.linear.x = 1.47
        revz = gpr_rosbot.predict(np_state_reshaped)
        message.angular.z = float(revz) #* -KP


    # Check for final countdown
    if finalization_countdown != None:
        if finalization_countdown > 0:
            finalization_countdown -= 1

        elif finalization_countdown == 0:
            should_move = False


    # Publish the message to 'cmd_vel'
    if should_move:
        print("Msg:  Angular Z: {}, Linear X: {}".format(message.angular.z, message.linear.x))
        publisher.publish(message)
        state_publisher.publish(state_msg)
    else:
        print("Msg: Empty")
        empty_message = Twist()
        empty_custom_msg = CustomState()
        publisher.publish(empty_message)
        state_publisher.publish(empty_custom_msg)

def odom_callback(msg):
    # This function will be called each time an Odometry message is received
    # Access the pose
    global state_stack
    state = []
    #timestr = time.strftime("%H%M%S%f")
    pose = msg.pose.pose
    position = pose.position
    state.append(position.x)
    state.append(position.y)

    orientation = pose.orientation
    state.append(orientation.z)

    # Access the twist (linear and angular velocities)
    twist = msg.twist.twist
    linear_velocity = twist.linear
    state.append(linear_velocity.x)
    state.append(linear_velocity.y)

    angular_velocity = twist.angular
    state.append(angular_velocity.z)

    state_stack.append(state)

def main():
    rclpy.init()
    global node
    node = Node('follower')

    global state_publisher
    global publisher
    global gp_client
    global request
    global future
    global gpr_rosbot
    publisher = node.create_publisher(Twist, '/demo/cmd_demo', rclpy.qos.qos_profile_system_default)
    state_publisher = node.create_publisher(CustomState, '/demo/cust_state', rclpy.qos.qos_profile_system_default)
    subscription = node.create_subscription(Image, '/demo_cam/camera1/image_raw',
                                            image_callback,
                                            rclpy.qos.qos_profile_sensor_data)
    odo_subscription = node.create_subscription(
        Odometry,
        '/demo/odom_demo',  # Topic name
        odom_callback,  # Callback function
        1  # QoS profile depth
        )                                        
    gpr_rosbot = GPR_rosbot()
    gpr_rosbot.loadModel()
    timer = node.create_timer(TIMER_PERIOD, timer_callback)

    start_service = node.create_service(Empty, 'start_follower', start_follower_callback)
    stop_service = node.create_service(Empty, 'stop_follower', stop_follower_callback)
    reset_service = node.create_service(Empty, 'reset_follower', reset_follower_callback)
    pilco_service = node.create_service(Empty, 'start_pilco', start_pilco_mode_callback)
    rclpy.spin(node)

try:
    main()
except (KeyboardInterrupt, rclpy.exceptions.ROSInterruptException):
    empty_message = Twist()
    publisher.publish(empty_message)

    node.destroy_node()
    rclpy.shutdown()
    exit()