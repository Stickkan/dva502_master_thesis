// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from custom_drone_interfaces:msg/MissionCommand.idl
// generated code does not contain a copyright notice
#include "custom_drone_interfaces/msg/detail/mission_command__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "custom_drone_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_drone_interfaces/msg/detail/mission_command__struct.h"
#include "custom_drone_interfaces/msg/detail/mission_command__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _MissionCommand__ros_msg_type = custom_drone_interfaces__msg__MissionCommand;

static bool _MissionCommand__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MissionCommand__ros_msg_type * ros_message = static_cast<const _MissionCommand__ros_msg_type *>(untyped_ros_message);
  // Field name: command_flag
  {
    cdr << ros_message->command_flag;
  }

  return true;
}

static bool _MissionCommand__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MissionCommand__ros_msg_type * ros_message = static_cast<_MissionCommand__ros_msg_type *>(untyped_ros_message);
  // Field name: command_flag
  {
    cdr >> ros_message->command_flag;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_drone_interfaces
size_t get_serialized_size_custom_drone_interfaces__msg__MissionCommand(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MissionCommand__ros_msg_type * ros_message = static_cast<const _MissionCommand__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name command_flag
  {
    size_t item_size = sizeof(ros_message->command_flag);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MissionCommand__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_drone_interfaces__msg__MissionCommand(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_drone_interfaces
size_t max_serialized_size_custom_drone_interfaces__msg__MissionCommand(
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

  // member: command_flag
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = custom_drone_interfaces__msg__MissionCommand;
    is_plain =
      (
      offsetof(DataType, command_flag) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _MissionCommand__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_custom_drone_interfaces__msg__MissionCommand(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_MissionCommand = {
  "custom_drone_interfaces::msg",
  "MissionCommand",
  _MissionCommand__cdr_serialize,
  _MissionCommand__cdr_deserialize,
  _MissionCommand__get_serialized_size,
  _MissionCommand__max_serialized_size
};

static rosidl_message_type_support_t _MissionCommand__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MissionCommand,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_drone_interfaces, msg, MissionCommand)() {
  return &_MissionCommand__type_support;
}

#if defined(__cplusplus)
}
#endif
