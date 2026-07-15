import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, SetEnvironmentVariable
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
import xacro

def generate_launch_description():
    description_pkg = get_package_share_directory('evoart_description')
    
    # Dosya yolları
    world_file = os.path.join(description_pkg, 'worlds', 'teknofest_city.sdf')
    xacro_file = os.path.join(description_pkg, 'urdf', 'robotaksi.urdf.xacro')

    models_dir = os.path.join(description_pkg, 'models')
    worlds_dir = os.path.join(description_pkg, 'worlds')
    gz_resource_path = f"{models_dir}:{worlds_dir}:{os.path.expanduser('~/.gz/models')}"

    set_gz_resource_path = SetEnvironmentVariable('GZ_SIM_RESOURCE_PATH', gz_resource_path)
    set_ign_resource_path = SetEnvironmentVariable('IGN_GAZEBO_RESOURCE_PATH', gz_resource_path)

    # Ignition Gazebo'yu başlat
    ros_gz_sim_pkg = get_package_share_directory('ros_gz_sim')
    gz_sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(ros_gz_sim_pkg, 'launch', 'gz_sim.launch.py')
        ),
        launch_arguments={'gz_args': f'-r "{world_file}"'}.items(),
    )

    # Xacro dosyasını parse et
    robot_description_config = xacro.process_file(xacro_file)
    robot_desc = robot_description_config.toxml()

    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='both',
        parameters=[{
            'robot_description': robot_desc,
            'use_sim_time': True
        }],
    )

    # Aracı Gazebo dünyasına indir (Spawn)
    spawn_entity = Node(
        package='ros_gz_sim',
        executable='create',
        arguments=[
            '-topic', 'robot_description', 
            '-name', 'evoart_robotaksi',   
            '-z', '0.5'                    
        ],
        output='screen'
    )

    # ROS 2 - Gazebo Köprüsü (Bridge)
    # Ignition Fortress Ackermann plugin /tf topic'ini Pose_V olarak yayınlar
    # Ayrıca model altındaki tf topic'ini de köprüleyelim
    bridge_node = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=[
            '/clock@rosgraph_msgs/msg/Clock[ignition.msgs.Clock',
            '/cmd_vel@geometry_msgs/msg/Twist@ignition.msgs.Twist',
            '/odom@nav_msgs/msg/Odometry[ignition.msgs.Odometry',
            '/scan@sensor_msgs/msg/LaserScan[ignition.msgs.LaserScan',
            '/joint_states@sensor_msgs/msg/JointState[ignition.msgs.Model',
            '/tf@tf2_msgs/msg/TFMessage[ignition.msgs.Pose_V',
            # Ackermann plugin'in model-specific TF topic'i
            '/model/evoart_robotaksi/tf@tf2_msgs/msg/TFMessage[ignition.msgs.Pose_V',
        ],
        parameters=[{'use_sim_time': True}],
        remappings=[
            ('/model/evoart_robotaksi/tf', '/tf'),
        ],
        output='screen'
    )

    return LaunchDescription([
        set_gz_resource_path,
        set_ign_resource_path,
        gz_sim,
        robot_state_publisher,
        spawn_entity,
        bridge_node
    ])
