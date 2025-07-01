// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_drone_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice
#include "custom_drone_interfaces/msg/detail/waypoint__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `point`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `velocity`
#include "geometry_msgs/msg/detail/vector3__functions.h"
// Member `subtrajectory`
#include "custom_drone_interfaces/msg/detail/sub_waypoint__functions.h"
// Member `task`
#include "custom_drone_interfaces/msg/detail/task_specification__functions.h"
// Member `commandid`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
custom_drone_interfaces__msg__Waypoint__init(custom_drone_interfaces__msg__Waypoint * msg)
{
  if (!msg) {
    return false;
  }
  // point
  if (!geometry_msgs__msg__Point__init(&msg->point)) {
    custom_drone_interfaces__msg__Waypoint__fini(msg);
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Vector3__init(&msg->velocity)) {
    custom_drone_interfaces__msg__Waypoint__fini(msg);
    return false;
  }
  // subtrajectory
  if (!custom_drone_interfaces__msg__SubWaypoint__Sequence__init(&msg->subtrajectory, 0)) {
    custom_drone_interfaces__msg__Waypoint__fini(msg);
    return false;
  }
  // stop
  // heading
  // time_in_seconds
  // hold_time
  // acceptence_radius
  // task
  if (!custom_drone_interfaces__msg__TaskSpecification__init(&msg->task)) {
    custom_drone_interfaces__msg__Waypoint__fini(msg);
    return false;
  }
  // commandid
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->commandid, 0)) {
    custom_drone_interfaces__msg__Waypoint__fini(msg);
    return false;
  }
  return true;
}

void
custom_drone_interfaces__msg__Waypoint__fini(custom_drone_interfaces__msg__Waypoint * msg)
{
  if (!msg) {
    return;
  }
  // point
  geometry_msgs__msg__Point__fini(&msg->point);
  // velocity
  geometry_msgs__msg__Vector3__fini(&msg->velocity);
  // subtrajectory
  custom_drone_interfaces__msg__SubWaypoint__Sequence__fini(&msg->subtrajectory);
  // stop
  // heading
  // time_in_seconds
  // hold_time
  // acceptence_radius
  // task
  custom_drone_interfaces__msg__TaskSpecification__fini(&msg->task);
  // commandid
  rosidl_runtime_c__int32__Sequence__fini(&msg->commandid);
}

bool
custom_drone_interfaces__msg__Waypoint__are_equal(const custom_drone_interfaces__msg__Waypoint * lhs, const custom_drone_interfaces__msg__Waypoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // point
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->point), &(rhs->point)))
  {
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->velocity), &(rhs->velocity)))
  {
    return false;
  }
  // subtrajectory
  if (!custom_drone_interfaces__msg__SubWaypoint__Sequence__are_equal(
      &(lhs->subtrajectory), &(rhs->subtrajectory)))
  {
    return false;
  }
  // stop
  if (lhs->stop != rhs->stop) {
    return false;
  }
  // heading
  if (lhs->heading != rhs->heading) {
    return false;
  }
  // time_in_seconds
  if (lhs->time_in_seconds != rhs->time_in_seconds) {
    return false;
  }
  // hold_time
  if (lhs->hold_time != rhs->hold_time) {
    return false;
  }
  // acceptence_radius
  if (lhs->acceptence_radius != rhs->acceptence_radius) {
    return false;
  }
  // task
  if (!custom_drone_interfaces__msg__TaskSpecification__are_equal(
      &(lhs->task), &(rhs->task)))
  {
    return false;
  }
  // commandid
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->commandid), &(rhs->commandid)))
  {
    return false;
  }
  return true;
}

bool
custom_drone_interfaces__msg__Waypoint__copy(
  const custom_drone_interfaces__msg__Waypoint * input,
  custom_drone_interfaces__msg__Waypoint * output)
{
  if (!input || !output) {
    return false;
  }
  // point
  if (!geometry_msgs__msg__Point__copy(
      &(input->point), &(output->point)))
  {
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->velocity), &(output->velocity)))
  {
    return false;
  }
  // subtrajectory
  if (!custom_drone_interfaces__msg__SubWaypoint__Sequence__copy(
      &(input->subtrajectory), &(output->subtrajectory)))
  {
    return false;
  }
  // stop
  output->stop = input->stop;
  // heading
  output->heading = input->heading;
  // time_in_seconds
  output->time_in_seconds = input->time_in_seconds;
  // hold_time
  output->hold_time = input->hold_time;
  // acceptence_radius
  output->acceptence_radius = input->acceptence_radius;
  // task
  if (!custom_drone_interfaces__msg__TaskSpecification__copy(
      &(input->task), &(output->task)))
  {
    return false;
  }
  // commandid
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->commandid), &(output->commandid)))
  {
    return false;
  }
  return true;
}

custom_drone_interfaces__msg__Waypoint *
custom_drone_interfaces__msg__Waypoint__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__Waypoint * msg = (custom_drone_interfaces__msg__Waypoint *)allocator.allocate(sizeof(custom_drone_interfaces__msg__Waypoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_drone_interfaces__msg__Waypoint));
  bool success = custom_drone_interfaces__msg__Waypoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_drone_interfaces__msg__Waypoint__destroy(custom_drone_interfaces__msg__Waypoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_drone_interfaces__msg__Waypoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_drone_interfaces__msg__Waypoint__Sequence__init(custom_drone_interfaces__msg__Waypoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__Waypoint * data = NULL;

  if (size) {
    data = (custom_drone_interfaces__msg__Waypoint *)allocator.zero_allocate(size, sizeof(custom_drone_interfaces__msg__Waypoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_drone_interfaces__msg__Waypoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_drone_interfaces__msg__Waypoint__fini(&data[i - 1]);
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
custom_drone_interfaces__msg__Waypoint__Sequence__fini(custom_drone_interfaces__msg__Waypoint__Sequence * array)
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
      custom_drone_interfaces__msg__Waypoint__fini(&array->data[i]);
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

custom_drone_interfaces__msg__Waypoint__Sequence *
custom_drone_interfaces__msg__Waypoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_drone_interfaces__msg__Waypoint__Sequence * array = (custom_drone_interfaces__msg__Waypoint__Sequence *)allocator.allocate(sizeof(custom_drone_interfaces__msg__Waypoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_drone_interfaces__msg__Waypoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_drone_interfaces__msg__Waypoint__Sequence__destroy(custom_drone_interfaces__msg__Waypoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_drone_interfaces__msg__Waypoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_drone_interfaces__msg__Waypoint__Sequence__are_equal(const custom_drone_interfaces__msg__Waypoint__Sequence * lhs, const custom_drone_interfaces__msg__Waypoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_drone_interfaces__msg__Waypoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_drone_interfaces__msg__Waypoint__Sequence__copy(
  const custom_drone_interfaces__msg__Waypoint__Sequence * input,
  custom_drone_interfaces__msg__Waypoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_drone_interfaces__msg__Waypoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_drone_interfaces__msg__Waypoint * data =
      (custom_drone_interfaces__msg__Waypoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_drone_interfaces__msg__Waypoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_drone_interfaces__msg__Waypoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_drone_interfaces__msg__Waypoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
