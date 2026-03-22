#define UPPER_LIMIT 100000

#include "../src/dllist.h"
#include <chrono>
#include <cstdlib>

int main() {
  DLList<int> dog; // Testing if it has no error
  size_t i = 0;

  auto minAdd = std::chrono::duration<double>::max();
  auto maxAdd = std::chrono::duration<double>::zero();

  auto minSort = std::chrono::duration<double>::max();
  auto maxSort = std::chrono::duration<double>::zero();

  auto minRemove = std::chrono::duration<double>::max();
  auto maxRemove = std::chrono::duration<double>::zero();

  auto avgAdd = std::chrono::duration<double>::zero();
  auto avgSort = std::chrono::duration<double>::zero();
  auto avgRemove = std::chrono::duration<double>::zero();

  while (i < 5) {
    std::chrono::time_point beforeTest = std::chrono::system_clock::now();

    for (size_t i = 0; i < UPPER_LIMIT; i++) {
      int randValue = std::rand();
      int randIndex = std::rand() % (dog.size() + 1);
      dog.add(randIndex, randValue);
    }

    std::chrono::time_point afterAdd = std::chrono::system_clock::now();

    std::chrono::duration<double> add = afterAdd - beforeTest;
    std::cout << "Add: " << add.count() << "s" << std::endl;

    dog.myMergeSort();

    std::chrono::time_point afterSort = std::chrono::system_clock::now();
    std::chrono::duration<double> sorting = afterSort - afterAdd;

    std::cout << "Sorting: " << sorting.count() << "s" << std::endl;

    for (size_t i = 0; i < UPPER_LIMIT; i++) {
      int randIndex = std::rand() % dog.size();
      dog.remove(randIndex);
    }

    std::chrono::time_point afterRemove = std::chrono::system_clock::now();

    std::chrono::duration<double> remove = afterRemove - afterSort;
    std::cout << "Remove: " << remove.count() << "s" << std::endl;

    i++;

    if (add > maxAdd)
      maxAdd = add;
    if (add < minAdd)
      minAdd = add;

    if (sorting > maxSort)
      maxSort = sorting;
    if (sorting < minSort)
      minSort = sorting;

    if (remove > maxRemove)
      maxRemove = remove;
    if (remove < minRemove)
      minRemove = remove;

    avgAdd += add;
    avgSort += sorting;
    avgRemove += remove;
  }

  avgAdd /= i;
  avgSort /= i;
  avgRemove /= i;

  std::cout << "Add: (max) " << maxAdd.count() << "s (min) " << minAdd.count()
            << "s (avg) " << avgAdd.count() << "s\n";
  std::cout << "Sort: (max) " << maxSort.count() << "s (min) "
            << minSort.count() << "s (avg) " << avgSort.count() << "s\n";
  std::cout << "Remove: (max) " << maxRemove.count() << "s (min) "
            << minRemove.count() << "s (avg) " << avgRemove.count() << "s\n";

  return 0;
}
