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

  array(const array<T> &anotherArr) {
    length = anotherArr.length;
    arr = new T[length];

    for (size_t i = 0; i < length; i++) {
      arr[i] = anotherArr.arr[i];
    }
  }

  array(array<T> &&anotherTempArr) noexcept {
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

<<<<<<< HEAD
  array<T> &operator=(array<T> &anotherArr) {
    if (this == &anotherArr) return *this;
=======
  const T &operator[](size_t index) const {
    if (index >= length) {
      throw std::out_of_range("Out of bounds\n");
    }

    return arr[index];
  }

  array<T> &operator=(const array<T> &anotherArr) {
    if (this == &anotherArr) {
      return *this;
    }
>>>>>>> 747f28b8e4c171da44e31deda0ba22d35c3e8387

    delete[] arr;

    length = anotherArr.length;
    arr = new T[length];

    for (size_t i = 0; i < length; i++) {
      arr[i] = anotherArr.arr[i];
    }

    return *this;
  }

  array<T> &operator=(array<T> &&anotherArr) noexcept {
    if (this == &anotherArr) {
      return *this;
    }

    if (arr != nullptr) {
      delete[] arr;
    }

    arr = anotherArr.arr;
    length = anotherArr.length;

    anotherArr.arr = nullptr;
    anotherArr.length = 0;
    return *this;
  }

  T *begin() { return arr; }

  T *end() { return arr + length; }
};
