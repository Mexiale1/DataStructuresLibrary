#pragma once

#include <stddef.h>

template <typename T> struct array {
  T *x;
  size_t length;
};
