// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_drone_interfaces:srv/ComputePath.idl
// generated code does not contain a copyright notice
#include "custom_drone_interfaces/srv/detail/compute_path__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `input_path`
#include "custom_drone_interfaces/msg/detail/path3_d__functions.h"
// Member `planning_method`
#include "rosidl_runtime_c/string_functions.h"

bool
custom_drone_interfaces__srv__ComputePath_Request__init(custom_drone_interfaces__srv__ComputePath_Request * msg)
{
  if (!msg) {
    return false;
  }
  // input_path
  if (!custom_drone_interfaces__msg__Path3D__init(&msg->input_path)) {
    custom_drone_interfaces__srv__ComputePath_Request__fini(msg);
    return false;
  }
  // velocity_limit
  // acceleration_limit
  // planning_method
  if (!rosidl_runtime_c__String__init(&msg->planning_method)) {
    custom_drone_interfaces__srv__ComputePath_Request__fini(msg);
    return false;
  }
  return true;
}

void
custom_drone_interfaces__srv__ComputePath_Request__fini(custom_drone_interfaces__srv__ComputePath_Request * msg)
{
  if (!msg) {
    return;
  }
  // input_path
  custom_drone_interfaces__msg__Path3D__fini(&msg->input_path);
  // velocity_limit
  // acceleration_limit
  // planning_method
  rosidl_runtime_c__String__fini(&msg->planning_method);
}

bool
custom_drone_interfaces__srv__ComputePath_Request__are_equal(const custom_drone_interfaces__srv__ComputePath_Request * lhs, const custom_drone_interfaces__srv__ComputePath_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // input_path
  if (!custom_drone_interfaces__msg__Path3D__are_equal(
      &(lhs->input_path), &(rhs->input_path)))
  {
    return false;
  }
  // velocity_limit
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->velocity_limit[i] != rhs->velocity_limit[i]) {
      return false;
    }
  }
  // acceleration_limit
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->acceleration_limit[i] != rhs->acceleration_limit[i]) {
      return false;
    }
  }
  // planning_method
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->planning_method), &(rhs->planning_method)))
  {
    return false;
  }
  return true;
}

bool
custom_drone_interfaces__srv__ComputePath_Request__copy(
  const custom_drone_interfaces__srv__ComputePath_Request * input,
  custom_drone_interfaces__srv__ComputePath_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // input_path
  if (!custom_drone_interfaces__msg__Path3D__copy(
      &(input->input_path), &(output->input_path)))
  {
    return false;
  }
  // velocity_limit
  for (size_t i = 0; i < 3; ++i) {
    output->velocity_limit[i] = input->velocity_limit[i];
  }
  // acceleration_limit
  for (size_t i = 0; i < 3; ++i) {
    output->acceleration_limit[i] = input->acceleration_limit[i];
  }
  // planning_method
  if (!rosidl_runtime_c__String__copy(
      &(input->planning_method), &(output->planning_method)))
  {
    return false;
  }
  return true;
}

custom_drone_interfaces__srv__ComputePath_Request *
custom_drone_interfaces__srv__ComputePath_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__srv__ComputePath_Request * msg = (custom_drone_interfaces__srv__ComputePath_Request *)allocator.allocate(sizeof(custom_drone_interfaces__srv__ComputePath_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_drone_interfaces__srv__ComputePath_Request));
  bool success = custom_drone_interfaces__srv__ComputePath_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_drone_interfaces__srv__ComputePath_Request__destroy(custom_drone_interfaces__srv__ComputePath_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_drone_interfaces__srv__ComputePath_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_drone_interfaces__srv__ComputePath_Request__Sequence__init(custom_drone_interfaces__srv__ComputePath_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__srv__ComputePath_Request * data = NULL;

  if (size) {
    data = (custom_drone_interfaces__srv__ComputePath_Request *)allocator.zero_allocate(size, sizeof(custom_drone_interfaces__srv__ComputePath_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_drone_interfaces__srv__ComputePath_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_drone_interfaces__srv__ComputePath_Request__fini(&data[i - 1]);
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
custom_drone_interfaces__srv__ComputePath_Request__Sequence__fini(custom_drone_interfaces__srv__ComputePath_Request__Sequence * array)
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
      custom_drone_interfaces__srv__ComputePath_Request__fini(&array->data[i]);
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

custom_drone_interfaces__srv__ComputePath_Request__Sequence *
custom_drone_interfaces__srv__ComputePath_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__srv__ComputePath_Request__Sequence * array = (custom_drone_interfaces__srv__ComputePath_Request__Sequence *)allocator.allocate(sizeof(custom_drone_interfaces__srv__ComputePath_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_drone_interfaces__srv__ComputePath_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_drone_interfaces__srv__ComputePath_Request__Sequence__destroy(custom_drone_interfaces__srv__ComputePath_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_drone_interfaces__srv__ComputePath_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_drone_interfaces__srv__ComputePath_Request__Sequence__are_equal(const custom_drone_interfaces__srv__ComputePath_Request__Sequence * lhs, const custom_drone_interfaces__srv__ComputePath_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_drone_interfaces__srv__ComputePath_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_drone_interfaces__srv__ComputePath_Request__Sequence__copy(
  const custom_drone_interfaces__srv__ComputePath_Request__Sequence * input,
  custom_drone_interfaces__srv__ComputePath_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_drone_interfaces__srv__ComputePath_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_drone_interfaces__srv__ComputePath_Request * data =
      (custom_drone_interfaces__srv__ComputePath_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_drone_interfaces__srv__ComputePath_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_drone_interfaces__srv__ComputePath_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_drone_interfaces__srv__ComputePath_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `planned_path`
// already included above
// #include "custom_drone_interfaces/msg/detail/path3_d__functions.h"

bool
custom_drone_interfaces__srv__ComputePath_Response__init(custom_drone_interfaces__srv__ComputePath_Response * msg)
{
  if (!msg) {
    return false;
  }
  // planned_path
  if (!custom_drone_interfaces__msg__Path3D__init(&msg->planned_path)) {
    custom_drone_interfaces__srv__ComputePath_Response__fini(msg);
    return false;
  }
  return true;
}

void
custom_drone_interfaces__srv__ComputePath_Response__fini(custom_drone_interfaces__srv__ComputePath_Response * msg)
{
  if (!msg) {
    return;
  }
  // planned_path
  custom_drone_interfaces__msg__Path3D__fini(&msg->planned_path);
}

bool
custom_drone_interfaces__srv__ComputePath_Response__are_equal(const custom_drone_interfaces__srv__ComputePath_Response * lhs, const custom_drone_interfaces__srv__ComputePath_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // planned_path
  if (!custom_drone_interfaces__msg__Path3D__are_equal(
      &(lhs->planned_path), &(rhs->planned_path)))
  {
    return false;
  }
  return true;
}

bool
custom_drone_interfaces__srv__ComputePath_Response__copy(
  const custom_drone_interfaces__srv__ComputePath_Response * input,
  custom_drone_interfaces__srv__ComputePath_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // planned_path
  if (!custom_drone_interfaces__msg__Path3D__copy(
      &(input->planned_path), &(output->planned_path)))
  {
    return false;
  }
  return true;
}

custom_drone_interfaces__srv__ComputePath_Response *
custom_drone_interfaces__srv__ComputePath_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__srv__ComputePath_Response * msg = (custom_drone_interfaces__srv__ComputePath_Response *)allocator.allocate(sizeof(custom_drone_interfaces__srv__ComputePath_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_drone_interfaces__srv__ComputePath_Response));
  bool success = custom_drone_interfaces__srv__ComputePath_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_drone_interfaces__srv__ComputePath_Response__destroy(custom_drone_interfaces__srv__ComputePath_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_drone_interfaces__srv__ComputePath_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_drone_interfaces__srv__ComputePath_Response__Sequence__init(custom_drone_interfaces__srv__ComputePath_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__srv__ComputePath_Response * data = NULL;

  if (size) {
    data = (custom_drone_interfaces__srv__ComputePath_Response *)allocator.zero_allocate(size, sizeof(custom_drone_interfaces__srv__ComputePath_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_drone_interfaces__srv__ComputePath_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_drone_interfaces__srv__ComputePath_Response__fini(&data[i - 1]);
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
custom_drone_interfaces__srv__ComputePath_Response__Sequence__fini(custom_drone_interfaces__srv__ComputePath_Response__Sequence * array)
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
      custom_drone_interfaces__srv__ComputePath_Response__fini(&array->data[i]);
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

custom_drone_interfaces__srv__ComputePath_Response__Sequence *
custom_drone_interfaces__srv__ComputePath_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__srv__ComputePath_Response__Sequence * array = (custom_drone_interfaces__srv__ComputePath_Response__Sequence *)allocator.allocate(sizeof(custom_drone_interfaces__srv__ComputePath_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_drone_interfaces__srv__ComputePath_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_drone_interfaces__srv__ComputePath_Response__Sequence__destroy(custom_drone_interfaces__srv__ComputePath_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_drone_interfaces__srv__ComputePath_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_drone_interfaces__srv__ComputePath_Response__Sequence__are_equal(const custom_drone_interfaces__srv__ComputePath_Response__Sequence * lhs, const custom_drone_interfaces__srv__ComputePath_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_drone_interfaces__srv__ComputePath_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_drone_interfaces__srv__ComputePath_Response__Sequence__copy(
  const custom_drone_interfaces__srv__ComputePath_Response__Sequence * input,
  custom_drone_interfaces__srv__ComputePath_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_drone_interfaces__srv__ComputePath_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_drone_interfaces__srv__ComputePath_Response * data =
      (custom_drone_interfaces__srv__ComputePath_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_drone_interfaces__srv__ComputePath_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_drone_interfaces__srv__ComputePath_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_drone_interfaces__srv__ComputePath_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
