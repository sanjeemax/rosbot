import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
#from py_custom_state_msg.msg import CustomMsg
from more_interfaces.msg import CustomState

class JointStateSubscriber(Node):
    def __init__(self):
        super().__init__('joint_state_subscriber')
        self.subscription = self.create_subscription(
            JointState,
            'joint_states',  # Topic name
            self.joint_state_callback,  # Callback function
            10  # QoS profile depth
        )
        self.subscription  # Prevent unused variable warning

        self.state_subscription = self.create_subscription(
            CustomState,
            '/demo/cust_state',  # Topic name
            self.joint_state_callback2,  # Callback function
            10  # QoS profile depth
        )
        self.state_subscription  # Prevent unused variable warning

    def joint_state_callback2(self, msg):
        # This function will be called each time a JointState message is received
        # Access joint names
        #robot_name = msg.name

        robot_error = msg.err
        # Access joint positions
        robot_linear_x = msg.linear_x
        # Access joint velocities
        robot_angular_z = msg.angular_z
        # Access joint efforts
        #print("robot_error : {}".format(robot_error))
        #print("robot_linear_x : {}".format(robot_linear_x))
        #print("robot_angular_z : {}".format(robot_angular_z))


    def joint_state_callback(self, msg):
        # This function will be called each time a JointState message is received
        # Access joint names
        joint_names = msg.name
        # Access joint positions
        joint_positions = msg.position
        # Access joint velocities
        joint_velocities = msg.velocity
        # Access joint efforts
        joint_efforts = msg.effort
        print("joint_positions : {}".format(joint_positions))
        i = 0
        for joint in joint_names:
            print("joint : {}".format(joint))
            print("vel : {}".format(joint_velocities[i]))
            print("pos : {}".format(joint_positions[i]))
            i = i + 1


def main(args=None):
    rclpy.init(args=args)
    joint_state_subscriber = JointStateSubscriber()
    rclpy.spin(joint_state_subscriber)
    joint_state_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
