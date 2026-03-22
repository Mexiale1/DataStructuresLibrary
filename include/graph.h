#pragma once

#include "list.h"

template <typename T> struct Graph {
  virtual ~Graph() {}
  virtual bool addEdge(const int &i, const int &j) = 0;
  virtual bool removeEdge(const int &i, const int &j) = 0;
  virtual bool hasEdge(const int &i, const int &j) const = 0;
  virtual List<T>* outEdges(const int &i) const = 0; 
  virtual List<T>* inEdges(const int &i) const = 0;   
};