// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from more_interfaces:msg/CustomState.idl
// generated code does not contain a copyright notice

#include "more_interfaces/msg/detail/custom_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_more_interfaces
const rosidl_type_hash_t *
more_interfaces__msg__CustomState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xaf, 0x18, 0x42, 0xc5, 0x59, 0x5b, 0x99, 0x58,
      0x2f, 0x2e, 0x65, 0x29, 0xf2, 0xb0, 0x15, 0xa8,
      0xe3, 0x03, 0xeb, 0x69, 0xa3, 0x45, 0x35, 0x14,
      0x56, 0x53, 0x5c, 0x0e, 0x59, 0xfa, 0xb7, 0x0e,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char more_interfaces__msg__CustomState__TYPE_NAME[] = "more_interfaces/msg/CustomState";

// Define type names, field names, and default values
static char more_interfaces__msg__CustomState__FIELD_NAME__id[] = "id";
static char more_interfaces__msg__CustomState__FIELD_NAME__err[] = "err";
static char more_interfaces__msg__CustomState__FIELD_NAME__linear_x[] = "linear_x";
static char more_interfaces__msg__CustomState__FIELD_NAME__linear_y[] = "linear_y";
static char more_interfaces__msg__CustomState__FIELD_NAME__linear_z[] = "linear_z";
static char more_interfaces__msg__CustomState__FIELD_NAME__angular_x[] = "angular_x";
static char more_interfaces__msg__CustomState__FIELD_NAME__angular_y[] = "angular_y";
static char more_interfaces__msg__CustomState__FIELD_NAME__angular_z[] = "angular_z";

static rosidl_runtime_c__type_description__Field more_interfaces__msg__CustomState__FIELDS[] = {
  {
    {more_interfaces__msg__CustomState__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {more_interfaces__msg__CustomState__FIELD_NAME__err, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {more_interfaces__msg__CustomState__FIELD_NAME__linear_x, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {more_interfaces__msg__CustomState__FIELD_NAME__linear_y, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {more_interfaces__msg__CustomState__FIELD_NAME__linear_z, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {more_interfaces__msg__CustomState__FIELD_NAME__angular_x, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {more_interfaces__msg__CustomState__FIELD_NAME__angular_y, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {more_interfaces__msg__CustomState__FIELD_NAME__angular_z, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
more_interfaces__msg__CustomState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {more_interfaces__msg__CustomState__TYPE_NAME, 31, 31},
      {more_interfaces__msg__CustomState__FIELDS, 8, 8},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# msg/CustomState.msg\n"
  "int32 id\n"
  "float64 err\n"
  "float64 linear_x\n"
  "float64 linear_y\n"
  "float64 linear_z\n"
  "float64 angular_x\n"
  "float64 angular_y\n"
  "float64 angular_z";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
more_interfaces__msg__CustomState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {more_interfaces__msg__CustomState__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 148, 148},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
more_interfaces__msg__CustomState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *more_interfaces__msg__CustomState__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
