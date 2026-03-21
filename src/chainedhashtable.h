#pragma once

#include "../include/array.h"
#include "../include/uset.h"
#include "dllist.h"
#include <algorithm>
#include <cstddef>
#include <functional>
#include <optional>

// Book said List so I took list

template <typename T> class ChainedHashTable : public Uset<T> {
private:
  array<DLList<T>> table;
  size_t items;
  std::hash<T> myHash;

public:
  ChainedHashTable() : table(10), items(0) {}

  void resize() {
    size_t newSize = std::max((size_t)1, 2 * table.length);
    array<DLList<T>> newTable(newSize);

    for (size_t i = 0; i < table.length; i++) {
      for (size_t j = 0; j < table[i].size(); j++) {
        newTable[myHash(table[i].get(j)) % newSize].addFirst(table[i].get(j));
      }
    }

    table = std::move(newTable);
  }

  size_t hash(const T &x) const { return myHash(x) % table.length; }

  size_t size() const { return items; }

  bool add(const T &x) {
    if (find(x).has_value()) {
      return false;
    }

    if (items + 1 > table.length) {
      resize();
    }

    table[this->hash(x)].addFirst(x);
    items++;

    return true;
  }

  std::optional<T> remove(const T &x) {
    size_t hashValue = hash(x);
    bool found = false;
    T toRemove;

    for (size_t i = 0; i < table[hashValue].size(); i++) {

      if (table[hashValue].get(i) == x) {
        found = true;
        toRemove = table[hashValue].remove(i);
        items--;
        break;
      }
    }

    if (!found) {
      return std::nullopt;
    }
    return toRemove;
  }

  std::optional<T>
  find(const T &x) const { // Book says return null but thats hard
    size_t hashValue = hash(x);

    for (size_t i = 0; i < table[hashValue].size(); i++) {
      if (table[hashValue].get(i) == x) {
        return table[hashValue].get(i);
      }
    }
    return std::nullopt;
  }
};
