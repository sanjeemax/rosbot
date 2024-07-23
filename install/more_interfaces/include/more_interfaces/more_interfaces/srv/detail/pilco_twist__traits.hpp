// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from more_interfaces:srv/PilcoTwist.idl
// generated code does not contain a copyright notice

#ifndef MORE_INTERFACES__SRV__DETAIL__PILCO_TWIST__TRAITS_HPP_
#define MORE_INTERFACES__SRV__DETAIL__PILCO_TWIST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "more_interfaces/srv/detail/pilco_twist__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace more_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PilcoTwist_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PilcoTwist_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PilcoTwist_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace more_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use more_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const more_interfaces::srv::PilcoTwist_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  more_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use more_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const more_interfaces::srv::PilcoTwist_Request & msg)
{
  return more_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<more_interfaces::srv::PilcoTwist_Request>()
{
  return "more_interfaces::srv::PilcoTwist_Request";
}

template<>
inline const char * name<more_interfaces::srv::PilcoTwist_Request>()
{
  return "more_interfaces/srv/PilcoTwist_Request";
}

template<>
struct has_fixed_size<more_interfaces::srv::PilcoTwist_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<more_interfaces::srv::PilcoTwist_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<more_interfaces::srv::PilcoTwist_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace more_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PilcoTwist_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: linx
  {
    out << "linx: ";
    rosidl_generator_traits::value_to_yaml(msg.linx, out);
    out << ", ";
  }

  // member: revz
  {
    out << "revz: ";
    rosidl_generator_traits::value_to_yaml(msg.revz, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PilcoTwist_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: linx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linx: ";
    rosidl_generator_traits::value_to_yaml(msg.linx, out);
    out << "\n";
  }

  // member: revz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "revz: ";
    rosidl_generator_traits::value_to_yaml(msg.revz, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PilcoTwist_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace more_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use more_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const more_interfaces::srv::PilcoTwist_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  more_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use more_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const more_interfaces::srv::PilcoTwist_Response & msg)
{
  return more_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<more_interfaces::srv::PilcoTwist_Response>()
{
  return "more_interfaces::srv::PilcoTwist_Response";
}

template<>
inline const char * name<more_interfaces::srv::PilcoTwist_Response>()
{
  return "more_interfaces/srv/PilcoTwist_Response";
}

template<>
struct has_fixed_size<more_interfaces::srv::PilcoTwist_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<more_interfaces::srv::PilcoTwist_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<more_interfaces::srv::PilcoTwist_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace more_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PilcoTwist_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PilcoTwist_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PilcoTwist_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace more_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use more_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const more_interfaces::srv::PilcoTwist_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  more_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use more_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const more_interfaces::srv::PilcoTwist_Event & msg)
{
  return more_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<more_interfaces::srv::PilcoTwist_Event>()
{
  return "more_interfaces::srv::PilcoTwist_Event";
}

template<>
inline const char * name<more_interfaces::srv::PilcoTwist_Event>()
{
  return "more_interfaces/srv/PilcoTwist_Event";
}

template<>
struct has_fixed_size<more_interfaces::srv::PilcoTwist_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<more_interfaces::srv::PilcoTwist_Event>
  : std::integral_constant<bool, has_bounded_size<more_interfaces::srv::PilcoTwist_Request>::value && has_bounded_size<more_interfaces::srv::PilcoTwist_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<more_interfaces::srv::PilcoTwist_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<more_interfaces::srv::PilcoTwist>()
{
  return "more_interfaces::srv::PilcoTwist";
}

template<>
inline const char * name<more_interfaces::srv::PilcoTwist>()
{
  return "more_interfaces/srv/PilcoTwist";
}

template<>
struct has_fixed_size<more_interfaces::srv::PilcoTwist>
  : std::integral_constant<
    bool,
    has_fixed_size<more_interfaces::srv::PilcoTwist_Request>::value &&
    has_fixed_size<more_interfaces::srv::PilcoTwist_Response>::value
  >
{
};

template<>
struct has_bounded_size<more_interfaces::srv::PilcoTwist>
  : std::integral_constant<
    bool,
    has_bounded_size<more_interfaces::srv::PilcoTwist_Request>::value &&
    has_bounded_size<more_interfaces::srv::PilcoTwist_Response>::value
  >
{
};

template<>
struct is_service<more_interfaces::srv::PilcoTwist>
  : std::true_type
{
};

template<>
struct is_service_request<more_interfaces::srv::PilcoTwist_Request>
  : std::true_type
{
};

template<>
struct is_service_response<more_interfaces::srv::PilcoTwist_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MORE_INTERFACES__SRV__DETAIL__PILCO_TWIST__TRAITS_HPP_
