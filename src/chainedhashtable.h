#pragma once

#include "../include/list.h"
#include "../include/uset.h"

template <typename T> class ChainedHashTable : public Uset<T> {
private:
  array<List> table;
  size_t items;
};
