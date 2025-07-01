// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_drone_interfaces:msg/MissionGoal.idl
// generated code does not contain a copyright notice
#include "custom_drone_interfaces/msg/detail/mission_goal__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `json_mission_data`
#include "rosidl_runtime_c/string_functions.h"

bool
custom_drone_interfaces__msg__MissionGoal__init(custom_drone_interfaces__msg__MissionGoal * msg)
{
  if (!msg) {
    return false;
  }
  // json_mission_data
  if (!rosidl_runtime_c__String__init(&msg->json_mission_data)) {
    custom_drone_interfaces__msg__MissionGoal__fini(msg);
    return false;
  }
  return true;
}

void
custom_drone_interfaces__msg__MissionGoal__fini(custom_drone_interfaces__msg__MissionGoal * msg)
{
  if (!msg) {
    return;
  }
  // json_mission_data
  rosidl_runtime_c__String__fini(&msg->json_mission_data);
}

bool
custom_drone_interfaces__msg__MissionGoal__are_equal(const custom_drone_interfaces__msg__MissionGoal * lhs, const custom_drone_interfaces__msg__MissionGoal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // json_mission_data
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->json_mission_data), &(rhs->json_mission_data)))
  {
    return false;
  }
  return true;
}

bool
custom_drone_interfaces__msg__MissionGoal__copy(
  const custom_drone_interfaces__msg__MissionGoal * input,
  custom_drone_interfaces__msg__MissionGoal * output)
{
  if (!input || !output) {
    return false;
  }
  // json_mission_data
  if (!rosidl_runtime_c__String__copy(
      &(input->json_mission_data), &(output->json_mission_data)))
  {
    return false;
  }
  return true;
}

custom_drone_interfaces__msg__MissionGoal *
custom_drone_interfaces__msg__MissionGoal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__MissionGoal * msg = (custom_drone_interfaces__msg__MissionGoal *)allocator.allocate(sizeof(custom_drone_interfaces__msg__MissionGoal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_drone_interfaces__msg__MissionGoal));
  bool success = custom_drone_interfaces__msg__MissionGoal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_drone_interfaces__msg__MissionGoal__destroy(custom_drone_interfaces__msg__MissionGoal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_drone_interfaces__msg__MissionGoal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_drone_interfaces__msg__MissionGoal__Sequence__init(custom_drone_interfaces__msg__MissionGoal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__MissionGoal * data = NULL;

  if (size) {
    data = (custom_drone_interfaces__msg__MissionGoal *)allocator.zero_allocate(size, sizeof(custom_drone_interfaces__msg__MissionGoal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_drone_interfaces__msg__MissionGoal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_drone_interfaces__msg__MissionGoal__fini(&data[i - 1]);
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
custom_drone_interfaces__msg__MissionGoal__Sequence__fini(custom_drone_interfaces__msg__MissionGoal__Sequence * array)
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
      custom_drone_interfaces__msg__MissionGoal__fini(&array->data[i]);
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

custom_drone_interfaces__msg__MissionGoal__Sequence *
custom_drone_interfaces__msg__MissionGoal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__MissionGoal__Sequence * array = (custom_drone_interfaces__msg__MissionGoal__Sequence *)allocator.allocate(sizeof(custom_drone_interfaces__msg__MissionGoal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_drone_interfaces__msg__MissionGoal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_drone_interfaces__msg__MissionGoal__Sequence__destroy(custom_drone_interfaces__msg__MissionGoal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_drone_interfaces__msg__MissionGoal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_drone_interfaces__msg__MissionGoal__Sequence__are_equal(const custom_drone_interfaces__msg__MissionGoal__Sequence * lhs, const custom_drone_interfaces__msg__MissionGoal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_drone_interfaces__msg__MissionGoal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_drone_interfaces__msg__MissionGoal__Sequence__copy(
  const custom_drone_interfaces__msg__MissionGoal__Sequence * input,
  custom_drone_interfaces__msg__MissionGoal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_drone_interfaces__msg__MissionGoal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_drone_interfaces__msg__MissionGoal * data =
      (custom_drone_interfaces__msg__MissionGoal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_drone_interfaces__msg__MissionGoal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_drone_interfaces__msg__MissionGoal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_drone_interfaces__msg__MissionGoal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
