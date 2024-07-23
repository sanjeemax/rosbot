// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from more_interfaces:msg/CustomState.idl
// generated code does not contain a copyright notice

#ifndef MORE_INTERFACES__MSG__DETAIL__CUSTOM_STATE__STRUCT_H_
#define MORE_INTERFACES__MSG__DETAIL__CUSTOM_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/CustomState in the package more_interfaces.
/**
  * msg/CustomState.msg
 */
typedef struct more_interfaces__msg__CustomState
{
  int32_t id;
  double err;
  double linear_x;
  double linear_y;
  double linear_z;
  double angular_x;
  double angular_y;
  double angular_z;
} more_interfaces__msg__CustomState;

// Struct for a sequence of more_interfaces__msg__CustomState.
typedef struct more_interfaces__msg__CustomState__Sequence
{
  more_interfaces__msg__CustomState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} more_interfaces__msg__CustomState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MORE_INTERFACES__MSG__DETAIL__CUSTOM_STATE__STRUCT_H_
