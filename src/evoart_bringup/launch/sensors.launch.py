import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node

def generate_launch_description():
    zed_wrapper_share = get_package_share_directory('zed_wrapper')
    velodyne_share = get_package_share_directory('velodyne') # velodyne_driver yerine ana paketi alıyoruz

    # 1. ZED 2i Kamera Sürücüsü
    zed_camera = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(zed_wrapper_share, 'launch', 'zed_camera.launch.py')
        ),
        launch_arguments={'camera_model': 'zed2i'}.items()
    )

    # 2. Velodyne VLP-16 LiDAR (Sürücü + 3D PointCloud Dönüştürücüsü Birlikte)
    velodyne_driver = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(velodyne_share, 'launch', 'velodyne-all-nodes-VLP16-launch.py')
        )
    )

    # 3. VELODYNE 3D POINTCLOUD -> 2D LASERSCAN ÇEVİRİCİ
    pointcloud_to_laserscan = Node(
        package='pointcloud_to_laserscan',
        executable='pointcloud_to_laserscan_node',
        name='pointcloud_to_laserscan',
        remappings=[
            ('cloud_in', '/velodyne_points'),
            ('scan', '/scan')
        ],
        parameters=[{
            'target_frame': 'velodyne',
            'transform_tolerance': 0.01,
            'min_height': -0.4,
            'max_height': 1.0,
            'angle_min': -3.14159,
            'angle_max': 3.14159,
            'angle_increment': 0.0087,
            'scan_time': 0.1,
            'range_min': 0.2,
            'range_max': 100.0,
            'use_inf': True
        }]
    )

    return LaunchDescription([
        zed_camera,
        velodyne_driver,
        pointcloud_to_laserscan
    ])
