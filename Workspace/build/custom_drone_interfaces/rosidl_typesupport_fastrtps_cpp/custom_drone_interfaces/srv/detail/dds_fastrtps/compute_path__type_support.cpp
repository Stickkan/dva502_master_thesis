// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from custom_drone_interfaces:srv/ComputePath.idl
// generated code does not contain a copyright notice
#include "custom_drone_interfaces/srv/detail/compute_path__rosidl_typesupport_fastrtps_cpp.hpp"
#include "custom_drone_interfaces/srv/detail/compute_path__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace custom_drone_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const custom_drone_interfaces::msg::Path3D &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  custom_drone_interfaces::msg::Path3D &);
size_t get_serialized_size(
  const custom_drone_interfaces::msg::Path3D &,
  size_t current_alignment);
size_t
max_serialized_size_Path3D(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace custom_drone_interfaces


namespace custom_drone_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_drone_interfaces
cdr_serialize(
  const custom_drone_interfaces::srv::ComputePath_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: input_path
  custom_drone_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.input_path,
    cdr);
  // Member: velocity_limit
  {
    cdr << ros_message.velocity_limit;
  }
  // Member: acceleration_limit
  {
    cdr << ros_message.acceleration_limit;
  }
  // Member: planning_method
  cdr << ros_message.planning_method;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_drone_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  custom_drone_interfaces::srv::ComputePath_Request & ros_message)
{
  // Member: input_path
  custom_drone_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.input_path);

  // Member: velocity_limit
  {
    cdr >> ros_message.velocity_limit;
  }

  // Member: acceleration_limit
  {
    cdr >> ros_message.acceleration_limit;
  }

  // Member: planning_method
  cdr >> ros_message.planning_method;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_drone_interfaces
get_serialized_size(
  const custom_drone_interfaces::srv::ComputePath_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: input_path

  current_alignment +=
    custom_drone_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.input_path, current_alignment);
  // Member: velocity_limit
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.velocity_limit[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: acceleration_limit
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.acceleration_limit[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: planning_method
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.planning_method.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_drone_interfaces
max_serialized_size_ComputePath_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: input_path
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        custom_drone_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_Path3D(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: velocity_limit
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: acceleration_limit
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: planning_method
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = custom_drone_interfaces::srv::ComputePath_Request;
    is_plain =
      (
      offsetof(DataType, planning_method) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ComputePath_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const custom_drone_interfaces::srv::ComputePath_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ComputePath_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<custom_drone_interfaces::srv::ComputePath_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ComputePath_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const custom_drone_interfaces::srv::ComputePath_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ComputePath_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ComputePath_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ComputePath_Request__callbacks = {
  "custom_drone_interfaces::srv",
  "ComputePath_Request",
  _ComputePath_Request__cdr_serialize,
  _ComputePath_Request__cdr_deserialize,
  _ComputePath_Request__get_serialized_size,
  _ComputePath_Request__max_serialized_size
};

static rosidl_message_type_support_t _ComputePath_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ComputePath_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace custom_drone_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_custom_drone_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_drone_interfaces::srv::ComputePath_Request>()
{
  return &custom_drone_interfaces::srv::typesupport_fastrtps_cpp::_ComputePath_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_drone_interfaces, srv, ComputePath_Request)() {
  return &custom_drone_interfaces::srv::typesupport_fastrtps_cpp::_ComputePath_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
// functions for custom_drone_interfaces::msg::Path3D already declared above


namespace custom_drone_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_drone_interfaces
cdr_serialize(
  const custom_drone_interfaces::srv::ComputePath_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: planned_path
  custom_drone_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.planned_path,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_drone_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  custom_drone_interfaces::srv::ComputePath_Response & ros_message)
{
  // Member: planned_path
  custom_drone_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.planned_path);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_drone_interfaces
get_serialized_size(
  const custom_drone_interfaces::srv::ComputePath_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: planned_path

  current_alignment +=
    custom_drone_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.planned_path, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_drone_interfaces
max_serialized_size_ComputePath_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: planned_path
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        custom_drone_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_Path3D(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = custom_drone_interfaces::srv::ComputePath_Response;
    is_plain =
      (
      offsetof(DataType, planned_path) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ComputePath_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const custom_drone_interfaces::srv::ComputePath_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ComputePath_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<custom_drone_interfaces::srv::ComputePath_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ComputePath_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const custom_drone_interfaces::srv::ComputePath_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ComputePath_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ComputePath_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ComputePath_Response__callbacks = {
  "custom_drone_interfaces::srv",
  "ComputePath_Response",
  _ComputePath_Response__cdr_serialize,
  _ComputePath_Response__cdr_deserialize,
  _ComputePath_Response__get_serialized_size,
  _ComputePath_Response__max_serialized_size
};

static rosidl_message_type_support_t _ComputePath_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ComputePath_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace custom_drone_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_custom_drone_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_drone_interfaces::srv::ComputePath_Response>()
{
  return &custom_drone_interfaces::srv::typesupport_fastrtps_cpp::_ComputePath_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_drone_interfaces, srv, ComputePath_Response)() {
  return &custom_drone_interfaces::srv::typesupport_fastrtps_cpp::_ComputePath_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace custom_drone_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _ComputePath__callbacks = {
  "custom_drone_interfaces::srv",
  "ComputePath",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_drone_interfaces, srv, ComputePath_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_drone_interfaces, srv, ComputePath_Response)(),
};

static rosidl_service_type_support_t _ComputePath__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ComputePath__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace custom_drone_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_custom_drone_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<custom_drone_interfaces::srv::ComputePath>()
{
  return &custom_drone_interfaces::srv::typesupport_fastrtps_cpp::_ComputePath__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_drone_interfaces, srv, ComputePath)() {
  return &custom_drone_interfaces::srv::typesupport_fastrtps_cpp::_ComputePath__handle;
}

#ifdef __cplusplus
}
#endif
