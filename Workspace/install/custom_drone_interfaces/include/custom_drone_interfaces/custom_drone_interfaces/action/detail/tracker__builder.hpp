// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_drone_interfaces:action/Tracker.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_DRONE_INTERFACES__ACTION__DETAIL__TRACKER__BUILDER_HPP_
#define CUSTOM_DRONE_INTERFACES__ACTION__DETAIL__TRACKER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_drone_interfaces/action/detail/tracker__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_drone_interfaces
{

namespace action
{

namespace builder
{

class Init_Tracker_Goal_current_waypoint
{
public:
  Init_Tracker_Goal_current_waypoint()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_drone_interfaces::action::Tracker_Goal current_waypoint(::custom_drone_interfaces::action::Tracker_Goal::_current_waypoint_type arg)
  {
    msg_.current_waypoint = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::action::Tracker_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::action::Tracker_Goal>()
{
  return custom_drone_interfaces::action::builder::Init_Tracker_Goal_current_waypoint();
}

}  // namespace custom_drone_interfaces


namespace custom_drone_interfaces
{

namespace action
{

namespace builder
{

class Init_Tracker_Result_success
{
public:
  Init_Tracker_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_drone_interfaces::action::Tracker_Result success(::custom_drone_interfaces::action::Tracker_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::action::Tracker_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::action::Tracker_Result>()
{
  return custom_drone_interfaces::action::builder::Init_Tracker_Result_success();
}

}  // namespace custom_drone_interfaces


namespace custom_drone_interfaces
{

namespace action
{

namespace builder
{

class Init_Tracker_Feedback_status_executing
{
public:
  explicit Init_Tracker_Feedback_status_executing(::custom_drone_interfaces::action::Tracker_Feedback & msg)
  : msg_(msg)
  {}
  ::custom_drone_interfaces::action::Tracker_Feedback status_executing(::custom_drone_interfaces::action::Tracker_Feedback::_status_executing_type arg)
  {
    msg_.status_executing = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::action::Tracker_Feedback msg_;
};

class Init_Tracker_Feedback_current_remaining_waypoint
{
public:
  Init_Tracker_Feedback_current_remaining_waypoint()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Tracker_Feedback_status_executing current_remaining_waypoint(::custom_drone_interfaces::action::Tracker_Feedback::_current_remaining_waypoint_type arg)
  {
    msg_.current_remaining_waypoint = std::move(arg);
    return Init_Tracker_Feedback_status_executing(msg_);
  }

private:
  ::custom_drone_interfaces::action::Tracker_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::action::Tracker_Feedback>()
{
  return custom_drone_interfaces::action::builder::Init_Tracker_Feedback_current_remaining_waypoint();
}

}  // namespace custom_drone_interfaces


namespace custom_drone_interfaces
{

namespace action
{

namespace builder
{

class Init_Tracker_SendGoal_Request_goal
{
public:
  explicit Init_Tracker_SendGoal_Request_goal(::custom_drone_interfaces::action::Tracker_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::custom_drone_interfaces::action::Tracker_SendGoal_Request goal(::custom_drone_interfaces::action::Tracker_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::action::Tracker_SendGoal_Request msg_;
};

class Init_Tracker_SendGoal_Request_goal_id
{
public:
  Init_Tracker_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Tracker_SendGoal_Request_goal goal_id(::custom_drone_interfaces::action::Tracker_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Tracker_SendGoal_Request_goal(msg_);
  }

private:
  ::custom_drone_interfaces::action::Tracker_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::action::Tracker_SendGoal_Request>()
{
  return custom_drone_interfaces::action::builder::Init_Tracker_SendGoal_Request_goal_id();
}

}  // namespace custom_drone_interfaces


namespace custom_drone_interfaces
{

namespace action
{

namespace builder
{

class Init_Tracker_SendGoal_Response_stamp
{
public:
  explicit Init_Tracker_SendGoal_Response_stamp(::custom_drone_interfaces::action::Tracker_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::custom_drone_interfaces::action::Tracker_SendGoal_Response stamp(::custom_drone_interfaces::action::Tracker_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::action::Tracker_SendGoal_Response msg_;
};

class Init_Tracker_SendGoal_Response_accepted
{
public:
  Init_Tracker_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Tracker_SendGoal_Response_stamp accepted(::custom_drone_interfaces::action::Tracker_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Tracker_SendGoal_Response_stamp(msg_);
  }

private:
  ::custom_drone_interfaces::action::Tracker_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::action::Tracker_SendGoal_Response>()
{
  return custom_drone_interfaces::action::builder::Init_Tracker_SendGoal_Response_accepted();
}

}  // namespace custom_drone_interfaces


namespace custom_drone_interfaces
{

namespace action
{

namespace builder
{

class Init_Tracker_GetResult_Request_goal_id
{
public:
  Init_Tracker_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_drone_interfaces::action::Tracker_GetResult_Request goal_id(::custom_drone_interfaces::action::Tracker_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::action::Tracker_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::action::Tracker_GetResult_Request>()
{
  return custom_drone_interfaces::action::builder::Init_Tracker_GetResult_Request_goal_id();
}

}  // namespace custom_drone_interfaces


namespace custom_drone_interfaces
{

namespace action
{

namespace builder
{

class Init_Tracker_GetResult_Response_result
{
public:
  explicit Init_Tracker_GetResult_Response_result(::custom_drone_interfaces::action::Tracker_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::custom_drone_interfaces::action::Tracker_GetResult_Response result(::custom_drone_interfaces::action::Tracker_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::action::Tracker_GetResult_Response msg_;
};

class Init_Tracker_GetResult_Response_status
{
public:
  Init_Tracker_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Tracker_GetResult_Response_result status(::custom_drone_interfaces::action::Tracker_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Tracker_GetResult_Response_result(msg_);
  }

private:
  ::custom_drone_interfaces::action::Tracker_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::action::Tracker_GetResult_Response>()
{
  return custom_drone_interfaces::action::builder::Init_Tracker_GetResult_Response_status();
}

}  // namespace custom_drone_interfaces


namespace custom_drone_interfaces
{

namespace action
{

namespace builder
{

class Init_Tracker_FeedbackMessage_feedback
{
public:
  explicit Init_Tracker_FeedbackMessage_feedback(::custom_drone_interfaces::action::Tracker_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::custom_drone_interfaces::action::Tracker_FeedbackMessage feedback(::custom_drone_interfaces::action::Tracker_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_drone_interfaces::action::Tracker_FeedbackMessage msg_;
};

class Init_Tracker_FeedbackMessage_goal_id
{
public:
  Init_Tracker_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Tracker_FeedbackMessage_feedback goal_id(::custom_drone_interfaces::action::Tracker_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Tracker_FeedbackMessage_feedback(msg_);
  }

private:
  ::custom_drone_interfaces::action::Tracker_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_drone_interfaces::action::Tracker_FeedbackMessage>()
{
  return custom_drone_interfaces::action::builder::Init_Tracker_FeedbackMessage_goal_id();
}

}  // namespace custom_drone_interfaces

#endif  // CUSTOM_DRONE_INTERFACES__ACTION__DETAIL__TRACKER__BUILDER_HPP_
