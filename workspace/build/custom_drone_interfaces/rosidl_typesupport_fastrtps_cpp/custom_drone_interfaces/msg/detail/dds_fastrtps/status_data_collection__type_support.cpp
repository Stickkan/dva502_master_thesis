// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from custom_drone_interfaces:msg/StatusDataCollection.idl
// generated code does not contain a copyright notice
#include "custom_drone_interfaces/msg/detail/status_data_collection__rosidl_typesupport_fastrtps_cpp.hpp"
#include "custom_drone_interfaces/msg/detail/status_data_collection__struct.hpp"

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

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_drone_interfaces
cdr_serialize(
  const custom_drone_interfaces::msg::StatusDataCollection & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: remaining
  cdr << ros_message.remaining;
  // Member: time_remaining_s
  cdr << ros_message.time_remaining_s;
  // Member: battery_warning
  cdr << ros_message.battery_warning;
  // Member: battery_unhealthy
  cdr << (ros_message.battery_unhealthy ? true : false);
  // Member: angular_velocity_invalid
  cdr << (ros_message.angular_velocity_invalid ? true : false);
  // Member: attitude_invalid
  cdr << (ros_message.attitude_invalid ? true : false);
  // Member: global_position_invalid
  cdr << (ros_message.global_position_invalid ? true : false);
  // Member: wind_limit_exceeded
  cdr << (ros_message.wind_limit_exceeded ? true : false);
  // Member: esc_arming_failure
  cdr << (ros_message.esc_arming_failure ? true : false);
  // Member: imbalanced_prop
  cdr << (ros_message.imbalanced_prop ? true : false);
  // Member: motor_failure
  cdr << (ros_message.motor_failure ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_drone_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  custom_drone_interfaces::msg::StatusDataCollection & ros_message)
{
  // Member: remaining
  cdr >> ros_message.remaining;

  // Member: time_remaining_s
  cdr >> ros_message.time_remaining_s;

  // Member: battery_warning
  cdr >> ros_message.battery_warning;

  // Member: battery_unhealthy
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.battery_unhealthy = tmp ? true : false;
  }

  // Member: angular_velocity_invalid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.angular_velocity_invalid = tmp ? true : false;
  }

  // Member: attitude_invalid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.attitude_invalid = tmp ? true : false;
  }

  // Member: global_position_invalid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.global_position_invalid = tmp ? true : false;
  }

  // Member: wind_limit_exceeded
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.wind_limit_exceeded = tmp ? true : false;
  }

  // Member: esc_arming_failure
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.esc_arming_failure = tmp ? true : false;
  }

  // Member: imbalanced_prop
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.imbalanced_prop = tmp ? true : false;
  }

  // Member: motor_failure
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.motor_failure = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_drone_interfaces
get_serialized_size(
  const custom_drone_interfaces::msg::StatusDataCollection & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: remaining
  {
    size_t item_size = sizeof(ros_message.remaining);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: time_remaining_s
  {
    size_t item_size = sizeof(ros_message.time_remaining_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: battery_warning
  {
    size_t item_size = sizeof(ros_message.battery_warning);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: battery_unhealthy
  {
    size_t item_size = sizeof(ros_message.battery_unhealthy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: angular_velocity_invalid
  {
    size_t item_size = sizeof(ros_message.angular_velocity_invalid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: attitude_invalid
  {
    size_t item_size = sizeof(ros_message.attitude_invalid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: global_position_invalid
  {
    size_t item_size = sizeof(ros_message.global_position_invalid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: wind_limit_exceeded
  {
    size_t item_size = sizeof(ros_message.wind_limit_exceeded);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: esc_arming_failure
  {
    size_t item_size = sizeof(ros_message.esc_arming_failure);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: imbalanced_prop
  {
    size_t item_size = sizeof(ros_message.imbalanced_prop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: motor_failure
  {
    size_t item_size = sizeof(ros_message.motor_failure);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_drone_interfaces
max_serialized_size_StatusDataCollection(
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


  // Member: remaining
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: time_remaining_s
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: battery_warning
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: battery_unhealthy
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: angular_velocity_invalid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: attitude_invalid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: global_position_invalid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: wind_limit_exceeded
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: esc_arming_failure
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: imbalanced_prop
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: motor_failure
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
    using DataType = custom_drone_interfaces::msg::StatusDataCollection;
    is_plain =
      (
      offsetof(DataType, motor_failure) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _StatusDataCollection__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const custom_drone_interfaces::msg::StatusDataCollection *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _StatusDataCollection__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<custom_drone_interfaces::msg::StatusDataCollection *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _StatusDataCollection__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const custom_drone_interfaces::msg::StatusDataCollection *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _StatusDataCollection__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_StatusDataCollection(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _StatusDataCollection__callbacks = {
  "custom_drone_interfaces::msg",
  "StatusDataCollection",
  _StatusDataCollection__cdr_serialize,
  _StatusDataCollection__cdr_deserialize,
  _StatusDataCollection__get_serialized_size,
  _StatusDataCollection__max_serialized_size
};

static rosidl_message_type_support_t _StatusDataCollection__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_StatusDataCollection__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace custom_drone_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_custom_drone_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_drone_interfaces::msg::StatusDataCollection>()
{
  return &custom_drone_interfaces::msg::typesupport_fastrtps_cpp::_StatusDataCollection__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_drone_interfaces, msg, StatusDataCollection)() {
  return &custom_drone_interfaces::msg::typesupport_fastrtps_cpp::_StatusDataCollection__handle;
}

#ifdef __cplusplus
}
#endif
