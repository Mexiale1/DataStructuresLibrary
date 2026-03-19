
#pragma once

#include "../include/list.h"
#include <iostream>
#include <stdexcept>

template <typename T>
struct Node {
    T data;
    Node *next;
};

template <typename T>
class SLList : public List<T> {
private:
    Node<T> *head;
    size_t listSize;

public:
    SLList() {
        head = nullptr;
        listSize = 0;
    }

    void checkBounds(size_t index) const {
        if (index >= listSize) {
            throw std::out_of_range("Index is out of bounds");
        }
    }

// Index starts at 0, that is the first element is at index 0, the second at index 1, and so on.
    void add(const size_t index, const T &data) override {
        if (index > listSize) {
            throw std::out_of_range("Index is out of bounds");
        }

        Node<T> *newNode = new Node<T>;
        newNode->data = data;

        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<T> *current = head;

            for (size_t i = 0; i < index - 1; i++) {
                current = current->next;
            }

            newNode->next = current->next;  
            current->next = newNode;
        }

        listSize++;
    }

    T remove(const size_t index) override {
        checkBounds(index);

        Node<T> *toRemove;
        T removedData;

        if (index == 0) {
            toRemove = head;
            head = head->next;
        } else {
            Node<T> *current = head;

            for (size_t i = 0; i < index - 1; i++) {
                current = current->next;
            }

            toRemove = current->next;
            current->next = toRemove->next;
        }

        removedData = toRemove->data;
        delete toRemove;
        listSize--;

        return removedData;
    }

    T get(const size_t i) const override {
        checkBounds(i);

        Node<T> *current = head;
        for (size_t j = 0; j < i; j++) {
            current = current->next;
        }

        return current->data;
    }

    T set(const size_t i, const T &x) override {
        checkBounds(i);

        Node<T> *current = head;
        for (size_t j = 0; j < i; j++) {
            current = current->next;
        }

        T oldData = current->data;
        current->data = x;

        return oldData;
    }

    size_t size() const override {
        return listSize;
    }
};
