#pragma once

#include "../include/sset.h"
#include <cstdlib>
#include <cstddef>
#include <ctime>

template <typename T>
struct Node {
    T data;
    int height;
    Node** next;

    Node(T val, int h) {
        data = val;
        height = h;
        next = new Node*[h + 1];
        for (int i = 0; i <= h; i++) {
            next[i] = nullptr;
        }
    }

    ~Node() {
        delete[] next;
    }
};

template <typename T> class Skiplist : public SortedSet<T> {
private:
    static const int MAXH = 32;

    Node<T>* sentinel;
    int maxHeight;
    size_t n;

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
            while (u->next[r] != nullptr &&
                   compare2(u->next[r]->data, x) < 0) {
                u = u->next[r];
            }
        }
        return u;
    }

public:
    Skiplist() {
        maxHeight = 0;
        n = 0;
        sentinel = new Node<T>(T(), MAXH - 1);
    }

    ~Skiplist() {
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

    void compare(T &x, T &y) override { }

    T find(const T &x) const override {
        Node<T>* u = findPredNode(x);

        if (u->next[0] != nullptr &&
            compare2(u->next[0]->data, x) == 0) {
            return u->next[0]->data;
        }

        return T(); 
    }

    bool add(const T &x) override {
        Node<T>* stack[MAXH];
        Node<T>* u = sentinel;

        int h = maxHeight;

        for (int r = h; r >= 0; r--) {
            while (u->next[r] != nullptr &&
                   compare2(u->next[r]->data, x) < 0) {
                u = u->next[r];
            }
            stack[r] = u;
        }
        if (u->next[0] != nullptr &&
            compare2(u->next[0]->data, x) == 0) {
            return false;
        }

        int newH = pickHeight();
        Node<T>* w = new Node<T>(x, newH);

        if (newH > maxHeight) {
            for (int i = maxHeight + 1; i <= newH; i++) {
                stack[i] = sentinel;
            }
            maxHeight = newH;
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
        for (int r = maxHeight; r >= 0; r--) {
            while (u->next[r] != nullptr &&
                   compare2(u->next[r]->data, x) < 0) {
                u = u->next[r];
            }
            if (u->next[r] != nullptr &&
                compare2(u->next[r]->data, x) == 0) {

                if (!found) {
                    del = u->next[r];
                    found = true;
                }
                u->next[r] = u->next[r]->next[r];
            }
        }
        if (found) {
            T val = del->data;
            delete del;
            n--;
            while (maxHeight > 0 &&
                   sentinel->next[maxHeight] == nullptr) {
                maxHeight--;
            }
            return val;
        }
        return T(); 
    }

    // ======================================
    // (Twist) REVERSE SKIPLIST FUNCTIONS
    // ======================================

    // insert x in reverse order (descending)
    bool add2(const T &x) {
        Node<T>* stack[MAXH];
        Node<T>* u = sentinel;
        int h = maxHeight;

        for (int r = h; r >= 0; r--) {
            while (u->next[r] != nullptr &&
                compare2(u->next[r]->data, x) > 0) {
                u = u->next[r];
            }
            stack[r] = u;
        }

        if (u->next[0] != nullptr &&
            compare2(u->next[0]->data, x) == 0) {
            return false;
        }

        int newH = pickHeight();
        Node<T>* w = new Node<T>(x, newH);

        if (newH > maxHeight) {
            for (int i = maxHeight + 1; i <= newH; i++) {
                stack[i] = sentinel;
            }
            maxHeight = newH;
        }
        for (int i = 0; i <= newH; i++) {
            w->next[i] = stack[i]->next[i];
            stack[i]->next[i] = w;
        }

        n++;
        return true;
    }

    // find x in reverse order (descending)
    T find2(const T &x) const {
        Node<T>* u = sentinel;

        for (int r = maxHeight; r >= 0; r--) {
            while (u->next[r] != nullptr &&
                compare2(u->next[r]->data, x) > 0) {
                u = u->next[r];
            }
        }

        if (u->next[0] != nullptr &&
            compare2(u->next[0]->data, x) == 0) {
            return u->next[0]->data;
        }

        return T(); 
    }

    // remove x in reverse order (descending)
    T remove2(const T &x) {
        Node<T>* u = sentinel;
        Node<T>* del = nullptr;
        bool found = false;

        for (int r = maxHeight; r >= 0; r--) {
            while (u->next[r] != nullptr &&
                compare2(u->next[r]->data, x) > 0) {
                u = u->next[r];
            }
            if (u->next[r] != nullptr &&
                compare2(u->next[r]->data, x) == 0) {

                if (!found) {
                    del = u->next[r];
                    found = true;
                }
                u->next[r] = u->next[r]->next[r];
            }
        }

        if (found) {
            T val = del->data;
            delete del;
            n--;
            while (maxHeight > 0 &&
                sentinel->next[maxHeight] == nullptr) {
                maxHeight--;
            }
            return val;
        }

        return T(); 
    }


    //print functions for testing
    void print() const {
        for (int r = maxHeight; r >= 0; r--) {
            Node<T>* u = sentinel->next[r];

            std::cout << "Level " << r << ": ";
            while (u != nullptr) {
                std::cout << u->data << " -> ";
                u = u->next[r];
            }
            std::cout << "nullptr\n";
        }
    }

    void printReverse() const {
        for (int r = maxHeight; r >= 0; r--) {
            Node<T>* u = sentinel->next[r];
            std::cout << "Level " << r << ": ";
            while (u != nullptr) {
                std::cout << u->data << " -> ";
                u = u->next[r];
            }
            std::cout << "nullptr\n";
        }
    }
};
