import rclpy
from rclpy.node import Node

from more_interfaces.msg import CustomState                            # CHANGE


class CustomPublisher(Node):

    def __init__(self):
        super().__init__('custom_publisher')
        self.publisher_ = self.create_publisher(CustomState, 'custom_topic', 10)  # CHANGE
        timer_period = 0.5
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg = CustomState()                                                # CHANGE
        msg.err = 1.03                                           # CHANGE
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%d"' % msg.err)       # CHANGE
        self.i += 1


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = CustomPublisher()

    rclpy.spin(minimal_publisher)

    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
