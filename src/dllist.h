#pragma once

#include "../include/list.h"
#include <iostream>
#include <stdexcept>
#include <type_traits>

template <typename T> struct Node {
  T data;
  Node *next, *prev;
};

template <typename T> class DLList : public List<T> {
private:
  Node<T> *dummy;
  size_t listSize;

public:
  DLList() {
    dummy = new Node<T>;
    dummy->next = dummy;
    dummy->prev = dummy;
    listSize = 0;
  }

  // I will place a comment over here about index
  // Index refers to the index computer programmers usually use for arrays
  // i.e. Starts at 0

  void checkBounds(size_t index) {
    if (index >= listSize) {
      throw std::out_of_range("Index is out of bounds");
    }
  }

  Node<T> *getNode(size_t index) const {
    checkBounds(index);

    Node<T> *head;

    if (index <= listSize / 2) {
      head = dummy->next;
      for (size_t i = 0; i <= index; i++) {
        head = head->next;
      }
    } else {
      head = dummy->prev;
      for (size_t i = 0; i < (listSize - 1) - index; i++) {
        head = head->prev;
      }
    }

    return head;
  }

  void add(const size_t index, const T &data) override {
    if (index > listSize) {
      throw std::out_of_range("Index is out of bounds");
    }

    Node<T> *head, *newNode;
    newNode = new Node<T>();

    if (index == listSize) { // Exception handling on getNode() kills code
      head = dummy;
    } else {
      head = getNode(index);
    }
    newNode->data = data;

    newNode->next = head;
    newNode->prev = head->prev;

    head->prev->next = newNode;
    head->prev = newNode;
    listSize++;
  }

  T remove(const size_t index) override {
    checkBounds(index);

    Node<T> *toRemove = getNode(index);
    T removedData;

    toRemove->prev->next = toRemove->next;
    toRemove->next->prev = toRemove->prev;

    removedData = toRemove->data;

    if constexpr (std::is_pointer<T>::value) {
      delete toRemove->data;
    }

    delete toRemove;
    listSize--;

    return removedData;
  }

  T get(const size_t index) const override {
    checkBounds(index);

    return getNode(index)->data;
  }

  T set(const size_t index, const T &data) override {
    checkBounds(index);

    Node<T> *toChange = getNode(index);
    T changedData = toChange->data;

    toChange->data = data;

    return changedData;
  }

  size_t size() const override { return listSize; }
};
