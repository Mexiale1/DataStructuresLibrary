#define UPPER_LIMIT 10000000

#include "../src/dllist.h"
#include <chrono>
#include <cstdlib>

int main() {
  DLList<int> dog; // Testing if it has no errors

  std::chrono::time_point beforeTest = std::chrono::system_clock::now();

  for (size_t i = 0; i < UPPER_LIMIT; i++) {
    int randValue = std::rand();
    dog.addFirst(randValue);
  }

  std::chrono::time_point afterAdd = std::chrono::system_clock::now();

  dog.myMergeSort();

  std::chrono::time_point afterSort = std::chrono::system_clock::now();

  for (size_t i = 0; i < UPPER_LIMIT / 10; i++) {
    dog.remove(0);
  }

  std::chrono::time_point afterRemove = std::chrono::system_clock::now();

  std::chrono::duration<double> add = afterAdd - beforeTest;
  std::chrono::duration<double> sorting = afterSort - afterAdd;
  std::chrono::duration<double> remove = afterRemove - afterSort;

  std::cout << "Add: " << add.count() << "s" << std::endl;
  std::cout << "Sorting: " << sorting.count() << "s" << std::endl;
  std::cout << "Remove: " << remove.count() << "s" << std::endl;

  return 0;
}
