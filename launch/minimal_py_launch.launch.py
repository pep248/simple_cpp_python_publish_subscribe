#!/usr/bin/env python3

import sys
from launch import LaunchService

from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():

        return LaunchDescription([
                # publisher_node
                Node(
                        package='simple_cpp_python_publish_subscribe',
                        executable='publisher.py',
                        output='screen',
                        name='publisher_py_node',
                ),
                # subscriber_node
                Node(
                        package='simple_cpp_python_publish_subscribe',
                        executable='subscriber.py',
                        output='screen',
                        name='subscriber_py_node',
                ),
        ])
        

if __name__ == '__main__':
    desc = generate_launch_description()
    service = LaunchService(argv=sys.argv[1:])
    service.include_launch_description(desc)
    service.run()        