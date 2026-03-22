#pragma once

#include <stddef.h>
#include <stdexcept>

template <typename T> struct array {
  // Attributes
  T *arr;
  size_t length;

  // Default Contructor
  array() : arr(nullptr), length(0) {}

  array(size_t n) {
    arr = new T[n];
    length = n;
  }

  // Rule of Five
  // Copy & Move Construtors

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
    anotherTempArr.length = 0;
  }

  // Copy & Move Operator overload

  array<T> &operator=(array<T> &anotherArr) {
    if (this == &anotherArr) {
      return *this;
    }

    if (arr != nullptr) {
      delete[] arr;
    }

    length = anotherArr.length;
    arr = new T[length];

    for (size_t i = 0; i < length; i++) {
      arr[i] = anotherArr.arr[i];
    }

    return *this;
  }

  array<T> &operator=(array<T> &&anotherArr) {
    if (this == &anotherArr) {
      return *this;
    }

    if (arr != nullptr) {
      delete[] arr;
    }

    arr = anotherArr.arr;
    anotherArr.arr = nullptr;
    length = anotherArr.length;
    anotherArr.length = 0;
    return *this;
  }

  // Destructor
  ~array() { delete[] arr; }

  // Indexing operators
  T &operator[](size_t index) {
    if (index >= length) {
      throw std::out_of_range("Out of bounds\n");
    }
    return arr[index];
  }

  const T &operator[](size_t index) const {
    if (index >= length) {
      throw std::out_of_range("Out of bounds\n");
    }
    return arr[index];
  }

  // First and Last element methods;
  T *begin() { return arr; }
  T *end() { return arr + length; }

  const T *begin() const { return arr; }
  const T *end() const { return arr + length; }
};
