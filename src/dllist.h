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
  DLList() : listSize(0) {
    dummy = new Node<T>;
    dummy->next = dummy;
    dummy->prev = dummy;
  }

  ~DLList() {
    Node<T> *head = dummy->next, *next;

    while (head != dummy) {
      next = head->next;
      delete head;
      head = next;
    }

    delete dummy;
  }

  // Just adding the rule of five because whoever thought of this is so funny

  DLList(const DLList<T> &anotherDLList) : listSize(0) {
    dummy = new Node<T>;
    dummy->next = dummy;
    dummy->prev = dummy;

    Node<T> *head = anotherDLList.dummy->next;

    while (head != anotherDLList.dummy) {
      add(listSize, head->data);
      head = head->next;
    }
  }

  DLList(DLList<T> &&anotherDLList) noexcept {
    dummy = anotherDLList.dummy;
    listSize = anotherDLList.size();

    anotherDLList.dummy = new Node<T>;
    anotherDLList.dummy->next = anotherDLList.dummy;
    anotherDLList.dummy->prev = anotherDLList.dummy;
    anotherDLList.listSize = 0;
  }

  DLList<T> &operator=(const DLList<T> &anotherDLList) {
    if (this == &anotherDLList) {
      return *this;
    }

    Node<T> *head = dummy->next;
    while (head != dummy) {
      Node<T> *next = head->next;
      delete head;
      head = next;
    }
    dummy->next = dummy;
    dummy->prev = dummy;
    listSize = 0;

    head = anotherDLList.dummy->next;
    while (head != anotherDLList.dummy) {
      add(listSize, head->data);
      head = head->next;
    }

    return *this;
  }

  DLList<T> &operator=(DLList<T> &&anotherDLList) noexcept {
    if (this == &anotherDLList) {
      return *this;
    }

    Node<T> *head = dummy->next;
    while (head != dummy) {
      Node<T> *next = head->next;
      delete head;
      head = next;
    }
    delete dummy;

    dummy = anotherDLList.dummy;
    listSize = anotherDLList.listSize;

    anotherDLList.dummy = new Node<T>;
    anotherDLList.dummy->next = anotherDLList.dummy;
    anotherDLList.dummy->prev = anotherDLList.dummy;
    anotherDLList.listSize = 0;

    return *this;
  }

  // I will place a comment over here about index
  // Index refers to the index computer programmers usually use for arrays
  // i.e. Starts at 0

  void checkBounds(size_t index) const {
    if (index >= listSize) {
      throw std::out_of_range("Index is out of bounds");
    }
  }

  Node<T> *getNode(size_t index) const {
    checkBounds(index);

    Node<T> *head;

    if (index <= listSize / 2) {
      head = dummy->next;
      for (size_t i = 0; i < index; i++) {
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

  void addFirst(const T &x) { add(0, x); }

  void printList() {
    Node<T> *head = dummy->next;

    while (head != dummy) {
      std::cout << head->data;
      if (head->next != dummy) {
        std::cout << " -> ";
      }

      head = head->next;
    }

    std::cout << std::endl;
  }
};
