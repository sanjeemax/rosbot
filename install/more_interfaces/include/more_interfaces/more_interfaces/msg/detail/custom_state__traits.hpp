// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from more_interfaces:msg/CustomState.idl
// generated code does not contain a copyright notice

#ifndef MORE_INTERFACES__MSG__DETAIL__CUSTOM_STATE__TRAITS_HPP_
#define MORE_INTERFACES__MSG__DETAIL__CUSTOM_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "more_interfaces/msg/detail/custom_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace more_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const CustomState & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: err
  {
    out << "err: ";
    rosidl_generator_traits::value_to_yaml(msg.err, out);
    out << ", ";
  }

  // member: linear_x
  {
    out << "linear_x: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_x, out);
    out << ", ";
  }

  // member: linear_y
  {
    out << "linear_y: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_y, out);
    out << ", ";
  }

  // member: linear_z
  {
    out << "linear_z: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_z, out);
    out << ", ";
  }

  // member: angular_x
  {
    out << "angular_x: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_x, out);
    out << ", ";
  }

  // member: angular_y
  {
    out << "angular_y: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_y, out);
    out << ", ";
  }

  // member: angular_z
  {
    out << "angular_z: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CustomState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: err
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "err: ";
    rosidl_generator_traits::value_to_yaml(msg.err, out);
    out << "\n";
  }

  // member: linear_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_x: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_x, out);
    out << "\n";
  }

  // member: linear_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_y: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_y, out);
    out << "\n";
  }

  // member: linear_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_z: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_z, out);
    out << "\n";
  }

  // member: angular_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_x: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_x, out);
    out << "\n";
  }

  // member: angular_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_y: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_y, out);
    out << "\n";
  }

  // member: angular_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_z: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CustomState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace more_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use more_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const more_interfaces::msg::CustomState & msg,
  std::ostream & out, size_t indentation = 0)
{
  more_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use more_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const more_interfaces::msg::CustomState & msg)
{
  return more_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<more_interfaces::msg::CustomState>()
{
  return "more_interfaces::msg::CustomState";
}

template<>
inline const char * name<more_interfaces::msg::CustomState>()
{
  return "more_interfaces/msg/CustomState";
}

template<>
struct has_fixed_size<more_interfaces::msg::CustomState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<more_interfaces::msg::CustomState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<more_interfaces::msg::CustomState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MORE_INTERFACES__MSG__DETAIL__CUSTOM_STATE__TRAITS_HPP_
