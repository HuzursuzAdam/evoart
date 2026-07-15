from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    # STM32 ile haberleşecek micro-ROS Ajanı
    microros_agent_node = Node(
        package='micro_ros_agent',
        executable='micro_ros_agent',
        name='micro_ros_agent',
        output='screen',
        # Eğer STM32'yi farklı bir porta (örn: ttyUSB0) takarsanız burayı değiştirin
        arguments=['serial', '--dev', '/dev/ttyACM0', '-b', '115200']
    )

    return LaunchDescription([
        microros_agent_node
    ])
