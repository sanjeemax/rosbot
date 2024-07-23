import rclpy
from rclpy.node import Node

from more_interfaces.msg import CustomState                        # CHANGE


class CustomSubscriber(Node):

    def __init__(self):
        super().__init__('custom_subscriber')
        self.subscription = self.create_subscription(
            CustomState,                                               # CHANGE
            'custom_topic',
            self.listener_callback,
            10)
        self.subscription

    def listener_callback(self, msg):
            self.get_logger().info('I heard: "%d"' % msg.err)  # CHANGE


def main(args=None):
    rclpy.init(args=args)

    minimal_subscriber = CustomSubscriber()

    rclpy.spin(minimal_subscriber)

    minimal_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
