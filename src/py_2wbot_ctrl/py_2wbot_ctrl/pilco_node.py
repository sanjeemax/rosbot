
import rclpy
import numpy as np
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Pose, Twist
from more_interfaces.srv import PilcoTwist
from py_2wbot_ctrl.gpr_rosbot import GPR_rosbot
from py_2wbot_ctrl.svm_rosbot import SVM_rosbot
from std_srvs.srv import Empty


class PilcoNode(Node):
    def __init__(self):
        super().__init__('pilco_node')
        self.req = Empty.Request()
        self.state_stack = []
        self.publisher = self.create_publisher(Twist, '/demo/cmd_demo', rclpy.qos.qos_profile_system_default)
        self.subscription = self.create_subscription(
        Odometry,
        '/demo/odom_demo',  # Topic name
        self.odom_callback,  # Callback function
        1  # QoS profile depth
        )
        self.gpr_rosbot = SVM_rosbot()#GPR_rosbot()
        self.gpr_rosbot.loadModel()

        self.pilco_service = self.create_service(PilcoTwist, 'pilco_service', self.pilco_service_callback)
        self.start_pilco_client = self.create_client(Empty, 'start_pilco')
        while not self.start_pilco_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.send_pilco_request()


    def pilco_service_callback(self,request, response):
        """
        pilco service
        """
        state = self.state_stack.pop()
        np_state = np.array(state)
        print("stop: move")
        response.linx = 1.5
        response.revz = gpr_rosbot.predict(np_state)
        self.get_logger().info('Incoming request\na: %d b: %d' % (response.linx, response.revz))
        return response

    def odom_callback(self, msg):
        # This function will be called each time an Odometry message is received
        # Access the pose
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

        self.state_stack.append(state)


    def send_pilco_request(self):
        self.future = self.start_pilco_client.call_async(self.req)
        rclpy.spin_until_future_complete(self,self.future)
        return self.future.result()

def main(args=None):
    rclpy.init(args=args)
    pico_node = PilcoNode()
    rclpy.spin(pico_node)
    pico_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
