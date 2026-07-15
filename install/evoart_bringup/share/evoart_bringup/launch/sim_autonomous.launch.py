import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node

def generate_launch_description():
    # Paket Dizinleri
    description_dir = get_package_share_directory('evoart_description')
    navigation_dir = get_package_share_directory('evoart_navigation')

    # 1. Gazebo Simülasyonu ve Robot Modelini Ayağa Kaldır
    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(description_dir, 'launch', 'gazebo.launch.py'))
    )

    # 2. RViz2 Görselleştirme Ekranı
    rviz_config_file = os.path.join(description_dir, 'rviz', 'robotaksi.rviz')
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', rviz_config_file],
        parameters=[{'use_sim_time': True}]
    )

    # 3. Nav2 (Otonom Navigasyon Sistemi) - Gazebo ayağa kalktıktan sonra başlat
    navigation_launch = TimerAction(
        period=8.0,  # Gazebo'nun tam olarak ayağa kalkması için 8 saniye bekle
        actions=[
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(os.path.join(navigation_dir, 'launch', 'navigation.launch.py')),
                launch_arguments={'use_sim_time': 'true'}.items()
            )
        ]
    )

    return LaunchDescription([
        gazebo_launch,
        rviz_node,
        navigation_launch,
    ])
