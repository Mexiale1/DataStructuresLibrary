#pragma once

#include <cstddef>

template <typename T> struct Stack {
    // Push an item onto the stack, accepts the item (any data type) as a parameter.
    virtual void push(const T& x) = 0;
    // Pop the top item from the stack.
    virtual void pop() = 0;
    // Returns the top item of the stack without removing it.
    virtual T& top() = 0;
    // Returns the current number of items in the stack.
    virtual size_t size() const = 0;
    // Returns true if the stack is empty, false otherwise.
    virtual bool isEmpty() const = 0;
};
