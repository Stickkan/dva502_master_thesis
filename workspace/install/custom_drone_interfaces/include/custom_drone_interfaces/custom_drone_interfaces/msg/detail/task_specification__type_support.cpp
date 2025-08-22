// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from custom_drone_interfaces:msg/TaskSpecification.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "custom_drone_interfaces/msg/detail/task_specification__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace custom_drone_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TaskSpecification_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) custom_drone_interfaces::msg::TaskSpecification(_init);
}

void TaskSpecification_fini_function(void * message_memory)
{
  auto typed_message = static_cast<custom_drone_interfaces::msg::TaskSpecification *>(message_memory);
  typed_message->~TaskSpecification();
}

size_t size_function__TaskSpecification__settings(const void * untyped_member)
{
  (void)untyped_member;
  return 5;
}

const void * get_const_function__TaskSpecification__settings(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 5> *>(untyped_member);
  return &member[index];
}

void * get_function__TaskSpecification__settings(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 5> *>(untyped_member);
  return &member[index];
}

void fetch_function__TaskSpecification__settings(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__TaskSpecification__settings(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__TaskSpecification__settings(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__TaskSpecification__settings(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TaskSpecification_message_member_array[2] = {
  {
    "flag",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_drone_interfaces::msg::TaskSpecification, flag),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "settings",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    5,  // array size
    false,  // is upper bound
    offsetof(custom_drone_interfaces::msg::TaskSpecification, settings),  // bytes offset in struct
    nullptr,  // default value
    size_function__TaskSpecification__settings,  // size() function pointer
    get_const_function__TaskSpecification__settings,  // get_const(index) function pointer
    get_function__TaskSpecification__settings,  // get(index) function pointer
    fetch_function__TaskSpecification__settings,  // fetch(index, &value) function pointer
    assign_function__TaskSpecification__settings,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TaskSpecification_message_members = {
  "custom_drone_interfaces::msg",  // message namespace
  "TaskSpecification",  // message name
  2,  // number of fields
  sizeof(custom_drone_interfaces::msg::TaskSpecification),
  TaskSpecification_message_member_array,  // message members
  TaskSpecification_init_function,  // function to initialize message memory (memory has to be allocated)
  TaskSpecification_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TaskSpecification_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TaskSpecification_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace custom_drone_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_drone_interfaces::msg::TaskSpecification>()
{
  return &::custom_drone_interfaces::msg::rosidl_typesupport_introspection_cpp::TaskSpecification_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_drone_interfaces, msg, TaskSpecification)() {
  return &::custom_drone_interfaces::msg::rosidl_typesupport_introspection_cpp::TaskSpecification_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
