#pragma once

#include "../include/array.h"
#include "../include/list.h"
#include <algorithm>

template <typename T>
class ArrayStack : public List<T> {
private:
    array<T>* arr;
    size_t n; 

    void resize() {
        size_t new_capacity = std::max((size_t)1, 2 * n);
        array<T>* b = new array<T>(new_capacity);
        for (size_t i = 0; i < n; i++) {
            (*b)[i] = (*arr)[i];
        }
        delete arr;
        arr = b;
    }

public:
    ArrayStack() {
        arr = new array<T>(1);
        n = 0;
    }

    ~ArrayStack() {
        delete arr;
    }

    size_t size() const override {
        return n;
    }

    T get(const size_t i) const override {
        return (*arr)[i];
    }

    T set(const size_t i, const T& x) override {
        T old = (*arr)[i];
        (*arr)[i] = x;
        return old;
    }

    void add(const size_t i, const T& x) override {
        if (n + 1 > arr->length) resize();
        for (size_t j = n; j > i; j--) {
            (*arr)[j] = (*arr)[j - 1];
        }
        (*arr)[i] = x;
        n++;
    }

    T remove(const size_t i) override {
        T x = (*arr)[i];
        for (size_t j = i; j < n - 1; j++) {
            (*arr)[j] = (*arr)[j + 1];
        }
        n--;
        if (arr->length >= 3 * n) resize();
        return x;
    }

    void push(const T& x) { add(n, x); }
    T pop() { return remove(n - 1); }
    T top() { return get(n - 1); }

    void clear() {
        n = 0;
        resize();
    }
};