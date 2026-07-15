cmake_minimum_required(VERSION 3.8)
project(evoart_behavior)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Bağımlılıkları Bul
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(behaviortree_cpp_v3 REQUIRED)
find_package(nav2_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(evoart_interfaces REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)

# Include dizinini belirt
include_directories(include)

# Ana motoru ve yazdığımız özel düğümleri derle
add_executable(bt_engine 
  src/bt_engine.cpp
  src/navigate_to_pose_action.cpp
  src/check_traffic_light_condition.cpp
)

# Derlenen motorun ROS 2 paketlerine olan bağımlılıklarını belirt
ament_target_dependencies(bt_engine 
  rclcpp 
  behaviortree_cpp_v3 
  nav2_msgs 
  geometry_msgs 
  evoart_interfaces
  tf2
  tf2_geometry_msgs
)

# Çalıştırılabilir dosyayı kur
install(TARGETS bt_engine
  DESTINATION lib/${PROJECT_NAME}
)

# XML ve Launch klasörlerini paylaşım dizinine kopyala
install(DIRECTORY
  bt_xml
  launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
