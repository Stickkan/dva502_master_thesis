// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_drone_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_drone_interfaces/msg/detail/waypoint__rosidl_typesupport_introspection_c.h"
#include "custom_drone_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_drone_interfaces/msg/detail/waypoint__functions.h"
#include "custom_drone_interfaces/msg/detail/waypoint__struct.h"


// Include directives for member types
// Member `point`
#include "geometry_msgs/msg/point.h"
// Member `point`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `velocity`
#include "geometry_msgs/msg/vector3.h"
// Member `velocity`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"
// Member `subtrajectory`
#include "custom_drone_interfaces/msg/sub_waypoint.h"
// Member `subtrajectory`
#include "custom_drone_interfaces/msg/detail/sub_waypoint__rosidl_typesupport_introspection_c.h"
// Member `task`
#include "custom_drone_interfaces/msg/task_specification.h"
// Member `task`
#include "custom_drone_interfaces/msg/detail/task_specification__rosidl_typesupport_introspection_c.h"
// Member `commandid`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_drone_interfaces__msg__Waypoint__init(message_memory);
}

void custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_fini_function(void * message_memory)
{
  custom_drone_interfaces__msg__Waypoint__fini(message_memory);
}

size_t custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__size_function__Waypoint__subtrajectory(
  const void * untyped_member)
{
  const custom_drone_interfaces__msg__SubWaypoint__Sequence * member =
    (const custom_drone_interfaces__msg__SubWaypoint__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__get_const_function__Waypoint__subtrajectory(
  const void * untyped_member, size_t index)
{
  const custom_drone_interfaces__msg__SubWaypoint__Sequence * member =
    (const custom_drone_interfaces__msg__SubWaypoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__get_function__Waypoint__subtrajectory(
  void * untyped_member, size_t index)
{
  custom_drone_interfaces__msg__SubWaypoint__Sequence * member =
    (custom_drone_interfaces__msg__SubWaypoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__fetch_function__Waypoint__subtrajectory(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const custom_drone_interfaces__msg__SubWaypoint * item =
    ((const custom_drone_interfaces__msg__SubWaypoint *)
    custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__get_const_function__Waypoint__subtrajectory(untyped_member, index));
  custom_drone_interfaces__msg__SubWaypoint * value =
    (custom_drone_interfaces__msg__SubWaypoint *)(untyped_value);
  *value = *item;
}

void custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__assign_function__Waypoint__subtrajectory(
  void * untyped_member, size_t index, const void * untyped_value)
{
  custom_drone_interfaces__msg__SubWaypoint * item =
    ((custom_drone_interfaces__msg__SubWaypoint *)
    custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__get_function__Waypoint__subtrajectory(untyped_member, index));
  const custom_drone_interfaces__msg__SubWaypoint * value =
    (const custom_drone_interfaces__msg__SubWaypoint *)(untyped_value);
  *item = *value;
}

bool custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__resize_function__Waypoint__subtrajectory(
  void * untyped_member, size_t size)
{
  custom_drone_interfaces__msg__SubWaypoint__Sequence * member =
    (custom_drone_interfaces__msg__SubWaypoint__Sequence *)(untyped_member);
  custom_drone_interfaces__msg__SubWaypoint__Sequence__fini(member);
  return custom_drone_interfaces__msg__SubWaypoint__Sequence__init(member, size);
}

size_t custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__size_function__Waypoint__commandid(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__get_const_function__Waypoint__commandid(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__get_function__Waypoint__commandid(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__fetch_function__Waypoint__commandid(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__get_const_function__Waypoint__commandid(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__assign_function__Waypoint__commandid(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__get_function__Waypoint__commandid(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__resize_function__Waypoint__commandid(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_message_member_array[10] = {
  {
    "point",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_drone_interfaces__msg__Waypoint, point),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_drone_interfaces__msg__Waypoint, velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "subtrajectory",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_drone_interfaces__msg__Waypoint, subtrajectory),  // bytes offset in struct
    NULL,  // default value
    custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__size_function__Waypoint__subtrajectory,  // size() function pointer
    custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__get_const_function__Waypoint__subtrajectory,  // get_const(index) function pointer
    custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__get_function__Waypoint__subtrajectory,  // get(index) function pointer
    custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__fetch_function__Waypoint__subtrajectory,  // fetch(index, &value) function pointer
    custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__assign_function__Waypoint__subtrajectory,  // assign(index, value) function pointer
    custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__resize_function__Waypoint__subtrajectory  // resize(index) function pointer
  },
  {
    "stop",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_drone_interfaces__msg__Waypoint, stop),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "heading",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_drone_interfaces__msg__Waypoint, heading),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "time_in_seconds",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_drone_interfaces__msg__Waypoint, time_in_seconds),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "hold_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_drone_interfaces__msg__Waypoint, hold_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acceptence_radius",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_drone_interfaces__msg__Waypoint, acceptence_radius),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "task",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_drone_interfaces__msg__Waypoint, task),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "commandid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_drone_interfaces__msg__Waypoint, commandid),  // bytes offset in struct
    NULL,  // default value
    custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__size_function__Waypoint__commandid,  // size() function pointer
    custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__get_const_function__Waypoint__commandid,  // get_const(index) function pointer
    custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__get_function__Waypoint__commandid,  // get(index) function pointer
    custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__fetch_function__Waypoint__commandid,  // fetch(index, &value) function pointer
    custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__assign_function__Waypoint__commandid,  // assign(index, value) function pointer
    custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__resize_function__Waypoint__commandid  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_message_members = {
  "custom_drone_interfaces__msg",  // message namespace
  "Waypoint",  // message name
  10,  // number of fields
  sizeof(custom_drone_interfaces__msg__Waypoint),
  custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_message_member_array,  // message members
  custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_message_type_support_handle = {
  0,
  &custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_drone_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_drone_interfaces, msg, Waypoint)() {
  custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_drone_interfaces, msg, SubWaypoint)();
  custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_message_member_array[8].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_drone_interfaces, msg, TaskSpecification)();
  if (!custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_message_type_support_handle.typesupport_identifier) {
    custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_drone_interfaces__msg__Waypoint__rosidl_typesupport_introspection_c__Waypoint_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
