cmake_minimum_required(VERSION 3.8)
project(evoart_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Bağımlılıkları bul
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Üretilecek tüm arayüz dosyalarını listele
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Obstacle.msg"
  "msg/TrafficLight.msg"
  "msg/VehicleControl.msg"
  "srv/StartPark.srv"
)

ament_package()
