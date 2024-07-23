import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from std_srvs.srv import Empty
import time
from datetime import datetime
import csv
from more_interfaces.msg import CustomState

RUN_TIME = 8#10
LOG_FILE_PATH = "/home/lasantha/"

class OdomSubscriber(Node):
    def __init__(self):
        super().__init__('odom_subscriber')
        self.subscription = self.create_subscription(
            Odometry,
            '/demo/odom_demo',  # Topic name
            self.odom_callback,  # Callback function
            1  # QoS profile depth
        )

        self.state_subscription = self.create_subscription(
            CustomState,
            '/demo/cust_state',  # Topic name
            self.joint_state_callback2,  # Callback function
            1  # QoS profile depth
        )

        self.start_client = self.create_client(Empty, 'start_follower')
        while not self.start_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')

        self.stop_client = self.create_client(Empty, 'stop_follower')
        while not self.stop_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        
        timestr = time.strftime("%Y%m%d-%H%M%S")
        self.filename = LOG_FILE_PATH + timestr + ".csv"
        self.logdata = []
        self.req = Empty.Request()
        self.start_time = time.time()
        self.subscription  # Prevent unused variable warning


    def joint_state_callback2(self, msg):
        # This function will be called each time a JointState message is received
        # Access joint names
        #robot_name = msg.name
        row = []
        timestr = datetime.now().strftime("%H:%M:%S.%f")#time.strftime("%H%M%S%f")
        row.append(timestr)

        robot_error = msg.err
        row.append(msg.err)
        # Access joint positions
        robot_linear_x = msg.linear_x
        row.append(msg.linear_x)
        row.append(msg.linear_y)
        row.append(msg.linear_z)
        # Access joint velocities
        robot_angular_z = msg.angular_z
        row.append(msg.angular_x)
        row.append(msg.angular_y)
        row.append(msg.angular_z)
        # Access joint efforts
        print("robot_error : {}".format(robot_error))
        #print("robot_linear_x : {}".format(robot_linear_x))
        #print("robot_angular_z : {}".format(robot_angular_z))
        self.logdata.append(row)

    def odom_callback(self, msg):
        # This function will be called each time an Odometry message is received
        # Access the pose
        row = []
        #timestr = time.strftime("%H%M%S%f")
        timestr = datetime.now().strftime("%H:%M:%S.%f")
        row.append(timestr)

        pose = msg.pose.pose
        position = pose.position
        row.append(position.x)
        row.append(position.y)
        row.append(position.z)

        orientation = pose.orientation
        row.append(orientation.x)
        row.append(orientation.y)
        row.append(orientation.z)
        # Access the twist (linear and angular velocities)
        twist = msg.twist.twist
        linear_velocity = twist.linear
        row.append(linear_velocity.x)
        row.append(linear_velocity.y)
        row.append(linear_velocity.z)

        angular_velocity = twist.angular
        row.append(angular_velocity.x)
        row.append(angular_velocity.y)
        row.append(angular_velocity.z)
        end_time = time.time()
        elapsed_time = end_time - self.start_time
        #print("elapsed_time: {}".format(elapsed_time))
        self.logdata.append(row)
        if(elapsed_time > RUN_TIME):
            self.log_data_to_csv()
            self.send_stop_request()
            print("TIME has finished")
            #log_data_to_csv()


    def send_start_request(self):
        self.future = self.start_client.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

    def send_stop_request(self):
        self.future = self.stop_client.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

    def log_data_to_csv(self):
        with open(self.filename, 'w') as csvfile:
            # creating a csv writer object
            csvwriter = csv.writer(csvfile)
        
            # writing the fields
            #csvwriter.writerow(fields)
        
            # writing the data rows
            csvwriter.writerows(self.logdata)
            print("data written to : {}".format(self.filename))

def main(args=None):
    rclpy.init(args=args)
    odom_subscriber = OdomSubscriber()
    odom_subscriber.send_start_request()
    rclpy.spin(odom_subscriber)
    odom_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
