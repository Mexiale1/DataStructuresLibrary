#pragma once

template <typename T> struct Queue {
  virtual void add(const T &x) = 0;
  virtual T remove() = 0;
  virtual bool empty() const = 0;
};
