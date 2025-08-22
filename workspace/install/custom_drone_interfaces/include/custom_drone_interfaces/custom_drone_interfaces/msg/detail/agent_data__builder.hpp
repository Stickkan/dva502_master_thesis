// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_drone_interfaces:msg/AgentData.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__MSG__DETAIL__AGENT_DATA__BUILDER_HPP_
#define CUSTOM_DRONE_INTERFACES__MSG__DETAIL__AGENT_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_drone_interfaces/msg/detail/agent_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_drone_interfaces
{

namespace msg
{

namespace builder
{

class Init_AgentData_time
{
public:
  explicit Init_AgentData_time(::custom_drone_interfaces::msg::AgentData & msg)
  : msg_(msg)
  {}
  ::custom_drone_interfaces::msg::AgentData time(::custom_drone_interfaces::msg::AgentData::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::msg::AgentData msg_;
};

class Init_AgentData_alt
{
public:
  explicit Init_AgentData_alt(::custom_drone_interfaces::msg::AgentData & msg)
  : msg_(msg)
  {}
  Init_AgentData_time alt(::custom_drone_interfaces::msg::AgentData::_alt_type arg)
  {
    msg_.alt = std::move(arg);
    return Init_AgentData_time(msg_);
  }

private:
  ::custom_drone_interfaces::msg::AgentData msg_;
};

class Init_AgentData_lon
{
public:
  explicit Init_AgentData_lon(::custom_drone_interfaces::msg::AgentData & msg)
  : msg_(msg)
  {}
  Init_AgentData_alt lon(::custom_drone_interfaces::msg::AgentData::_lon_type arg)
  {
    msg_.lon = std::move(arg);
    return Init_AgentData_alt(msg_);
  }

private:
  ::custom_drone_interfaces::msg::AgentData msg_;
};

class Init_AgentData_lat
{
public:
  explicit Init_AgentData_lat(::custom_drone_interfaces::msg::AgentData & msg)
  : msg_(msg)
  {}
  Init_AgentData_lon lat(::custom_drone_interfaces::msg::AgentData::_lat_type arg)
  {
    msg_.lat = std::move(arg);
    return Init_AgentData_lon(msg_);
  }

private:
  ::custom_drone_interfaces::msg::AgentData msg_;
};

class Init_AgentData_vz
{
public:
  explicit Init_AgentData_vz(::custom_drone_interfaces::msg::AgentData & msg)
  : msg_(msg)
  {}
  Init_AgentData_lat vz(::custom_drone_interfaces::msg::AgentData::_vz_type arg)
  {
    msg_.vz = std::move(arg);
    return Init_AgentData_lat(msg_);
  }

private:
  ::custom_drone_interfaces::msg::AgentData msg_;
};

class Init_AgentData_vy
{
public:
  explicit Init_AgentData_vy(::custom_drone_interfaces::msg::AgentData & msg)
  : msg_(msg)
  {}
  Init_AgentData_vz vy(::custom_drone_interfaces::msg::AgentData::_vy_type arg)
  {
    msg_.vy = std::move(arg);
    return Init_AgentData_vz(msg_);
  }

private:
  ::custom_drone_interfaces::msg::AgentData msg_;
};

class Init_AgentData_vx
{
public:
  explicit Init_AgentData_vx(::custom_drone_interfaces::msg::AgentData & msg)
  : msg_(msg)
  {}
  Init_AgentData_vy vx(::custom_drone_interfaces::msg::AgentData::_vx_type arg)
  {
    msg_.vx = std::move(arg);
    return Init_AgentData_vy(msg_);
  }

private:
  ::custom_drone_interfaces::msg::AgentData msg_;
};

class Init_AgentData_priority
{
public:
  explicit Init_AgentData_priority(::custom_drone_interfaces::msg::AgentData & msg)
  : msg_(msg)
  {}
  Init_AgentData_vx priority(::custom_drone_interfaces::msg::AgentData::_priority_type arg)
  {
    msg_.priority = std::move(arg);
    return Init_AgentData_vx(msg_);
  }

private:
  ::custom_drone_interfaces::msg::AgentData msg_;
};

class Init_AgentData_agentid
{
public:
  Init_AgentData_agentid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AgentData_priority agentid(::custom_drone_interfaces::msg::AgentData::_agentid_type arg)
  {
    msg_.agentid = std::move(arg);
    return Init_AgentData_priority(msg_);
  }

private:
  ::custom_drone_interfaces::msg::AgentData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::msg::AgentData>()
{
  return custom_drone_interfaces::msg::builder::Init_AgentData_agentid();
}

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__MSG__DETAIL__AGENT_DATA__BUILDER_HPP_
