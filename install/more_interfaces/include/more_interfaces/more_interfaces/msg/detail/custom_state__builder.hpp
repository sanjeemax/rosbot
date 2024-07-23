// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from more_interfaces:msg/CustomState.idl
// generated code does not contain a copyright notice

#ifndef MORE_INTERFACES__MSG__DETAIL__CUSTOM_STATE__BUILDER_HPP_
#define MORE_INTERFACES__MSG__DETAIL__CUSTOM_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "more_interfaces/msg/detail/custom_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace more_interfaces
{

namespace msg
{

namespace builder
{

class Init_CustomState_angular_z
{
public:
  explicit Init_CustomState_angular_z(::more_interfaces::msg::CustomState & msg)
  : msg_(msg)
  {}
  ::more_interfaces::msg::CustomState angular_z(::more_interfaces::msg::CustomState::_angular_z_type arg)
  {
    msg_.angular_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::more_interfaces::msg::CustomState msg_;
};

class Init_CustomState_angular_y
{
public:
  explicit Init_CustomState_angular_y(::more_interfaces::msg::CustomState & msg)
  : msg_(msg)
  {}
  Init_CustomState_angular_z angular_y(::more_interfaces::msg::CustomState::_angular_y_type arg)
  {
    msg_.angular_y = std::move(arg);
    return Init_CustomState_angular_z(msg_);
  }

private:
  ::more_interfaces::msg::CustomState msg_;
};

class Init_CustomState_angular_x
{
public:
  explicit Init_CustomState_angular_x(::more_interfaces::msg::CustomState & msg)
  : msg_(msg)
  {}
  Init_CustomState_angular_y angular_x(::more_interfaces::msg::CustomState::_angular_x_type arg)
  {
    msg_.angular_x = std::move(arg);
    return Init_CustomState_angular_y(msg_);
  }

private:
  ::more_interfaces::msg::CustomState msg_;
};

class Init_CustomState_linear_z
{
public:
  explicit Init_CustomState_linear_z(::more_interfaces::msg::CustomState & msg)
  : msg_(msg)
  {}
  Init_CustomState_angular_x linear_z(::more_interfaces::msg::CustomState::_linear_z_type arg)
  {
    msg_.linear_z = std::move(arg);
    return Init_CustomState_angular_x(msg_);
  }

private:
  ::more_interfaces::msg::CustomState msg_;
};

class Init_CustomState_linear_y
{
public:
  explicit Init_CustomState_linear_y(::more_interfaces::msg::CustomState & msg)
  : msg_(msg)
  {}
  Init_CustomState_linear_z linear_y(::more_interfaces::msg::CustomState::_linear_y_type arg)
  {
    msg_.linear_y = std::move(arg);
    return Init_CustomState_linear_z(msg_);
  }

private:
  ::more_interfaces::msg::CustomState msg_;
};

class Init_CustomState_linear_x
{
public:
  explicit Init_CustomState_linear_x(::more_interfaces::msg::CustomState & msg)
  : msg_(msg)
  {}
  Init_CustomState_linear_y linear_x(::more_interfaces::msg::CustomState::_linear_x_type arg)
  {
    msg_.linear_x = std::move(arg);
    return Init_CustomState_linear_y(msg_);
  }

private:
  ::more_interfaces::msg::CustomState msg_;
};

class Init_CustomState_err
{
public:
  explicit Init_CustomState_err(::more_interfaces::msg::CustomState & msg)
  : msg_(msg)
  {}
  Init_CustomState_linear_x err(::more_interfaces::msg::CustomState::_err_type arg)
  {
    msg_.err = std::move(arg);
    return Init_CustomState_linear_x(msg_);
  }

private:
  ::more_interfaces::msg::CustomState msg_;
};

class Init_CustomState_id
{
public:
  Init_CustomState_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CustomState_err id(::more_interfaces::msg::CustomState::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_CustomState_err(msg_);
  }

private:
  ::more_interfaces::msg::CustomState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::more_interfaces::msg::CustomState>()
{
  return more_interfaces::msg::builder::Init_CustomState_id();
}

}  // namespace more_interfaces

#endif  // MORE_INTERFACES__MSG__DETAIL__CUSTOM_STATE__BUILDER_HPP_
