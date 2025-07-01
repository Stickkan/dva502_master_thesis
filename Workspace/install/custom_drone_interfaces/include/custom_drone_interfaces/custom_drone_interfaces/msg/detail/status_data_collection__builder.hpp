// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_drone_interfaces:msg/StatusDataCollection.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__STATUS_DATA_COLLECTION__BUILDER_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__STATUS_DATA_COLLECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_drone_interfaces/msg/detail/status_data_collection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_drone_interfaces
{

namespace msg
{

namespace builder
{

class Init_StatusDataCollection_motor_failure
{
public:
  explicit Init_StatusDataCollection_motor_failure(::custom_drone_interfaces::msg::StatusDataCollection & msg)
  : msg_(msg)
  {}
  ::custom_drone_interfaces::msg::StatusDataCollection motor_failure(::custom_drone_interfaces::msg::StatusDataCollection::_motor_failure_type arg)
  {
    msg_.motor_failure = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::msg::StatusDataCollection msg_;
};

class Init_StatusDataCollection_imbalanced_prop
{
public:
  explicit Init_StatusDataCollection_imbalanced_prop(::custom_drone_interfaces::msg::StatusDataCollection & msg)
  : msg_(msg)
  {}
  Init_StatusDataCollection_motor_failure imbalanced_prop(::custom_drone_interfaces::msg::StatusDataCollection::_imbalanced_prop_type arg)
  {
    msg_.imbalanced_prop = std::move(arg);
    return Init_StatusDataCollection_motor_failure(msg_);
  }

private:
  ::custom_drone_interfaces::msg::StatusDataCollection msg_;
};

class Init_StatusDataCollection_esc_arming_failure
{
public:
  explicit Init_StatusDataCollection_esc_arming_failure(::custom_drone_interfaces::msg::StatusDataCollection & msg)
  : msg_(msg)
  {}
  Init_StatusDataCollection_imbalanced_prop esc_arming_failure(::custom_drone_interfaces::msg::StatusDataCollection::_esc_arming_failure_type arg)
  {
    msg_.esc_arming_failure = std::move(arg);
    return Init_StatusDataCollection_imbalanced_prop(msg_);
  }

private:
  ::custom_drone_interfaces::msg::StatusDataCollection msg_;
};

class Init_StatusDataCollection_wind_limit_exceeded
{
public:
  explicit Init_StatusDataCollection_wind_limit_exceeded(::custom_drone_interfaces::msg::StatusDataCollection & msg)
  : msg_(msg)
  {}
  Init_StatusDataCollection_esc_arming_failure wind_limit_exceeded(::custom_drone_interfaces::msg::StatusDataCollection::_wind_limit_exceeded_type arg)
  {
    msg_.wind_limit_exceeded = std::move(arg);
    return Init_StatusDataCollection_esc_arming_failure(msg_);
  }

private:
  ::custom_drone_interfaces::msg::StatusDataCollection msg_;
};

class Init_StatusDataCollection_global_position_invalid
{
public:
  explicit Init_StatusDataCollection_global_position_invalid(::custom_drone_interfaces::msg::StatusDataCollection & msg)
  : msg_(msg)
  {}
  Init_StatusDataCollection_wind_limit_exceeded global_position_invalid(::custom_drone_interfaces::msg::StatusDataCollection::_global_position_invalid_type arg)
  {
    msg_.global_position_invalid = std::move(arg);
    return Init_StatusDataCollection_wind_limit_exceeded(msg_);
  }

private:
  ::custom_drone_interfaces::msg::StatusDataCollection msg_;
};

class Init_StatusDataCollection_attitude_invalid
{
public:
  explicit Init_StatusDataCollection_attitude_invalid(::custom_drone_interfaces::msg::StatusDataCollection & msg)
  : msg_(msg)
  {}
  Init_StatusDataCollection_global_position_invalid attitude_invalid(::custom_drone_interfaces::msg::StatusDataCollection::_attitude_invalid_type arg)
  {
    msg_.attitude_invalid = std::move(arg);
    return Init_StatusDataCollection_global_position_invalid(msg_);
  }

private:
  ::custom_drone_interfaces::msg::StatusDataCollection msg_;
};

class Init_StatusDataCollection_angular_velocity_invalid
{
public:
  explicit Init_StatusDataCollection_angular_velocity_invalid(::custom_drone_interfaces::msg::StatusDataCollection & msg)
  : msg_(msg)
  {}
  Init_StatusDataCollection_attitude_invalid angular_velocity_invalid(::custom_drone_interfaces::msg::StatusDataCollection::_angular_velocity_invalid_type arg)
  {
    msg_.angular_velocity_invalid = std::move(arg);
    return Init_StatusDataCollection_attitude_invalid(msg_);
  }

private:
  ::custom_drone_interfaces::msg::StatusDataCollection msg_;
};

class Init_StatusDataCollection_battery_unhealthy
{
public:
  explicit Init_StatusDataCollection_battery_unhealthy(::custom_drone_interfaces::msg::StatusDataCollection & msg)
  : msg_(msg)
  {}
  Init_StatusDataCollection_angular_velocity_invalid battery_unhealthy(::custom_drone_interfaces::msg::StatusDataCollection::_battery_unhealthy_type arg)
  {
    msg_.battery_unhealthy = std::move(arg);
    return Init_StatusDataCollection_angular_velocity_invalid(msg_);
  }

private:
  ::custom_drone_interfaces::msg::StatusDataCollection msg_;
};

class Init_StatusDataCollection_battery_warning
{
public:
  explicit Init_StatusDataCollection_battery_warning(::custom_drone_interfaces::msg::StatusDataCollection & msg)
  : msg_(msg)
  {}
  Init_StatusDataCollection_battery_unhealthy battery_warning(::custom_drone_interfaces::msg::StatusDataCollection::_battery_warning_type arg)
  {
    msg_.battery_warning = std::move(arg);
    return Init_StatusDataCollection_battery_unhealthy(msg_);
  }

private:
  ::custom_drone_interfaces::msg::StatusDataCollection msg_;
};

class Init_StatusDataCollection_time_remaining_s
{
public:
  explicit Init_StatusDataCollection_time_remaining_s(::custom_drone_interfaces::msg::StatusDataCollection & msg)
  : msg_(msg)
  {}
  Init_StatusDataCollection_battery_warning time_remaining_s(::custom_drone_interfaces::msg::StatusDataCollection::_time_remaining_s_type arg)
  {
    msg_.time_remaining_s = std::move(arg);
    return Init_StatusDataCollection_battery_warning(msg_);
  }

private:
  ::custom_drone_interfaces::msg::StatusDataCollection msg_;
};

class Init_StatusDataCollection_remaining
{
public:
  Init_StatusDataCollection_remaining()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StatusDataCollection_time_remaining_s remaining(::custom_drone_interfaces::msg::StatusDataCollection::_remaining_type arg)
  {
    msg_.remaining = std::move(arg);
    return Init_StatusDataCollection_time_remaining_s(msg_);
  }

private:
  ::custom_drone_interfaces::msg::StatusDataCollection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::msg::StatusDataCollection>()
{
  return custom_drone_interfaces::msg::builder::Init_StatusDataCollection_remaining();
}

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__STATUS_DATA_COLLECTION__BUILDER_HPP_
