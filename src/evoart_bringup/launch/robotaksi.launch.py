import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node

def generate_launch_description():
    # Paket Dizinleri
    bringup_dir = get_package_share_directory('evoart_bringup')
    description_dir = get_package_share_directory('evoart_description')
    navigation_dir = get_package_share_directory('evoart_navigation')
    control_dir = get_package_share_directory('evoart_control') # YENİ EKLENDİ

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

    # 3. Sensör Füzyonunu (EKF) Başlat
    ekf_node = Node(
        package='robot_localization',
        executable='ekf_node',
        name='ekf_filter_node',
        output='screen',
        parameters=[os.path.join(navigation_dir, 'config', 'ekf.yaml'), {'use_sim_time': True}]
    )

    # 4. Nav2 (Otonom Navigasyon Sistemi) Başlatıcı
    navigation_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(navigation_dir, 'launch', 'navigation.launch.py')),
        launch_arguments={'use_sim_time': 'true'}.items()
    )

    # 5. micro-ROS Agent (STM32 Bağlantısı) - Gerçek araçta kullanılır
    microros_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(bringup_dir, 'launch', 'microros.launch.py'))
    )

    # 6. YENİ: Hız Komutunu Direksiyon Açısına Çeviren Düğüm
    control_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(control_dir, 'launch', 'control.launch.py'))
    )

    return LaunchDescription([
        gazebo_launch,
        rviz_node,
        ekf_node,
        navigation_launch,
        #microros_launch,
        control_launch
    ])
