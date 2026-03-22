#define UPPER_LIMIT 1000000

#include "../src/chainedhashtable.h"
#include <chrono>
#include <cstddef>

int main() {
  ChainedHashTable<int> dog;
  auto minAdd = std::chrono::duration<double>::max();
  auto maxAdd = std::chrono::duration<double>::zero();

  auto minFind = std::chrono::duration<double>::max();
  auto maxFind = std::chrono::duration<double>::zero();

  auto avgAdd = std::chrono::duration<double>::zero();
  auto avgFind = std::chrono::duration<double>::zero();

  size_t i = 0;

  while (i < 10) {
    std::chrono::time_point beforeTest = std::chrono::system_clock::now();

    for (size_t i = 0; i < UPPER_LIMIT; i++) {
      int randValue = std::rand();
      dog.add(randValue);
    }

    std::chrono::time_point afterAdd = std::chrono::system_clock::now();

    for (size_t i = 0; i < UPPER_LIMIT; i++) {
      int randValue = std::rand();
      dog.find(randValue);
    }
    std::chrono::time_point afterFind = std::chrono::system_clock::now();

    std::chrono::duration<double> add = afterAdd - beforeTest;
    std::chrono::duration<double> find = afterFind - afterAdd;

    std::cout << "Add: " << add.count() << "s" << std::endl;
    std::cout << "Find: " << find.count() << "s" << std::endl;

    if (add < minAdd)
      minAdd = add;
    if (add > maxAdd)
      maxAdd = add;

    if (find < minFind)
      minFind = find;
    if (find > maxFind)
      maxFind = find;

    avgAdd += add;
    avgFind += find;
    i++;
  }

  avgFind /= 10;
  avgAdd /= 10;

  std::cout << "Minimum time (add): " << minAdd.count() << "s" << std::endl;
  std::cout << "Maximum time (add): " << maxAdd.count() << "s" << std::endl;

  std::cout << "Minimum time (find): " << minFind.count() << "s" << std::endl;
  std::cout << "Maximum time (find): " << maxFind.count() << "s" << std::endl;

  std::cout << "Average time (add): " << avgAdd.count() << "s" << std::endl;
  std::cout << "Average time (find): " << avgFind.count() << "s" << std::endl;

  return 0;
}
