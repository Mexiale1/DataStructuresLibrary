#pragma once

#include <stddef.h>

template <typename T> struct SortedSet {
  virtual size_t size() const = 0;
  virtual bool add(const T &x) = 0;
  virtual T remove(const T &x) = 0;
  virtual T find(const T &x) const = 0;
  virtual void compare(T &x, T &y) = 0;
};
