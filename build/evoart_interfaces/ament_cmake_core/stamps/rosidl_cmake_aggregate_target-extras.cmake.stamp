# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target evoart_interfaces::evoart_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${evoart_interfaces_TARGETS}.
if(evoart_interfaces_TARGETS AND NOT TARGET evoart_interfaces::evoart_interfaces)
  add_library(evoart_interfaces::evoart_interfaces INTERFACE IMPORTED)
  set_target_properties(evoart_interfaces::evoart_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${evoart_interfaces_TARGETS}")
endif()
