// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from custom_drone_interfaces:msg/Path3D.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "custom_drone_interfaces/msg/detail/path3_d__struct.hpp"
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

void Path3D_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) custom_drone_interfaces::msg::Path3D(_init);
}

void Path3D_fini_function(void * message_memory)
{
  auto typed_message = static_cast<custom_drone_interfaces::msg::Path3D *>(message_memory);
  typed_message->~Path3D();
}

size_t size_function__Path3D__waypoints(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<custom_drone_interfaces::msg::Waypoint> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Path3D__waypoints(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<custom_drone_interfaces::msg::Waypoint> *>(untyped_member);
  return &member[index];
}

void * get_function__Path3D__waypoints(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<custom_drone_interfaces::msg::Waypoint> *>(untyped_member);
  return &member[index];
}

void fetch_function__Path3D__waypoints(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const custom_drone_interfaces::msg::Waypoint *>(
    get_const_function__Path3D__waypoints(untyped_member, index));
  auto & value = *reinterpret_cast<custom_drone_interfaces::msg::Waypoint *>(untyped_value);
  value = item;
}

void assign_function__Path3D__waypoints(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<custom_drone_interfaces::msg::Waypoint *>(
    get_function__Path3D__waypoints(untyped_member, index));
  const auto & value = *reinterpret_cast<const custom_drone_interfaces::msg::Waypoint *>(untyped_value);
  item = value;
}

void resize_function__Path3D__waypoints(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<custom_drone_interfaces::msg::Waypoint> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Path3D_message_member_array[1] = {
  {
    "waypoints",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<custom_drone_interfaces::msg::Waypoint>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_drone_interfaces::msg::Path3D, waypoints),  // bytes offset in struct
    nullptr,  // default value
    size_function__Path3D__waypoints,  // size() function pointer
    get_const_function__Path3D__waypoints,  // get_const(index) function pointer
    get_function__Path3D__waypoints,  // get(index) function pointer
    fetch_function__Path3D__waypoints,  // fetch(index, &value) function pointer
    assign_function__Path3D__waypoints,  // assign(index, value) function pointer
    resize_function__Path3D__waypoints  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Path3D_message_members = {
  "custom_drone_interfaces::msg",  // message namespace
  "Path3D",  // message name
  1,  // number of fields
  sizeof(custom_drone_interfaces::msg::Path3D),
  Path3D_message_member_array,  // message members
  Path3D_init_function,  // function to initialize message memory (memory has to be allocated)
  Path3D_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Path3D_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Path3D_message_members,
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
get_message_type_support_handle<custom_drone_interfaces::msg::Path3D>()
{
  return &::custom_drone_interfaces::msg::rosidl_typesupport_introspection_cpp::Path3D_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_drone_interfaces, msg, Path3D)() {
  return &::custom_drone_interfaces::msg::rosidl_typesupport_introspection_cpp::Path3D_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
