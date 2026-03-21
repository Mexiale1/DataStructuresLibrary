#pragma once

#include "../include/queue.h"
#include <stdexcept>

template <typename T> 
struct Node {
    T data;
    Node* next;

    Node(const T& x){
        data = x;
        next = nullptr;
    } 
};

template <typename T> class SLList : public Queue<T> {
    private:
        Node<T>* head;   
        Node<T>* tail;   
        size_t listSize;

    public:

        SLList(){
            head = nullptr;
            tail = nullptr;
            listSize = 0;
        } 

        ~SLList() {
            Node<T>* current = head;
            while (current != nullptr) {
                Node<T>* temp = current;
                current = current->next;
                delete temp;
            }
        }

        // we add to tail and remove from head to maintain FIFO order
        void add(const T &x) override {
            Node<T>* n = new Node<T>(x);

            if (listSize == 0) {
                head = tail = n;
            } else {
                tail->next = n;
                tail = n;
            }

            listSize++;
        }
        T remove() override {
            if (listSize == 0) {
                throw std::runtime_error("Queue is empty");
            }

            Node<T>* temp = head;
            T removedData = temp->data;

            head = head->next;
            delete temp;

            listSize--;

            if (listSize == 0) {
                tail = nullptr;
            }

            return removedData;
        }
        bool empty() const override {
            return listSize == 0;
        }

        size_t size() const {
            return listSize;
        }

// add inserts elements in sorted order instead of always adding at tail (no longer FIFO)
        void addSorted(const T &x) {
            Node<T>* n = new Node<T>(x);
            if (empty() || head->data > x) {
                n->next = head;
                head = n;
                if (listSize == 0) tail = n;
            } else {
                Node<T>* current = head;
                while (current->next && current->next->data <= x)
                    current = current->next;
                n->next = current->next;
                current->next = n;
                if (!n->next) tail = n;
            }
            listSize++;
        }
        void printHelper() const {
            Node<T>* current = head;

            std::cout << "[ ";
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << "]" << std::endl;
        }
};
