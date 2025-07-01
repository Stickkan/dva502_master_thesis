// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_drone_interfaces:msg/AgentsList.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_drone_interfaces/msg/detail/agents_list__rosidl_typesupport_introspection_c.h"
#include "custom_drone_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_drone_interfaces/msg/detail/agents_list__functions.h"
#include "custom_drone_interfaces/msg/detail/agents_list__struct.h"


// Include directives for member types
// Member `agents`
#include "custom_drone_interfaces/msg/agent_data.h"
// Member `agents`
#include "custom_drone_interfaces/msg/detail/agent_data__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__AgentsList_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_drone_interfaces__msg__AgentsList__init(message_memory);
}

void custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__AgentsList_fini_function(void * message_memory)
{
  custom_drone_interfaces__msg__AgentsList__fini(message_memory);
}

size_t custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__size_function__AgentsList__agents(
  const void * untyped_member)
{
  const custom_drone_interfaces__msg__AgentData__Sequence * member =
    (const custom_drone_interfaces__msg__AgentData__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__get_const_function__AgentsList__agents(
  const void * untyped_member, size_t index)
{
  const custom_drone_interfaces__msg__AgentData__Sequence * member =
    (const custom_drone_interfaces__msg__AgentData__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__get_function__AgentsList__agents(
  void * untyped_member, size_t index)
{
  custom_drone_interfaces__msg__AgentData__Sequence * member =
    (custom_drone_interfaces__msg__AgentData__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__fetch_function__AgentsList__agents(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const custom_drone_interfaces__msg__AgentData * item =
    ((const custom_drone_interfaces__msg__AgentData *)
    custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__get_const_function__AgentsList__agents(untyped_member, index));
  custom_drone_interfaces__msg__AgentData * value =
    (custom_drone_interfaces__msg__AgentData *)(untyped_value);
  *value = *item;
}

void custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__assign_function__AgentsList__agents(
  void * untyped_member, size_t index, const void * untyped_value)
{
  custom_drone_interfaces__msg__AgentData * item =
    ((custom_drone_interfaces__msg__AgentData *)
    custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__get_function__AgentsList__agents(untyped_member, index));
  const custom_drone_interfaces__msg__AgentData * value =
    (const custom_drone_interfaces__msg__AgentData *)(untyped_value);
  *item = *value;
}

bool custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__resize_function__AgentsList__agents(
  void * untyped_member, size_t size)
{
  custom_drone_interfaces__msg__AgentData__Sequence * member =
    (custom_drone_interfaces__msg__AgentData__Sequence *)(untyped_member);
  custom_drone_interfaces__msg__AgentData__Sequence__fini(member);
  return custom_drone_interfaces__msg__AgentData__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__AgentsList_message_member_array[1] = {
  {
    "agents",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_drone_interfaces__msg__AgentsList, agents),  // bytes offset in struct
    NULL,  // default value
    custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__size_function__AgentsList__agents,  // size() function pointer
    custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__get_const_function__AgentsList__agents,  // get_const(index) function pointer
    custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__get_function__AgentsList__agents,  // get(index) function pointer
    custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__fetch_function__AgentsList__agents,  // fetch(index, &value) function pointer
    custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__assign_function__AgentsList__agents,  // assign(index, value) function pointer
    custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__resize_function__AgentsList__agents  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__AgentsList_message_members = {
  "custom_drone_interfaces__msg",  // message namespace
  "AgentsList",  // message name
  1,  // number of fields
  sizeof(custom_drone_interfaces__msg__AgentsList),
  custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__AgentsList_message_member_array,  // message members
  custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__AgentsList_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__AgentsList_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__AgentsList_message_type_support_handle = {
  0,
  &custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__AgentsList_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_drone_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_drone_interfaces, msg, AgentsList)() {
  custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__AgentsList_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_drone_interfaces, msg, AgentData)();
  if (!custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__AgentsList_message_type_support_handle.typesupport_identifier) {
    custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__AgentsList_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_drone_interfaces__msg__AgentsList__rosidl_typesupport_introspection_c__AgentsList_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
