#pragma once

#include <stddef.h>
#include <stdexcept>

template <typename T> struct array {
  T *arr;
  size_t length;

  array(size_t n) {
    arr = new T[n];
    length = n;
  }

  array(array<T> &anotherArr) {
    length = anotherArr.length;
    arr = new T[length];

    for (size_t i = 0; i < length; i++) {
      arr[i] = anotherArr.arr[i];
    }
  }

  array(array<T> &&anotherTempArr) {
    arr = anotherTempArr.arr;
    length = anotherTempArr.length;
    anotherTempArr.arr = nullptr;
  }

  ~array() { delete[] arr; }

  T &operator[](size_t index) {
    if (index >= length) {
      throw std::out_of_range("Out of bounds\n");
    }

    return arr[index];
  }

  array<T> &operator=(array<T> &anotherArr) {
    if (this == &anotherArr) {
      return *this;
    }

    if (arr != nullptr) {
      delete[] arr;
    }

    arr = anotherArr.arr;
    length = anotherArr.length;
    return *this;
  }

  T begin() { return arr; }

  T end() { return arr + length; }
};
