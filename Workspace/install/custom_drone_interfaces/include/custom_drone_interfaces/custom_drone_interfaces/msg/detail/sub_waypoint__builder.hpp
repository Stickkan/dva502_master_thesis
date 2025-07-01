// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_drone_interfaces:msg/SubWaypoint.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SUB_WAYPOINT__BUILDER_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SUB_WAYPOINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_drone_interfaces/msg/detail/sub_waypoint__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_drone_interfaces
{

namespace msg
{

namespace builder
{

class Init_SubWaypoint_time_sec
{
public:
  explicit Init_SubWaypoint_time_sec(::custom_drone_interfaces::msg::SubWaypoint & msg)
  : msg_(msg)
  {}
  ::custom_drone_interfaces::msg::SubWaypoint time_sec(::custom_drone_interfaces::msg::SubWaypoint::_time_sec_type arg)
  {
    msg_.time_sec = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SubWaypoint msg_;
};

class Init_SubWaypoint_heading
{
public:
  explicit Init_SubWaypoint_heading(::custom_drone_interfaces::msg::SubWaypoint & msg)
  : msg_(msg)
  {}
  Init_SubWaypoint_time_sec heading(::custom_drone_interfaces::msg::SubWaypoint::_heading_type arg)
  {
    msg_.heading = std::move(arg);
    return Init_SubWaypoint_time_sec(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SubWaypoint msg_;
};

class Init_SubWaypoint_acceleration
{
public:
  explicit Init_SubWaypoint_acceleration(::custom_drone_interfaces::msg::SubWaypoint & msg)
  : msg_(msg)
  {}
  Init_SubWaypoint_heading acceleration(::custom_drone_interfaces::msg::SubWaypoint::_acceleration_type arg)
  {
    msg_.acceleration = std::move(arg);
    return Init_SubWaypoint_heading(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SubWaypoint msg_;
};

class Init_SubWaypoint_velocity
{
public:
  explicit Init_SubWaypoint_velocity(::custom_drone_interfaces::msg::SubWaypoint & msg)
  : msg_(msg)
  {}
  Init_SubWaypoint_acceleration velocity(::custom_drone_interfaces::msg::SubWaypoint::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_SubWaypoint_acceleration(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SubWaypoint msg_;
};

class Init_SubWaypoint_point
{
public:
  Init_SubWaypoint_point()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SubWaypoint_velocity point(::custom_drone_interfaces::msg::SubWaypoint::_point_type arg)
  {
    msg_.point = std::move(arg);
    return Init_SubWaypoint_velocity(msg_);
  }

private:
  ::custom_drone_interfaces::msg::SubWaypoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::msg::SubWaypoint>()
{
  return custom_drone_interfaces::msg::builder::Init_SubWaypoint_point();
}

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__SUB_WAYPOINT__BUILDER_HPP_
