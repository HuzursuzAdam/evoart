cmake_minimum_required(VERSION 3.8)
project(evoart_perception)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Bağımlılıkları Bul
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclpy REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(evoart_interfaces REQUIRED)

# 1. Python scriptlerini çalıştırılabilir olarak (ros2 run için) kur
install(PROGRAMS
  scripts/lane_detector.py
  scripts/object_detector.py
  DESTINATION lib/${PROJECT_NAME}
)

# 2. Config ve Models klasörlerini (paylaşım dizinine) kopyala
install(DIRECTORY
  config
  models
  DESTINATION share/${PROJECT_NAME}
)
ament_package()
