// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from custom_drone_interfaces:srv/ComputePath.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "custom_drone_interfaces/srv/detail/compute_path__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace custom_drone_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void ComputePath_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) custom_drone_interfaces::srv::ComputePath_Request(_init);
}

void ComputePath_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<custom_drone_interfaces::srv::ComputePath_Request *>(message_memory);
  typed_message->~ComputePath_Request();
}

size_t size_function__ComputePath_Request__velocity_limit(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__ComputePath_Request__velocity_limit(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__ComputePath_Request__velocity_limit(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void fetch_function__ComputePath_Request__velocity_limit(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__ComputePath_Request__velocity_limit(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__ComputePath_Request__velocity_limit(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__ComputePath_Request__velocity_limit(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__ComputePath_Request__acceleration_limit(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__ComputePath_Request__acceleration_limit(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__ComputePath_Request__acceleration_limit(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 3> *>(untyped_member);
  return &member[index];
}

void fetch_function__ComputePath_Request__acceleration_limit(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__ComputePath_Request__acceleration_limit(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__ComputePath_Request__acceleration_limit(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__ComputePath_Request__acceleration_limit(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ComputePath_Request_message_member_array[4] = {
  {
    "input_path",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<custom_drone_interfaces::msg::Path3D>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_drone_interfaces::srv::ComputePath_Request, input_path),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "velocity_limit",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(custom_drone_interfaces::srv::ComputePath_Request, velocity_limit),  // bytes offset in struct
    nullptr,  // default value
    size_function__ComputePath_Request__velocity_limit,  // size() function pointer
    get_const_function__ComputePath_Request__velocity_limit,  // get_const(index) function pointer
    get_function__ComputePath_Request__velocity_limit,  // get(index) function pointer
    fetch_function__ComputePath_Request__velocity_limit,  // fetch(index, &value) function pointer
    assign_function__ComputePath_Request__velocity_limit,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "acceleration_limit",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(custom_drone_interfaces::srv::ComputePath_Request, acceleration_limit),  // bytes offset in struct
    nullptr,  // default value
    size_function__ComputePath_Request__acceleration_limit,  // size() function pointer
    get_const_function__ComputePath_Request__acceleration_limit,  // get_const(index) function pointer
    get_function__ComputePath_Request__acceleration_limit,  // get(index) function pointer
    fetch_function__ComputePath_Request__acceleration_limit,  // fetch(index, &value) function pointer
    assign_function__ComputePath_Request__acceleration_limit,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "planning_method",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_drone_interfaces::srv::ComputePath_Request, planning_method),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ComputePath_Request_message_members = {
  "custom_drone_interfaces::srv",  // message namespace
  "ComputePath_Request",  // message name
  4,  // number of fields
  sizeof(custom_drone_interfaces::srv::ComputePath_Request),
  ComputePath_Request_message_member_array,  // message members
  ComputePath_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ComputePath_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ComputePath_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ComputePath_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace custom_drone_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_drone_interfaces::srv::ComputePath_Request>()
{
  return &::custom_drone_interfaces::srv::rosidl_typesupport_introspection_cpp::ComputePath_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_drone_interfaces, srv, ComputePath_Request)() {
  return &::custom_drone_interfaces::srv::rosidl_typesupport_introspection_cpp::ComputePath_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "custom_drone_interfaces/srv/detail/compute_path__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace custom_drone_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void ComputePath_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) custom_drone_interfaces::srv::ComputePath_Response(_init);
}

void ComputePath_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<custom_drone_interfaces::srv::ComputePath_Response *>(message_memory);
  typed_message->~ComputePath_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ComputePath_Response_message_member_array[1] = {
  {
    "planned_path",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<custom_drone_interfaces::msg::Path3D>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_drone_interfaces::srv::ComputePath_Response, planned_path),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ComputePath_Response_message_members = {
  "custom_drone_interfaces::srv",  // message namespace
  "ComputePath_Response",  // message name
  1,  // number of fields
  sizeof(custom_drone_interfaces::srv::ComputePath_Response),
  ComputePath_Response_message_member_array,  // message members
  ComputePath_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ComputePath_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ComputePath_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ComputePath_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace custom_drone_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_drone_interfaces::srv::ComputePath_Response>()
{
  return &::custom_drone_interfaces::srv::rosidl_typesupport_introspection_cpp::ComputePath_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_drone_interfaces, srv, ComputePath_Response)() {
  return &::custom_drone_interfaces::srv::rosidl_typesupport_introspection_cpp::ComputePath_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "custom_drone_interfaces/srv/detail/compute_path__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace custom_drone_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers ComputePath_service_members = {
  "custom_drone_interfaces::srv",  // service namespace
  "ComputePath",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<custom_drone_interfaces::srv::ComputePath>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t ComputePath_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ComputePath_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace custom_drone_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<custom_drone_interfaces::srv::ComputePath>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::custom_drone_interfaces::srv::rosidl_typesupport_introspection_cpp::ComputePath_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::custom_drone_interfaces::srv::ComputePath_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::custom_drone_interfaces::srv::ComputePath_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_drone_interfaces, srv, ComputePath)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<custom_drone_interfaces::srv::ComputePath>();
}

#ifdef __cplusplus
}
#endif
