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
        // Initialize each row
        for (size_t i = 0; i < n; i++) {
            // Create a new array for each row
            array<bool> row(n);
            for (size_t j = 0; j < n; j++) {
                row[j] = false;
            }
            matrix[i] = row;
        }
    }

    ~AdjacencyMatrix() {
        // Clean up if needed
    }

    bool addEdge(const int &i, const int &j) override {
        if (i < 0 || j < 0 || static_cast<size_t>(i) >= n || static_cast<size_t>(j) >= n) return false;
        matrix[i][j] = true;
        return true;
    }

    bool removeEdge(const int &i, const int &j) override {
        if (i < 0 || j < 0 || static_cast<size_t>(i) >= n || static_cast<size_t>(j) >= n) return false;
        matrix[i][j] = false;
        return true;
    }

    bool hasEdge(const int &i, const int &j) const override {
        if (i < 0 || j < 0 || static_cast<size_t>(i) >= n || static_cast<size_t>(j) >= n) return false;
        return matrix[i][j];
    }

    List<T>* outEdges(const int &i) const override {
        if (i < 0 || static_cast<size_t>(i) >= n) return nullptr;
        
        ArrayStack<T>* list = new ArrayStack<T>();

        for (size_t j = 0; j < n; j++) {
            if (matrix[i][j]) {
                list->add(list->size(), static_cast<T>(j));
            }
        }

        return list; 
    }

    List<T>* inEdges(const int &i) const override {
        if (i < 0 || static_cast<size_t>(i) >= n) return nullptr;
        
        ArrayStack<T>* list = new ArrayStack<T>();

        for (size_t j = 0; j < n; j++) {
            if (matrix[j][i]) {
                list->add(list->size(), static_cast<T>(j));
            }
        }

        return list;
    }
};