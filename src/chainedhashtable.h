#pragma once

#include "../include/array.h"
#include "../include/uset.h"
#include "dllist.h"
#include <algorithm>
#include <cstddef>
#include <functional>

// Book said List so I took list

template <typename T> class ChainedHashTable : public Uset<T> {
private:
  array<DLList<T>> table;
  size_t items;
  std::hash<T> myHash;

public:
  void resize() {
    size_t newSize = std::max((size_t)1, 2 * table.length);
    array<DLList<T>> newTable(newSize);

    for (size_t i = 0; i < table.length; i++) {
      for (size_t j = 0; i < table[i].size(); j++) {
        newTable[myHash(table[i].get(j)) % newSize].addFirst(table[i].get(j));
      }
    }

    table = std::move(newTable);
  }

  size_t hash(const T &x) { return myHash(x) % table.length; }

  size_t size() const { return items; }

  bool add(const T &x) {
    if (find(x) != NULL) {
      return false;
    }

    float ratio = (float)items / (float)table.length;

    if (ratio > 1.0) {
      resize();
    }

    table[this->hash(x)].addFirst(x);
    items++;

    return true;
  }

  bool remove(const T &x) {
    size_t hashValue = hash(x);
    T toRemove = NULL;

    for (size_t i = 0; i < table[hashValue].size(); i++) {
      toRemove = table[hashValue].get(i);

      if (toRemove == x) {
        table[hashValue].remove(i);
        items--;
        break;
      }
    }

    return toRemove;
  }

  bool find(const T &x) {
    size_t hashValue = hash(x);
    bool found = false;

    for (size_t i = 0; i < table[hashValue].size(); i++) {
      if (table[hashValue].get(i) == x) {
        found = true;
        break;
      }
    }

    return found;
  }
};
