#include "../include/array.h"
#include "../include/deque.h"
#include "../include/list.h"

#include <stdexcept>
#include <algorithm>

template <typename T>
class ArrayDeque : public Deque<T>, public List<T>
{
private:
    array<T> a;
    size_t j;  // index of front
    size_t n;  // number of elements

    void resize(size_t newCap) {
        array<T> b(newCap);
        for (size_t k = 0; k < n; k++)
            b[k] = a[(j + k) % a.length];
        a = b;
        j = 0;
    }

public:
    ArrayDeque() : a(10), j(0), n(0) {}

    void addFirst(const T &x) override {
        if (n + 1 > a.length) resize(2 * a.length);
        j = (j == 0) ? a.length - 1 : j - 1;
        a[j] = x;
        n++;
    }

    void addLast(const T &x) override {
        if (n + 1 > a.length) resize(2 * a.length);
        a[(j + n) % a.length] = x;
        n++;
    }

    T removeFirst() override {
        if (n == 0) throw std::out_of_range("Deque is empty");
        T x = a[j];
        j = (j + 1) % a.length;
        n--;
        if (a.length >= 3 * n && a.length > 10)
            resize(std::max<size_t>(10, 2 * n));
        return x;
    }

    T removeLast() override {
        if (n == 0) throw std::out_of_range("Deque is empty");
        size_t idx = (j + n - 1) % a.length;
        T x = a[idx];
        n--;
        if (a.length >= 3 * n && a.length > 10)
            resize(std::max<size_t>(10, 2 * n));
        return x;
    }

    const T peekFirst() const override {
        if (n == 0) throw std::out_of_range("Deque is empty");
        return a[j];
    }

    const T peekLast() const override {
        if (n == 0) throw std::out_of_range("Deque is empty");
        return a[(j + n - 1) % a.length];
    }

    bool isEmpty() const override {
        return n == 0;
    }

    void clear() override {
        resize (10);
        j = 0;
        n = 0;
    }

    size_t size() const override {
        return n;
    }

    void add(const size_t i, const T &x) override {
        if (i > n) throw std::out_of_range("Index out of range");
        if (n + 1 > a.length) resize(2 * a.length);
        if (i < n / 2) {
            j = (j == 0) ? a.length - 1 : j - 1;
            for (size_t k = 0; k < i; k++) {
                a[(j + k) % a.length] = a[(j + k + 1) % a.length];
            }
        } else {
            for (size_t k = n; k > i; k--) {
                a[(j + k) % a.length] = a[(j + k - 1) % a.length];
            }
        }
        a[(j + i) % a.length] = x;
        n++;
    }

    T remove(const size_t i) override {
        if (i >= n) throw std::out_of_range("Index out of range");
        T x = a[(j + i) % a.length];
        if (i < n / 2) {
            for (size_t k = i; k > 0; k--) {
                a[(j + k) % a.length] = a[(j + k - 1) % a.length];
            }
            j = (j + 1) % a.length;
        } else {
            for (size_t k = i; k < n - 1; k++) {
                a[(j + k) % a.length] = a[(j + k + 1) % a.length];
            }
        }
        n--;
        if (a.length >= 3 * n && a.length > 10)
            resize(std::max<size_t>(10, 2 * n));
        return x;
    }

    T get(const size_t i) const override {
        if (i >= n) throw std::out_of_range("Index out of range");
        return a[(j + i) % a.length];
    }

    T set(const size_t i, const T &x) override {
        if (i >= n) throw std::out_of_range("Index out of range");
        T y = a[(j + i) % a.length];
        a[(j + i) % a.length] = x;
        return y;
    }
};