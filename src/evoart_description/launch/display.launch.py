import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
import xacro

def generate_launch_description():
    pkg_name = 'evoart_description'
    
    # Xacro dosyasının yolunu bul
    xacro_file = os.path.join(get_package_share_directory(pkg_name), 'urdf', 'robotaksi.urdf.xacro')
    
    # Xacro dosyasını Python içinde parse ederek standart XML/URDF'e çevir
    robot_description_config = xacro.process_file(xacro_file)
    robot_desc = robot_description_config.toxml()

    # Robot State Publisher Düğümü (TF yayınlar)
    rsp_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[{'robot_description': robot_desc}]
    )

    # Joint State Publisher Düğümü (Hareketli eklemleri -tekerlek vb- yönetir)
    jsp_node = Node(
        package='joint_state_publisher',
        executable='joint_state_publisher',
        name='joint_state_publisher'
    )

    return LaunchDescription([
        rsp_node,
        jsp_node
    ])
