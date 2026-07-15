# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_evoart_behavior_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED evoart_behavior_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(evoart_behavior_FOUND FALSE)
  elseif(NOT evoart_behavior_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(evoart_behavior_FOUND FALSE)
  endif()
  return()
endif()
set(_evoart_behavior_CONFIG_INCLUDED TRUE)

# output package information
if(NOT evoart_behavior_FIND_QUIETLY)
  message(STATUS "Found evoart_behavior: 0.0.0 (${evoart_behavior_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'evoart_behavior' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${evoart_behavior_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(evoart_behavior_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${evoart_behavior_DIR}/${_extra}")
endforeach()
