import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    # Kendi paketimizin yollarını bul
    pkg_dir = get_package_share_directory('evoart_navigation')
    nav2_bringup_dir = get_package_share_directory('nav2_bringup')
    
    # Parametre ve harita yolları
    params_file = os.path.join(pkg_dir, 'config', 'nav2_params.yaml')
    map_file = os.path.join(pkg_dir, 'maps', 'robotaksi_pist.yaml')

    use_sim_time = LaunchConfiguration('use_sim_time', default='true')

    # Nav2 Bringup'ı kendi parametrelerimizle başlat
    nav2_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(nav2_bringup_dir, 'launch', 'bringup_launch.py')
        ),
        launch_arguments={
            'map': map_file,
            'params_file': params_file,
            'use_sim_time': use_sim_time
        }.items()
    )

    return LaunchDescription([
        nav2_launch
    ])
