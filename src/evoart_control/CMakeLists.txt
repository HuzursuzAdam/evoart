cmake_minimum_required(VERSION 3.8)
project(evoart_control)
# Derleyiciye, eski C++ sürümleriyle uyum için bu kısıtlamaları esnetmesini söylüyoruz
add_compile_definitions(_GLIBCXX_USE_CXX11_ABI=1)
add_compile_options(-Wno-error=ignored-attributes)
# C++17 Standardını KESİN OLARAK zorunlu kılıyoruz
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Derleyici uyarı ayarları (Eksik olan endif buradaydı)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Bağımlılıklar
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(evoart_interfaces REQUIRED)
find_package(nav_msgs REQUIRED)



include_directories(include)

# C++ Düğümünü derle
add_executable(cmd_vel_to_ackermann src/cmd_vel_to_ackermann.cpp)
ament_target_dependencies(cmd_vel_to_ackermann rclcpp geometry_msgs evoart_interfaces)
target_compile_features(cmd_vel_to_ackermann PUBLIC cxx_std_17)
add_executable(stm32_odom_node src/stm32_odom_node.cpp)
ament_target_dependencies(stm32_odom_node
  rclcpp
  nav_msgs
  geometry_msgs
)

# Kurulum Yolları
install(TARGETS 
cmd_vel_to_ackermann
stm32_odom_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  config
  launch
  DESTINATION share/${PROJECT_NAME}
)
ament_target_dependencies(cmd_vel_to_ackermann
  rclcpp
  geometry_msgs
  evoart_interfaces # BURA EKLENECEK
)
ament_target_dependencies(stm32_odom_node
  rclcpp
  nav_msgs
  evoart_interfaces # BURA EKLENECEK
)

# Executable'ı kur (install kısmına manual_commander'ı ekle)
install(TARGETS
  cmd_vel_to_ackermann
  stm32_odom_node
  DESTINATION lib/${PROJECT_NAME}
)
install(PROGRAMS
  scripts/manual_commander.py
  scripts/global_teleop.py
  DESTINATION lib/${PROJECT_NAME}
)
# Launch klasörünü sisteme kur
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()

