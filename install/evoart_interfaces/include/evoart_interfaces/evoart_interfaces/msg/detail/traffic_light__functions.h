// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from evoart_interfaces:msg/TrafficLight.idl
// generated code does not contain a copyright notice

#ifndef EVOART_INTERFACES__MSG__DETAIL__TRAFFIC_LIGHT__FUNCTIONS_H_
#define EVOART_INTERFACES__MSG__DETAIL__TRAFFIC_LIGHT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "evoart_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "evoart_interfaces/msg/detail/traffic_light__struct.h"

/// Initialize msg/TrafficLight message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * evoart_interfaces__msg__TrafficLight
 * )) before or use
 * evoart_interfaces__msg__TrafficLight__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_evoart_interfaces
bool
evoart_interfaces__msg__TrafficLight__init(evoart_interfaces__msg__TrafficLight * msg);

/// Finalize msg/TrafficLight message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_evoart_interfaces
void
evoart_interfaces__msg__TrafficLight__fini(evoart_interfaces__msg__TrafficLight * msg);

/// Create msg/TrafficLight message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * evoart_interfaces__msg__TrafficLight__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_evoart_interfaces
evoart_interfaces__msg__TrafficLight *
evoart_interfaces__msg__TrafficLight__create();

/// Destroy msg/TrafficLight message.
/**
 * It calls
 * evoart_interfaces__msg__TrafficLight__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_evoart_interfaces
void
evoart_interfaces__msg__TrafficLight__destroy(evoart_interfaces__msg__TrafficLight * msg);

/// Check for msg/TrafficLight message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_evoart_interfaces
bool
evoart_interfaces__msg__TrafficLight__are_equal(const evoart_interfaces__msg__TrafficLight * lhs, const evoart_interfaces__msg__TrafficLight * rhs);

/// Copy a msg/TrafficLight message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_evoart_interfaces
bool
evoart_interfaces__msg__TrafficLight__copy(
  const evoart_interfaces__msg__TrafficLight * input,
  evoart_interfaces__msg__TrafficLight * output);

/// Initialize array of msg/TrafficLight messages.
/**
 * It allocates the memory for the number of elements and calls
 * evoart_interfaces__msg__TrafficLight__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_evoart_interfaces
bool
evoart_interfaces__msg__TrafficLight__Sequence__init(evoart_interfaces__msg__TrafficLight__Sequence * array, size_t size);

/// Finalize array of msg/TrafficLight messages.
/**
 * It calls
 * evoart_interfaces__msg__TrafficLight__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_evoart_interfaces
void
evoart_interfaces__msg__TrafficLight__Sequence__fini(evoart_interfaces__msg__TrafficLight__Sequence * array);

/// Create array of msg/TrafficLight messages.
/**
 * It allocates the memory for the array and calls
 * evoart_interfaces__msg__TrafficLight__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_evoart_interfaces
evoart_interfaces__msg__TrafficLight__Sequence *
evoart_interfaces__msg__TrafficLight__Sequence__create(size_t size);

/// Destroy array of msg/TrafficLight messages.
/**
 * It calls
 * evoart_interfaces__msg__TrafficLight__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_evoart_interfaces
void
evoart_interfaces__msg__TrafficLight__Sequence__destroy(evoart_interfaces__msg__TrafficLight__Sequence * array);

/// Check for msg/TrafficLight message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_evoart_interfaces
bool
evoart_interfaces__msg__TrafficLight__Sequence__are_equal(const evoart_interfaces__msg__TrafficLight__Sequence * lhs, const evoart_interfaces__msg__TrafficLight__Sequence * rhs);

/// Copy an array of msg/TrafficLight messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_evoart_interfaces
bool
evoart_interfaces__msg__TrafficLight__Sequence__copy(
  const evoart_interfaces__msg__TrafficLight__Sequence * input,
  evoart_interfaces__msg__TrafficLight__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // EVOART_INTERFACES__MSG__DETAIL__TRAFFIC_LIGHT__FUNCTIONS_H_
