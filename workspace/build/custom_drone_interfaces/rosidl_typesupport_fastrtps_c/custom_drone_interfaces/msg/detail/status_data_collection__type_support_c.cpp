// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from custom_drone_interfaces:msg/StatusDataCollection.idl
// generated code does not contain a copyright notice
#include "custom_drone_interfaces/msg/detail/status_data_collection__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "custom_drone_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_drone_interfaces/msg/detail/status_data_collection__struct.h"
#include "custom_drone_interfaces/msg/detail/status_data_collection__functions.h"
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


using _StatusDataCollection__ros_msg_type = custom_drone_interfaces__msg__StatusDataCollection;

static bool _StatusDataCollection__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _StatusDataCollection__ros_msg_type * ros_message = static_cast<const _StatusDataCollection__ros_msg_type *>(untyped_ros_message);
  // Field name: remaining
  {
    cdr << ros_message->remaining;
  }

  // Field name: time_remaining_s
  {
    cdr << ros_message->time_remaining_s;
  }

  // Field name: battery_warning
  {
    cdr << ros_message->battery_warning;
  }

  // Field name: battery_unhealthy
  {
    cdr << (ros_message->battery_unhealthy ? true : false);
  }

  // Field name: angular_velocity_invalid
  {
    cdr << (ros_message->angular_velocity_invalid ? true : false);
  }

  // Field name: attitude_invalid
  {
    cdr << (ros_message->attitude_invalid ? true : false);
  }

  // Field name: global_position_invalid
  {
    cdr << (ros_message->global_position_invalid ? true : false);
  }

  // Field name: wind_limit_exceeded
  {
    cdr << (ros_message->wind_limit_exceeded ? true : false);
  }

  // Field name: esc_arming_failure
  {
    cdr << (ros_message->esc_arming_failure ? true : false);
  }

  // Field name: imbalanced_prop
  {
    cdr << (ros_message->imbalanced_prop ? true : false);
  }

  // Field name: motor_failure
  {
    cdr << (ros_message->motor_failure ? true : false);
  }

  return true;
}

static bool _StatusDataCollection__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _StatusDataCollection__ros_msg_type * ros_message = static_cast<_StatusDataCollection__ros_msg_type *>(untyped_ros_message);
  // Field name: remaining
  {
    cdr >> ros_message->remaining;
  }

  // Field name: time_remaining_s
  {
    cdr >> ros_message->time_remaining_s;
  }

  // Field name: battery_warning
  {
    cdr >> ros_message->battery_warning;
  }

  // Field name: battery_unhealthy
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->battery_unhealthy = tmp ? true : false;
  }

  // Field name: angular_velocity_invalid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->angular_velocity_invalid = tmp ? true : false;
  }

  // Field name: attitude_invalid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->attitude_invalid = tmp ? true : false;
  }

  // Field name: global_position_invalid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->global_position_invalid = tmp ? true : false;
  }

  // Field name: wind_limit_exceeded
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->wind_limit_exceeded = tmp ? true : false;
  }

  // Field name: esc_arming_failure
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->esc_arming_failure = tmp ? true : false;
  }

  // Field name: imbalanced_prop
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->imbalanced_prop = tmp ? true : false;
  }

  // Field name: motor_failure
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->motor_failure = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_drone_interfaces
size_t get_serialized_size_custom_drone_interfaces__msg__StatusDataCollection(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _StatusDataCollection__ros_msg_type * ros_message = static_cast<const _StatusDataCollection__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name remaining
  {
    size_t item_size = sizeof(ros_message->remaining);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name time_remaining_s
  {
    size_t item_size = sizeof(ros_message->time_remaining_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name battery_warning
  {
    size_t item_size = sizeof(ros_message->battery_warning);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name battery_unhealthy
  {
    size_t item_size = sizeof(ros_message->battery_unhealthy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name angular_velocity_invalid
  {
    size_t item_size = sizeof(ros_message->angular_velocity_invalid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name attitude_invalid
  {
    size_t item_size = sizeof(ros_message->attitude_invalid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name global_position_invalid
  {
    size_t item_size = sizeof(ros_message->global_position_invalid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name wind_limit_exceeded
  {
    size_t item_size = sizeof(ros_message->wind_limit_exceeded);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name esc_arming_failure
  {
    size_t item_size = sizeof(ros_message->esc_arming_failure);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name imbalanced_prop
  {
    size_t item_size = sizeof(ros_message->imbalanced_prop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name motor_failure
  {
    size_t item_size = sizeof(ros_message->motor_failure);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _StatusDataCollection__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_drone_interfaces__msg__StatusDataCollection(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_drone_interfaces
size_t max_serialized_size_custom_drone_interfaces__msg__StatusDataCollection(
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

  // member: remaining
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: time_remaining_s
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: battery_warning
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: battery_unhealthy
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: angular_velocity_invalid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: attitude_invalid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: global_position_invalid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: wind_limit_exceeded
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: esc_arming_failure
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: imbalanced_prop
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: motor_failure
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = custom_drone_interfaces__msg__StatusDataCollection;
    is_plain =
      (
      offsetof(DataType, motor_failure) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _StatusDataCollection__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_custom_drone_interfaces__msg__StatusDataCollection(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_StatusDataCollection = {
  "custom_drone_interfaces::msg",
  "StatusDataCollection",
  _StatusDataCollection__cdr_serialize,
  _StatusDataCollection__cdr_deserialize,
  _StatusDataCollection__get_serialized_size,
  _StatusDataCollection__max_serialized_size
};

static rosidl_message_type_support_t _StatusDataCollection__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_StatusDataCollection,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_drone_interfaces, msg, StatusDataCollection)() {
  return &_StatusDataCollection__type_support;
}

#if defined(__cplusplus)
}
#endif
