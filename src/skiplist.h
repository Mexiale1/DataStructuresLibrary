
#pragma once

#include "../include/sset.h"
#include <cstdlib>
#include <cstddef>
#include <iostream>

template <typename T>
struct Node {
    T data;
    int height;
    Node** next;
    
    Node(T input, int h) {
        data = input;
        height = h;
        next = new Node*[h + 1]; // array of pointers to next nodes at each level
        for (int i = 0; i <= h; i++) {
            next[i] = nullptr;
        }
    }

    ~Node() {
        delete[] next; 
    }
};

template <typename T> class SkiplistSSet : public SortedSet<T> {
private:
    static const int MAXH = 32;

    Node<T>* sentinel;
    int maxHeight;  // current max height
    size_t n;       // number of elements

    int compare2(const T& a, const T& b) const {
        if (a < b) return -1;
        if (a > b) return 1;
        return 0;
    }

    int pickHeight() {
        int z = rand();
        int k = 0;

        while ((z & 1) == 1 && k < MAXH - 1) {
            k++;
            z >>= 1;
        }
        return k;
    }

    Node<T>* findPredNode(const T& x) const {
        Node<T>* u = sentinel;
        for (int r = maxHeight; r >= 0; r--) {
            while (u->next[r] != nullptr && compare2(u->next[r]->data, x) < 0) {
                u = u->next[r];
            }
        }
        return u;
    }

public:
    SkiplistSSet() {
        maxHeight = 0;
        n = 0;
        sentinel = new Node<T>(T(), MAXH);
    }

    ~SkiplistSSet() {
        Node<T>* u = sentinel;
        while (u != nullptr) {
            Node<T>* next = u->next[0];
            delete u;
            u = next;
        }
    }

    size_t size() const override {
        return n;
    }

    void compare(T &x, T &y) override {}

    T find(const T &x) const override {
        Node<T>* u = findPredNode(x);

        if (u->next[0] != nullptr &&
            compare2(u->next[0]->data, x) == 0) {
            return u->next[0]->data;
        }

        return T();
    }

    bool add(const T &x) override {
        Node<T>* stack[MAXH + 1];
        Node<T>* u = sentinel;

        int h = maxHeight;

        // build stack of predecessors
        for (int r = h; r >= 0; r--) {
            while (u->next[r] != nullptr &&
                   compare2(u->next[r]->data, x) < 0) {
                u = u->next[r];
            }
            stack[r] = u;
        }

        // check for duplicates
        if (u->next[0] != nullptr &&
            compare2(u->next[0]->data, x) == 0) {
            return false;
        }

        int newH = pickHeight();
        
        Node<T>* w = new Node<T>(x, newH);

        if (newH > h) {
            for (int i = h + 1; i <= newH; i++) {
                stack[i] = sentinel;
            }
            maxHeight = newH;
            h = newH;
        }

        for (int i = 0; i <= newH; i++) {
            w->next[i] = stack[i]->next[i];
            stack[i]->next[i] = w;
        }

        n++;
        return true;
    }

    T remove(const T &x) override {
        Node<T>* u = sentinel;
        Node<T>* del = nullptr;
        bool found = false;

        int h = maxHeight;

        for (int r = h; r >= 0; r--) {
            while (u->next[r] != nullptr &&
                   compare2(u->next[r]->data, x) < 0) {
                u = u->next[r];
            }

            if (u->next[r] != nullptr &&
                compare2(u->next[r]->data, x) == 0) {

                if (!found) del = u->next[r]; 
                found = true;

                u->next[r] = u->next[r]->next[r];

                if (u == sentinel && u->next[r] == nullptr) {
                    maxHeight--;
                }
            }
        }

        if (found) {
            T val = del->data;
            delete del;
            n--;
            return val;
        }

        return T();
    }
};
