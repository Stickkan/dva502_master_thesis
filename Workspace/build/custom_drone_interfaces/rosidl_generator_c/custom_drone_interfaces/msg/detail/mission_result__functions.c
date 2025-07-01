// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_drone_interfaces:msg/MissionResult.idl
// generated code does not contain a copyright notice
#include "custom_drone_interfaces/msg/detail/mission_result__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `result_message`
#include "rosidl_runtime_c/string_functions.h"

bool
custom_drone_interfaces__msg__MissionResult__init(custom_drone_interfaces__msg__MissionResult * msg)
{
  if (!msg) {
    return false;
  }
  // result_message
  if (!rosidl_runtime_c__String__init(&msg->result_message)) {
    custom_drone_interfaces__msg__MissionResult__fini(msg);
    return false;
  }
  return true;
}

void
custom_drone_interfaces__msg__MissionResult__fini(custom_drone_interfaces__msg__MissionResult * msg)
{
  if (!msg) {
    return;
  }
  // result_message
  rosidl_runtime_c__String__fini(&msg->result_message);
}

bool
custom_drone_interfaces__msg__MissionResult__are_equal(const custom_drone_interfaces__msg__MissionResult * lhs, const custom_drone_interfaces__msg__MissionResult * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result_message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->result_message), &(rhs->result_message)))
  {
    return false;
  }
  return true;
}

bool
custom_drone_interfaces__msg__MissionResult__copy(
  const custom_drone_interfaces__msg__MissionResult * input,
  custom_drone_interfaces__msg__MissionResult * output)
{
  if (!input || !output) {
    return false;
  }
  // result_message
  if (!rosidl_runtime_c__String__copy(
      &(input->result_message), &(output->result_message)))
  {
    return false;
  }
  return true;
}

custom_drone_interfaces__msg__MissionResult *
custom_drone_interfaces__msg__MissionResult__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__MissionResult * msg = (custom_drone_interfaces__msg__MissionResult *)allocator.allocate(sizeof(custom_drone_interfaces__msg__MissionResult), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_drone_interfaces__msg__MissionResult));
  bool success = custom_drone_interfaces__msg__MissionResult__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_drone_interfaces__msg__MissionResult__destroy(custom_drone_interfaces__msg__MissionResult * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_drone_interfaces__msg__MissionResult__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_drone_interfaces__msg__MissionResult__Sequence__init(custom_drone_interfaces__msg__MissionResult__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__MissionResult * data = NULL;

  if (size) {
    data = (custom_drone_interfaces__msg__MissionResult *)allocator.zero_allocate(size, sizeof(custom_drone_interfaces__msg__MissionResult), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_drone_interfaces__msg__MissionResult__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_drone_interfaces__msg__MissionResult__fini(&data[i - 1]);
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
custom_drone_interfaces__msg__MissionResult__Sequence__fini(custom_drone_interfaces__msg__MissionResult__Sequence * array)
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
      custom_drone_interfaces__msg__MissionResult__fini(&array->data[i]);
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

custom_drone_interfaces__msg__MissionResult__Sequence *
custom_drone_interfaces__msg__MissionResult__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__MissionResult__Sequence * array = (custom_drone_interfaces__msg__MissionResult__Sequence *)allocator.allocate(sizeof(custom_drone_interfaces__msg__MissionResult__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_drone_interfaces__msg__MissionResult__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_drone_interfaces__msg__MissionResult__Sequence__destroy(custom_drone_interfaces__msg__MissionResult__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_drone_interfaces__msg__MissionResult__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_drone_interfaces__msg__MissionResult__Sequence__are_equal(const custom_drone_interfaces__msg__MissionResult__Sequence * lhs, const custom_drone_interfaces__msg__MissionResult__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_drone_interfaces__msg__MissionResult__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_drone_interfaces__msg__MissionResult__Sequence__copy(
  const custom_drone_interfaces__msg__MissionResult__Sequence * input,
  custom_drone_interfaces__msg__MissionResult__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_drone_interfaces__msg__MissionResult);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_drone_interfaces__msg__MissionResult * data =
      (custom_drone_interfaces__msg__MissionResult *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_drone_interfaces__msg__MissionResult__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_drone_interfaces__msg__MissionResult__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_drone_interfaces__msg__MissionResult__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
