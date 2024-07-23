// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from more_interfaces:srv/PilcoTwist.idl
// generated code does not contain a copyright notice

#ifndef MORE_INTERFACES__SRV__DETAIL__PILCO_TWIST__BUILDER_HPP_
#define MORE_INTERFACES__SRV__DETAIL__PILCO_TWIST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "more_interfaces/srv/detail/pilco_twist__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace more_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::more_interfaces::srv::PilcoTwist_Request>()
{
  return ::more_interfaces::srv::PilcoTwist_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace more_interfaces


namespace more_interfaces
{

namespace srv
{

namespace builder
{

class Init_PilcoTwist_Response_revz
{
public:
  explicit Init_PilcoTwist_Response_revz(::more_interfaces::srv::PilcoTwist_Response & msg)
  : msg_(msg)
  {}
  ::more_interfaces::srv::PilcoTwist_Response revz(::more_interfaces::srv::PilcoTwist_Response::_revz_type arg)
  {
    msg_.revz = std::move(arg);
    return std::move(msg_);
  }

private:
  ::more_interfaces::srv::PilcoTwist_Response msg_;
};

class Init_PilcoTwist_Response_linx
{
public:
  Init_PilcoTwist_Response_linx()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PilcoTwist_Response_revz linx(::more_interfaces::srv::PilcoTwist_Response::_linx_type arg)
  {
    msg_.linx = std::move(arg);
    return Init_PilcoTwist_Response_revz(msg_);
  }

private:
  ::more_interfaces::srv::PilcoTwist_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::more_interfaces::srv::PilcoTwist_Response>()
{
  return more_interfaces::srv::builder::Init_PilcoTwist_Response_linx();
}

}  // namespace more_interfaces


namespace more_interfaces
{

namespace srv
{

namespace builder
{

class Init_PilcoTwist_Event_response
{
public:
  explicit Init_PilcoTwist_Event_response(::more_interfaces::srv::PilcoTwist_Event & msg)
  : msg_(msg)
  {}
  ::more_interfaces::srv::PilcoTwist_Event response(::more_interfaces::srv::PilcoTwist_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::more_interfaces::srv::PilcoTwist_Event msg_;
};

class Init_PilcoTwist_Event_request
{
public:
  explicit Init_PilcoTwist_Event_request(::more_interfaces::srv::PilcoTwist_Event & msg)
  : msg_(msg)
  {}
  Init_PilcoTwist_Event_response request(::more_interfaces::srv::PilcoTwist_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_PilcoTwist_Event_response(msg_);
  }

private:
  ::more_interfaces::srv::PilcoTwist_Event msg_;
};

class Init_PilcoTwist_Event_info
{
public:
  Init_PilcoTwist_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PilcoTwist_Event_request info(::more_interfaces::srv::PilcoTwist_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_PilcoTwist_Event_request(msg_);
  }

private:
  ::more_interfaces::srv::PilcoTwist_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::more_interfaces::srv::PilcoTwist_Event>()
{
  return more_interfaces::srv::builder::Init_PilcoTwist_Event_info();
}

}  // namespace more_interfaces

#endif  // MORE_INTERFACES__SRV__DETAIL__PILCO_TWIST__BUILDER_HPP_
