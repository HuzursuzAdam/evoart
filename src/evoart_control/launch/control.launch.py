import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    # YAML dosyasının yerini buluyoruz
    config = os.path.join(
        get_package_share_directory('evoart_control'),
        'config',
        'control_params.yaml'
    )

    # Düğümü parametreleriyle birlikte oluşturuyoruz
    cmd_vel_node = Node(
        package='evoart_control',
        executable='cmd_vel_to_ackermann',
        name='cmd_vel_to_ackermann_node',
        output='screen',
        parameters=[config]
    )
    
    stm32_odom_node = Node(
    package='evoart_control',
    executable='stm32_odom_node',
    name='stm32_odom_node',
    output='screen',
    parameters=[
        {'serial_port': '/dev/ttyUSB0'},
        {'baud_rate': 115200},
        {'wheel_radius': 0.15} # Örnek tekerlek yarıçapı (metre)
    ]
    
    )

    return LaunchDescription([
        cmd_vel_node,
        stm32_odom_node
    ])
