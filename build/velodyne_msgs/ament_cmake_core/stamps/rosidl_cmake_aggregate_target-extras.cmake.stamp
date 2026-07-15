# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target velodyne_msgs::velodyne_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${velodyne_msgs_TARGETS}.
if(velodyne_msgs_TARGETS AND NOT TARGET velodyne_msgs::velodyne_msgs)
  add_library(velodyne_msgs::velodyne_msgs INTERFACE IMPORTED)
  set_target_properties(velodyne_msgs::velodyne_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${velodyne_msgs_TARGETS}")
endif()
