// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_drone_interfaces:msg/Waypoint.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__WAYPOINT__BUILDER_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__WAYPOINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_drone_interfaces/msg/detail/waypoint__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_drone_interfaces
{

namespace msg
{

namespace builder
{

class Init_Waypoint_commandid
{
public:
  explicit Init_Waypoint_commandid(::custom_drone_interfaces::msg::Waypoint & msg)
  : msg_(msg)
  {}
  ::custom_drone_interfaces::msg::Waypoint commandid(::custom_drone_interfaces::msg::Waypoint::_commandid_type arg)
  {
    msg_.commandid = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::msg::Waypoint msg_;
};

class Init_Waypoint_task
{
public:
  explicit Init_Waypoint_task(::custom_drone_interfaces::msg::Waypoint & msg)
  : msg_(msg)
  {}
  Init_Waypoint_commandid task(::custom_drone_interfaces::msg::Waypoint::_task_type arg)
  {
    msg_.task = std::move(arg);
    return Init_Waypoint_commandid(msg_);
  }

private:
  ::custom_drone_interfaces::msg::Waypoint msg_;
};

class Init_Waypoint_acceptence_radius
{
public:
  explicit Init_Waypoint_acceptence_radius(::custom_drone_interfaces::msg::Waypoint & msg)
  : msg_(msg)
  {}
  Init_Waypoint_task acceptence_radius(::custom_drone_interfaces::msg::Waypoint::_acceptence_radius_type arg)
  {
    msg_.acceptence_radius = std::move(arg);
    return Init_Waypoint_task(msg_);
  }

private:
  ::custom_drone_interfaces::msg::Waypoint msg_;
};

class Init_Waypoint_hold_time
{
public:
  explicit Init_Waypoint_hold_time(::custom_drone_interfaces::msg::Waypoint & msg)
  : msg_(msg)
  {}
  Init_Waypoint_acceptence_radius hold_time(::custom_drone_interfaces::msg::Waypoint::_hold_time_type arg)
  {
    msg_.hold_time = std::move(arg);
    return Init_Waypoint_acceptence_radius(msg_);
  }

private:
  ::custom_drone_interfaces::msg::Waypoint msg_;
};

class Init_Waypoint_time_in_seconds
{
public:
  explicit Init_Waypoint_time_in_seconds(::custom_drone_interfaces::msg::Waypoint & msg)
  : msg_(msg)
  {}
  Init_Waypoint_hold_time time_in_seconds(::custom_drone_interfaces::msg::Waypoint::_time_in_seconds_type arg)
  {
    msg_.time_in_seconds = std::move(arg);
    return Init_Waypoint_hold_time(msg_);
  }

private:
  ::custom_drone_interfaces::msg::Waypoint msg_;
};

class Init_Waypoint_heading
{
public:
  explicit Init_Waypoint_heading(::custom_drone_interfaces::msg::Waypoint & msg)
  : msg_(msg)
  {}
  Init_Waypoint_time_in_seconds heading(::custom_drone_interfaces::msg::Waypoint::_heading_type arg)
  {
    msg_.heading = std::move(arg);
    return Init_Waypoint_time_in_seconds(msg_);
  }

private:
  ::custom_drone_interfaces::msg::Waypoint msg_;
};

class Init_Waypoint_stop
{
public:
  explicit Init_Waypoint_stop(::custom_drone_interfaces::msg::Waypoint & msg)
  : msg_(msg)
  {}
  Init_Waypoint_heading stop(::custom_drone_interfaces::msg::Waypoint::_stop_type arg)
  {
    msg_.stop = std::move(arg);
    return Init_Waypoint_heading(msg_);
  }

private:
  ::custom_drone_interfaces::msg::Waypoint msg_;
};

class Init_Waypoint_subtrajectory
{
public:
  explicit Init_Waypoint_subtrajectory(::custom_drone_interfaces::msg::Waypoint & msg)
  : msg_(msg)
  {}
  Init_Waypoint_stop subtrajectory(::custom_drone_interfaces::msg::Waypoint::_subtrajectory_type arg)
  {
    msg_.subtrajectory = std::move(arg);
    return Init_Waypoint_stop(msg_);
  }

private:
  ::custom_drone_interfaces::msg::Waypoint msg_;
};

class Init_Waypoint_velocity
{
public:
  explicit Init_Waypoint_velocity(::custom_drone_interfaces::msg::Waypoint & msg)
  : msg_(msg)
  {}
  Init_Waypoint_subtrajectory velocity(::custom_drone_interfaces::msg::Waypoint::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_Waypoint_subtrajectory(msg_);
  }

private:
  ::custom_drone_interfaces::msg::Waypoint msg_;
};

class Init_Waypoint_point
{
public:
  Init_Waypoint_point()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Waypoint_velocity point(::custom_drone_interfaces::msg::Waypoint::_point_type arg)
  {
    msg_.point = std::move(arg);
    return Init_Waypoint_velocity(msg_);
  }

private:
  ::custom_drone_interfaces::msg::Waypoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::msg::Waypoint>()
{
  return custom_drone_interfaces::msg::builder::Init_Waypoint_point();
}

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__WAYPOINT__BUILDER_HPP_
