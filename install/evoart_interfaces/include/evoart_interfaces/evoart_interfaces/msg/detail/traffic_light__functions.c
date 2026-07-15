// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from evoart_interfaces:msg/TrafficLight.idl
// generated code does not contain a copyright notice
#include "evoart_interfaces/msg/detail/traffic_light__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
evoart_interfaces__msg__TrafficLight__init(evoart_interfaces__msg__TrafficLight * msg)
{
  if (!msg) {
    return false;
  }
  // color
  // confidence
  return true;
}

void
evoart_interfaces__msg__TrafficLight__fini(evoart_interfaces__msg__TrafficLight * msg)
{
  if (!msg) {
    return;
  }
  // color
  // confidence
}

bool
evoart_interfaces__msg__TrafficLight__are_equal(const evoart_interfaces__msg__TrafficLight * lhs, const evoart_interfaces__msg__TrafficLight * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // color
  if (lhs->color != rhs->color) {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  return true;
}

bool
evoart_interfaces__msg__TrafficLight__copy(
  const evoart_interfaces__msg__TrafficLight * input,
  evoart_interfaces__msg__TrafficLight * output)
{
  if (!input || !output) {
    return false;
  }
  // color
  output->color = input->color;
  // confidence
  output->confidence = input->confidence;
  return true;
}

evoart_interfaces__msg__TrafficLight *
evoart_interfaces__msg__TrafficLight__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  evoart_interfaces__msg__TrafficLight * msg = (evoart_interfaces__msg__TrafficLight *)allocator.allocate(sizeof(evoart_interfaces__msg__TrafficLight), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(evoart_interfaces__msg__TrafficLight));
  bool success = evoart_interfaces__msg__TrafficLight__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
evoart_interfaces__msg__TrafficLight__destroy(evoart_interfaces__msg__TrafficLight * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    evoart_interfaces__msg__TrafficLight__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
evoart_interfaces__msg__TrafficLight__Sequence__init(evoart_interfaces__msg__TrafficLight__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  evoart_interfaces__msg__TrafficLight * data = NULL;

  if (size) {
    data = (evoart_interfaces__msg__TrafficLight *)allocator.zero_allocate(size, sizeof(evoart_interfaces__msg__TrafficLight), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = evoart_interfaces__msg__TrafficLight__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        evoart_interfaces__msg__TrafficLight__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
evoart_interfaces__msg__TrafficLight__Sequence__fini(evoart_interfaces__msg__TrafficLight__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      evoart_interfaces__msg__TrafficLight__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

evoart_interfaces__msg__TrafficLight__Sequence *
evoart_interfaces__msg__TrafficLight__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  evoart_interfaces__msg__TrafficLight__Sequence * array = (evoart_interfaces__msg__TrafficLight__Sequence *)allocator.allocate(sizeof(evoart_interfaces__msg__TrafficLight__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = evoart_interfaces__msg__TrafficLight__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
evoart_interfaces__msg__TrafficLight__Sequence__destroy(evoart_interfaces__msg__TrafficLight__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    evoart_interfaces__msg__TrafficLight__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
evoart_interfaces__msg__TrafficLight__Sequence__are_equal(const evoart_interfaces__msg__TrafficLight__Sequence * lhs, const evoart_interfaces__msg__TrafficLight__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!evoart_interfaces__msg__TrafficLight__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
evoart_interfaces__msg__TrafficLight__Sequence__copy(
  const evoart_interfaces__msg__TrafficLight__Sequence * input,
  evoart_interfaces__msg__TrafficLight__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(evoart_interfaces__msg__TrafficLight);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    evoart_interfaces__msg__TrafficLight * data =
      (evoart_interfaces__msg__TrafficLight *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!evoart_interfaces__msg__TrafficLight__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          evoart_interfaces__msg__TrafficLight__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!evoart_interfaces__msg__TrafficLight__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
