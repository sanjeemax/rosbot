from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
   return LaunchDescription([
    Node(
    package='py_2wbot_ctrl',
    executable='follower',
    name='sim'
)
   ])