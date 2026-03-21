#pragma once

#include "../include/graph.h"
#include "../include/array.h"
#include "../include/list.h"
#include "arraystack.h"

template <typename T>
class AdjacencyMatrix : public Graph<T> {
private:
    array<array<bool>> matrix;
    size_t n;

public:
    AdjacencyMatrix(size_t n) : matrix(n), n(n) {
        for (size_t i = 0; i < n; i++) {
            matrix[i] = array<bool>(n);
            for (size_t j = 0; j < n; j++) {
                matrix[i][j] = false;
            }
        }
    }

    bool addEdge(const int &i, const int &j) override {
        if (i >= n || j >= n) return false;
        matrix[i][j] = true;
        return true;
    }

    bool removeEdge(const int &i, const int &j) override {
        if (i >= n || j >= n) return false;
        matrix[i][j] = false;
        return true;
    }

    bool hasEdge(const int &i, const int &j) const override {
        if (i >= n || j >= n) return false;
        return matrix[i][j];
    }

    List<T> outEdges(const int &i) const override {
        ArrayStack<T>* list = new ArrayStack<T>();

        for (size_t j = 0; j < n; j++) {
            if (matrix[i][j]) {
                list->add(list->size(), j);
            }
        }

        return *list; // ⚠️ (not ideal but matches your interface)
    }

    List<T> inEdges(const int &i) const override {
        ArrayStack<T>* list = new ArrayStack<T>();

        for (size_t j = 0; j < n; j++) {
            if (matrix[j][i]) {
                list->add(list->size(), j);
            }
        }

        return *list;
    }
};