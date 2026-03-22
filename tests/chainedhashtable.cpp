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

  auto minRemove = std::chrono::duration<double>::max();
  auto maxRemove = std::chrono::duration<double>::zero();

  auto avgAdd = std::chrono::duration<double>::zero();
  auto avgFind = std::chrono::duration<double>::zero();
  auto avgRemove = std::chrono::duration<double>::zero();

  size_t i = 0;

  while (i < 10) {
    std::chrono::time_point beforeTest = std::chrono::system_clock::now();

    for (size_t j = 0; j < UPPER_LIMIT; j++) {
      dog.add(std::rand());
    }

    std::chrono::time_point afterAdd = std::chrono::system_clock::now();

    for (size_t j = 0; j < UPPER_LIMIT; j++) {
      dog.find(std::rand());
    }
    std::chrono::time_point afterFind = std::chrono::system_clock::now();

    for (size_t j = 0; j < UPPER_LIMIT; j++) {
      dog.remove(std::rand());
    }

    std::chrono::time_point afterRemove = std::chrono::system_clock::now();

    std::chrono::duration<double> add = afterAdd - beforeTest;
    std::chrono::duration<double> find = afterFind - afterAdd;
    std::chrono::duration<double> remove = afterRemove - afterFind;

    if (add < minAdd)
      minAdd = add;
    if (add > maxAdd)
      maxAdd = add;

    if (find < minFind)
      minFind = find;
    if (find > maxFind)
      maxFind = find;

    if (remove < minRemove)
      minRemove = remove;
    if (remove > maxRemove)
      maxRemove = remove;

    avgAdd += add;
    avgFind += find;
    avgRemove += remove;

    i++;
  }

  avgFind /= i;
  avgAdd /= i;
  avgRemove /= i;

  std::cout << "Minimum time (add): " << minAdd.count() << "s" << std::endl;
  std::cout << "Maximum time (add): " << maxAdd.count() << "s" << std::endl;

  std::cout << "Minimum time (find): " << minFind.count() << "s" << std::endl;
  std::cout << "Maximum time (find): " << maxFind.count() << "s" << std::endl;

  std::cout << "Minimum time (remove): " << minRemove.count() << "s"
            << std::endl;
  std::cout << "Maximum time (remove): " << maxRemove.count() << "s"
            << std::endl;

  std::cout << "Average time (add): " << avgAdd.count() << "s" << std::endl;
  std::cout << "Average time (find): " << avgFind.count() << "s" << std::endl;
  std::cout << "Average time (remove): " << avgRemove.count() << "s"
            << std::endl;

  return 0;
}
