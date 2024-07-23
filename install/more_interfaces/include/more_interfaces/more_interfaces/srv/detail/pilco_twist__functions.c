// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from more_interfaces:srv/PilcoTwist.idl
// generated code does not contain a copyright notice
#include "more_interfaces/srv/detail/pilco_twist__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
more_interfaces__srv__PilcoTwist_Request__init(more_interfaces__srv__PilcoTwist_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
more_interfaces__srv__PilcoTwist_Request__fini(more_interfaces__srv__PilcoTwist_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
more_interfaces__srv__PilcoTwist_Request__are_equal(const more_interfaces__srv__PilcoTwist_Request * lhs, const more_interfaces__srv__PilcoTwist_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
more_interfaces__srv__PilcoTwist_Request__copy(
  const more_interfaces__srv__PilcoTwist_Request * input,
  more_interfaces__srv__PilcoTwist_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

more_interfaces__srv__PilcoTwist_Request *
more_interfaces__srv__PilcoTwist_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  more_interfaces__srv__PilcoTwist_Request * msg = (more_interfaces__srv__PilcoTwist_Request *)allocator.allocate(sizeof(more_interfaces__srv__PilcoTwist_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(more_interfaces__srv__PilcoTwist_Request));
  bool success = more_interfaces__srv__PilcoTwist_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
more_interfaces__srv__PilcoTwist_Request__destroy(more_interfaces__srv__PilcoTwist_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    more_interfaces__srv__PilcoTwist_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
more_interfaces__srv__PilcoTwist_Request__Sequence__init(more_interfaces__srv__PilcoTwist_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  more_interfaces__srv__PilcoTwist_Request * data = NULL;

  if (size) {
    data = (more_interfaces__srv__PilcoTwist_Request *)allocator.zero_allocate(size, sizeof(more_interfaces__srv__PilcoTwist_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = more_interfaces__srv__PilcoTwist_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        more_interfaces__srv__PilcoTwist_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
more_interfaces__srv__PilcoTwist_Request__Sequence__fini(more_interfaces__srv__PilcoTwist_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      more_interfaces__srv__PilcoTwist_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

more_interfaces__srv__PilcoTwist_Request__Sequence *
more_interfaces__srv__PilcoTwist_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  more_interfaces__srv__PilcoTwist_Request__Sequence * array = (more_interfaces__srv__PilcoTwist_Request__Sequence *)allocator.allocate(sizeof(more_interfaces__srv__PilcoTwist_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = more_interfaces__srv__PilcoTwist_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
more_interfaces__srv__PilcoTwist_Request__Sequence__destroy(more_interfaces__srv__PilcoTwist_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    more_interfaces__srv__PilcoTwist_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
more_interfaces__srv__PilcoTwist_Request__Sequence__are_equal(const more_interfaces__srv__PilcoTwist_Request__Sequence * lhs, const more_interfaces__srv__PilcoTwist_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!more_interfaces__srv__PilcoTwist_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
more_interfaces__srv__PilcoTwist_Request__Sequence__copy(
  const more_interfaces__srv__PilcoTwist_Request__Sequence * input,
  more_interfaces__srv__PilcoTwist_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(more_interfaces__srv__PilcoTwist_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    more_interfaces__srv__PilcoTwist_Request * data =
      (more_interfaces__srv__PilcoTwist_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!more_interfaces__srv__PilcoTwist_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          more_interfaces__srv__PilcoTwist_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!more_interfaces__srv__PilcoTwist_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
more_interfaces__srv__PilcoTwist_Response__init(more_interfaces__srv__PilcoTwist_Response * msg)
{
  if (!msg) {
    return false;
  }
  // linx
  // revz
  return true;
}

void
more_interfaces__srv__PilcoTwist_Response__fini(more_interfaces__srv__PilcoTwist_Response * msg)
{
  if (!msg) {
    return;
  }
  // linx
  // revz
}

bool
more_interfaces__srv__PilcoTwist_Response__are_equal(const more_interfaces__srv__PilcoTwist_Response * lhs, const more_interfaces__srv__PilcoTwist_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // linx
  if (lhs->linx != rhs->linx) {
    return false;
  }
  // revz
  if (lhs->revz != rhs->revz) {
    return false;
  }
  return true;
}

bool
more_interfaces__srv__PilcoTwist_Response__copy(
  const more_interfaces__srv__PilcoTwist_Response * input,
  more_interfaces__srv__PilcoTwist_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // linx
  output->linx = input->linx;
  // revz
  output->revz = input->revz;
  return true;
}

more_interfaces__srv__PilcoTwist_Response *
more_interfaces__srv__PilcoTwist_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  more_interfaces__srv__PilcoTwist_Response * msg = (more_interfaces__srv__PilcoTwist_Response *)allocator.allocate(sizeof(more_interfaces__srv__PilcoTwist_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(more_interfaces__srv__PilcoTwist_Response));
  bool success = more_interfaces__srv__PilcoTwist_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
more_interfaces__srv__PilcoTwist_Response__destroy(more_interfaces__srv__PilcoTwist_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    more_interfaces__srv__PilcoTwist_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
more_interfaces__srv__PilcoTwist_Response__Sequence__init(more_interfaces__srv__PilcoTwist_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  more_interfaces__srv__PilcoTwist_Response * data = NULL;

  if (size) {
    data = (more_interfaces__srv__PilcoTwist_Response *)allocator.zero_allocate(size, sizeof(more_interfaces__srv__PilcoTwist_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = more_interfaces__srv__PilcoTwist_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        more_interfaces__srv__PilcoTwist_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
more_interfaces__srv__PilcoTwist_Response__Sequence__fini(more_interfaces__srv__PilcoTwist_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      more_interfaces__srv__PilcoTwist_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

more_interfaces__srv__PilcoTwist_Response__Sequence *
more_interfaces__srv__PilcoTwist_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  more_interfaces__srv__PilcoTwist_Response__Sequence * array = (more_interfaces__srv__PilcoTwist_Response__Sequence *)allocator.allocate(sizeof(more_interfaces__srv__PilcoTwist_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = more_interfaces__srv__PilcoTwist_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
more_interfaces__srv__PilcoTwist_Response__Sequence__destroy(more_interfaces__srv__PilcoTwist_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    more_interfaces__srv__PilcoTwist_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
more_interfaces__srv__PilcoTwist_Response__Sequence__are_equal(const more_interfaces__srv__PilcoTwist_Response__Sequence * lhs, const more_interfaces__srv__PilcoTwist_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!more_interfaces__srv__PilcoTwist_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
more_interfaces__srv__PilcoTwist_Response__Sequence__copy(
  const more_interfaces__srv__PilcoTwist_Response__Sequence * input,
  more_interfaces__srv__PilcoTwist_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(more_interfaces__srv__PilcoTwist_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    more_interfaces__srv__PilcoTwist_Response * data =
      (more_interfaces__srv__PilcoTwist_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!more_interfaces__srv__PilcoTwist_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          more_interfaces__srv__PilcoTwist_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!more_interfaces__srv__PilcoTwist_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "more_interfaces/srv/detail/pilco_twist__functions.h"

bool
more_interfaces__srv__PilcoTwist_Event__init(more_interfaces__srv__PilcoTwist_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    more_interfaces__srv__PilcoTwist_Event__fini(msg);
    return false;
  }
  // request
  if (!more_interfaces__srv__PilcoTwist_Request__Sequence__init(&msg->request, 0)) {
    more_interfaces__srv__PilcoTwist_Event__fini(msg);
    return false;
  }
  // response
  if (!more_interfaces__srv__PilcoTwist_Response__Sequence__init(&msg->response, 0)) {
    more_interfaces__srv__PilcoTwist_Event__fini(msg);
    return false;
  }
  return true;
}

void
more_interfaces__srv__PilcoTwist_Event__fini(more_interfaces__srv__PilcoTwist_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  more_interfaces__srv__PilcoTwist_Request__Sequence__fini(&msg->request);
  // response
  more_interfaces__srv__PilcoTwist_Response__Sequence__fini(&msg->response);
}

bool
more_interfaces__srv__PilcoTwist_Event__are_equal(const more_interfaces__srv__PilcoTwist_Event * lhs, const more_interfaces__srv__PilcoTwist_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!more_interfaces__srv__PilcoTwist_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!more_interfaces__srv__PilcoTwist_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
more_interfaces__srv__PilcoTwist_Event__copy(
  const more_interfaces__srv__PilcoTwist_Event * input,
  more_interfaces__srv__PilcoTwist_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!more_interfaces__srv__PilcoTwist_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!more_interfaces__srv__PilcoTwist_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

more_interfaces__srv__PilcoTwist_Event *
more_interfaces__srv__PilcoTwist_Event__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  more_interfaces__srv__PilcoTwist_Event * msg = (more_interfaces__srv__PilcoTwist_Event *)allocator.allocate(sizeof(more_interfaces__srv__PilcoTwist_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(more_interfaces__srv__PilcoTwist_Event));
  bool success = more_interfaces__srv__PilcoTwist_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
more_interfaces__srv__PilcoTwist_Event__destroy(more_interfaces__srv__PilcoTwist_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    more_interfaces__srv__PilcoTwist_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
more_interfaces__srv__PilcoTwist_Event__Sequence__init(more_interfaces__srv__PilcoTwist_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  more_interfaces__srv__PilcoTwist_Event * data = NULL;

  if (size) {
    data = (more_interfaces__srv__PilcoTwist_Event *)allocator.zero_allocate(size, sizeof(more_interfaces__srv__PilcoTwist_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = more_interfaces__srv__PilcoTwist_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        more_interfaces__srv__PilcoTwist_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
more_interfaces__srv__PilcoTwist_Event__Sequence__fini(more_interfaces__srv__PilcoTwist_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      more_interfaces__srv__PilcoTwist_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

more_interfaces__srv__PilcoTwist_Event__Sequence *
more_interfaces__srv__PilcoTwist_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  more_interfaces__srv__PilcoTwist_Event__Sequence * array = (more_interfaces__srv__PilcoTwist_Event__Sequence *)allocator.allocate(sizeof(more_interfaces__srv__PilcoTwist_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = more_interfaces__srv__PilcoTwist_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
more_interfaces__srv__PilcoTwist_Event__Sequence__destroy(more_interfaces__srv__PilcoTwist_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    more_interfaces__srv__PilcoTwist_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
more_interfaces__srv__PilcoTwist_Event__Sequence__are_equal(const more_interfaces__srv__PilcoTwist_Event__Sequence * lhs, const more_interfaces__srv__PilcoTwist_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!more_interfaces__srv__PilcoTwist_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
more_interfaces__srv__PilcoTwist_Event__Sequence__copy(
  const more_interfaces__srv__PilcoTwist_Event__Sequence * input,
  more_interfaces__srv__PilcoTwist_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(more_interfaces__srv__PilcoTwist_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    more_interfaces__srv__PilcoTwist_Event * data =
      (more_interfaces__srv__PilcoTwist_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!more_interfaces__srv__PilcoTwist_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          more_interfaces__srv__PilcoTwist_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!more_interfaces__srv__PilcoTwist_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
