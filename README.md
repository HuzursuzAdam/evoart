# EVOART-O Autonomous Vehicle System (`evoart_ws`)

**EVOART-O** is an end-to-end autonomous vehicle software stack built on **ROS 2 (Jazzy/Humble)** and **Gazebo (Ignition / `ros_gz`)**. Designed specifically for autonomous track driving, urban navigation, and robotics competitions (such as RoboTaksi / Teknofest), this repository integrates 3D simulation, multi-sensor localization (EKF), Ackermann steering kinematics, path planning (Nav2), perception, and behavior decision trees into a modular architecture.

---

## 🏗️ System Architecture & Packages

The workspace is organized into functional ROS 2 packages located inside `src/`:

| Package Name | Description |
| :--- | :--- |
| **`evoart_bringup`** | **Core Orchestrator**: Contains the master launch files (`robotaksi.launch.py`) that coordinate simulation, visualization (RViz2), sensor fusion (EKF), navigation, and control. |
| **`evoart_description`** | **Robot & World Descriptions**: Contains the vehicle URDF/Xacro (`robotaksi.urdf.xacro`), 3D meshes, RViz configurations (`robotaksi.rviz`), track environments (`robotaksi_pist_2024.sdf`, `teknofest_city.sdf`), and custom traffic signage models. |
| **`evoart_navigation`** | **Autonomous Navigation & Fusion**: Contains Nav2 configurations (`nav2_params.yaml`), global/local planners (`DWBLocalPlanner`, `NavfnPlanner`), behavior trees, and `robot_localization` EKF settings (`ekf.yaml`). |
| **`evoart_control`** | **Vehicle Kinematics & Control**: Converts standard ROS velocity commands (`/cmd_vel`) into Ackermann steering geometry (`cmd_vel_to_ackermann`). |
| **`evoart_perception`** | **Computer Vision & Detection**: Contains deep-learning and OpenCV pipelines for lane detection (`lane_detector.py`) and traffic sign/object detection (`object_detector.py`). |
| **`evoart_behavior`** | **Decision Making**: Implements state machines and behavior trees (`behaviortree_cpp`) for intersection handling, stop signs, and obstacle avoidance. |
| **`evoart_interfaces`** | **Custom Interfaces**: Project-specific ROS 2 messages, services, and action definitions. |
| **`velodyne`** | **LiDAR Hardware Drivers**: Drivers and pointcloud/laserscan converters for physical Velodyne VLP-16 LiDARs. |
| **`zed-ros2-wrapper`** | **Stereo Camera Drivers**: Drivers and wrapper nodes for physical Stereolabs ZED 2i stereo cameras. |

---

## 📋 Prerequisites & Requirements

- **Operating System**: Ubuntu 24.04 LTS (for ROS 2 Jazzy) or Ubuntu 22.04 LTS (for ROS 2 Humble)
- **ROS 2 Distribution**: `Jazzy Jalisco` (Default) or `Humble Hawksbill`
- **Simulation Engine**: Ignition Gazebo (`gz-sim` / `ros_gz_sim` & `ros_gz_bridge`)
- **Python Virtual Environment**: Python 3.12+ with a dedicated virtual environment (`.venv`) for machine learning and CV dependencies (`ultralytics`, `opencv-python`, `pyserial`)

---

## ⚙️ Installation & Build Setup

### 1. Source ROS 2 & Activate Virtual Environment
Before compiling or running any launch files, always source your ROS 2 environment and activate the project virtual environment:

```bash
# Source ROS 2 Jazzy (or change to /opt/ros/humble/setup.bash if using Humble)
source /opt/ros/jazzy/setup.bash

# Activate local Python virtual environment
source /home/leykun/EVOART-O/.venv/bin/activate
```

### 2. Build the Workspace
Compile the core simulation and navigation stack using `colcon`:

```bash
cd "/home/leykun/Documents/EVOART-O /evoart_ws"

# Build simulation packages with symlink install for rapid iteration
colcon build --symlink-install --packages-select evoart_interfaces evoart_description evoart_control evoart_navigation evoart_bringup

# Source the generated workspace setup
source install/setup.bash
```

> [!NOTE]
> Hardware driver packages (`zed_wrapper`, `velodyne_driver`) depend on physical device SDKs (e.g., Stereolabs ZED SDK or `libpcap-dev`) and are bypassed during simulation builds.

---

## 🚀 Running the Simulation (Gazebo + RViz2)

The master simulation pipeline launches **Gazebo** (Ignition), **RViz2**, the **EKF Sensor Fusion** node (`ekf_node`), the **Nav2 Autonomous Navigation Stack**, and the **Ackermann Steering Controller** simultaneously using simulation time (`use_sim_time: True` and `/clock`).

### 1. Launch Master Orchestrator
```bash
cd "/home/leykun/Documents/EVOART-O /evoart_ws"
source /opt/ros/jazzy/setup.bash
source /home/leykun/EVOART-O/.venv/bin/activate
source install/setup.bash

ros2 launch evoart_bringup robotaksi.launch.py
```

### 2. What Happens on Launch
- **Gazebo Track (`robotaksi_pist_2024.sdf`)**: Opens the 2024 RoboTaksi competition track equipped with custom 3D road signage (`DurakTabelasi`, `DonelKavsakTabelasi`, `ParkYeriTabelasi`, etc.) and traffic lights.
- **Vehicle Spawn**: Spawns the `evoart_robotaksi` Ackermann vehicle at `z=0.5m` origin.
- **ROS 2 Topic Bridge (`ros_gz_bridge`)**: Automatically bridges Ignition Gazebo simulation topics to standard ROS 2 topics:
  - `/clock` ↔ `rosgraph_msgs/msg/Clock`
  - `/cmd_vel` ↔ `geometry_msgs/msg/Twist`
  - `/odom` ↔ `nav_msgs/msg/Odometry`
  - `/scan` ↔ `sensor_msgs/msg/LaserScan`
  - `/joint_states` ↔ `sensor_msgs/msg/JointState`
  - `/tf` ↔ `tf2_msgs/msg/TFMessage`
- **RViz2 Visualizer**: Opens pre-configured with `robotaksi.rviz`, displaying real-time TF transformations (`base_link`, `lidar_link`, `zed_camera_link`), odometry arrows, and 2D/3D sensor pointclouds.
- **Autonomous Navigation (Nav2)**: Initializes `planner_server` and `controller_server` with `DWBLocalPlanner` and `NavfnPlanner`, ready to accept navigation goal poses (`2D Goal Pose` in RViz).

---

## 🗺️ Simulation Environments

You can easily switch the default Gazebo world in `evoart_description/launch/gazebo.launch.py`:

1. **`robotaksi_pist_2024.sdf`** *(Default)*: Full RoboTaksi race track with realistic road layouts, mandatory turn signs, speed limits, and traffic light intersections.
2. **`teknofest_city.sdf`**: Urban city environment for wide-area testing.

All required 3D models are located inside `evoart_description/models/` and are automatically exported via `GZ_SIM_RESOURCE_PATH` and `IGN_GAZEBO_RESOURCE_PATH`.

---

## 📡 Key ROS 2 Topics

| Topic | Type | Description |
| :--- | :--- | :--- |
| `/clock` | `rosgraph_msgs/msg/Clock` | Synchronized simulation clock from Gazebo (`use_sim_time: True`) |
| `/cmd_vel` | `geometry_msgs/msg/Twist` | Target linear and angular velocity commands issued by Nav2 or teleop |
| `/odom` | `nav_msgs/msg/Odometry` | Raw wheel odometry published by Ignition Gazebo Ackermann plugin |
| `/odometry/filtered` | `nav_msgs/msg/Odometry` | Filtered state estimation fused from wheel odometry and IMU via `ekf_node` |
| `/scan` | `sensor_msgs/msg/LaserScan` | 360° 2D laser scan generated from simulated Velodyne VLP-16 GPU LiDAR |
| `/zed/zed_node/rgb/image_rect_color` | `sensor_msgs/msg/Image` | Rectified RGB camera feed from simulated ZED 2i camera |
| `/joint_states` | `sensor_msgs/msg/JointState` | Real-time steering and wheel rotation angles |
| `/tf` & `/tf_static` | `tf2_msgs/msg/TFMessage` | Complete kinematic transformation tree (`odom` → `base_footprint` → `base_link` → sensors) |

---

## 🛠️ Troubleshooting & Tips

- **Spaces in Directory Paths**: The workspace launch files utilize robust Python XML/Xacro parsing (`xacro.process_file(...).toxml()`) and quoted `gz_args`. If moving the repository, directory paths containing spaces (`EVOART-O /evoart_ws`) are fully supported.
- **Nav2 Plugin Syntax**: Configured to use ROS 2 Jazzy double colon namespace syntax (`::`) inside `nav2_params.yaml` (`nav2_navfn_planner::NavfnPlanner` and `nav2_behaviors::Spin`).
- **TF / Time Jumps**: When restarting Gazebo simulation, you may see `Detected jump back in time. Clearing TF buffer` warnings in terminal. This is normal behavior when `/clock` resets to `0.0s`.
# evoart
