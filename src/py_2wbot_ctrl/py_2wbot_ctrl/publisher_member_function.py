# Copyright 2016 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from geometry_msgs.msg import Twist


class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('cntrl_publisher')
        self.publisher_ = self.create_publisher(Twist,'/demo/cmd_demo', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        move = Twist()
        move.linear.x = 0.8
        move.angular.z = 0.2
        self.publisher_.publish(move)
        self.get_logger().info('Publishing: ')
        self.i += 1


def main(args=None):
    rclpy.init(args=args)

    cntrl_publisher = MinimalPublisher()

    rclpy.spin(cntrl_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    cntrl_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
