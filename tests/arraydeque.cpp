#define UPPER_LIMIT 10000000

#include "../src/arraydeque.h"
#include <chrono>
#include <iostream>

int main() {
  size_t i = 0;

  auto minAdd = std::chrono::duration<double>::max();
  auto maxAdd = std::chrono::duration<double>::zero();

  auto minRemove = std::chrono::duration<double>::max();
  auto maxRemove = std::chrono::duration<double>::zero();

  auto avgAdd = std::chrono::duration<double>::zero();
  auto avgRemove = std::chrono::duration<double>::zero();

  while (i < 10) {

    ArrayDeque<int> dog;
    std::chrono::time_point beforeTest = std::chrono::system_clock::now();

    for (size_t j = 0; 2 * j < UPPER_LIMIT; j++) {
      dog.addFirst(std::rand());
    }

    // I went for making two loops idk something about having to call an if
    // statment for half of UPPER_LIMIT sounded stupid to me

    for (size_t j = 0; 2 * j < UPPER_LIMIT; j++) {
      dog.addLast(std::rand());
    }

    std::chrono::time_point afterAdd = std::chrono::system_clock::now();

    std::chrono::duration<double> add = afterAdd - beforeTest;

    for (size_t j = 0; 2 * j < UPPER_LIMIT; j++) {
      dog.removeFirst();
    }

    for (size_t j = 0; 2 * j < UPPER_LIMIT; j++) {
      dog.removeLast();
    }

    std::chrono::time_point afterRemove = std::chrono::system_clock::now();

    std::chrono::duration<double> remove = afterRemove - afterAdd;

    if (add > maxAdd)
      maxAdd = add;
    if (add < minAdd)
      minAdd = add;

    if (remove > maxRemove)
      maxRemove = remove;
    if (remove < minRemove)
      minRemove = remove;

    avgAdd += add;
    avgRemove += remove;

    i++;
  }

  avgAdd /= i;
  avgRemove /= i;

  std::cout << "Add: (max) " << maxAdd.count() << "s (min) " << minAdd.count()
            << "s (avg) " << avgAdd.count() << "s\n";
  std::cout << "Remove: (max) " << maxRemove.count() << "s (min) "
            << minRemove.count() << "s (avg) " << avgRemove.count() << "s\n";

  return 0;
}

// Commented out dave's tests
// ArrayDeque<int> dq;
//
// dq.addLast(1);
// dq.addLast(2);
// dq.addLast(3);
//
// dq.addFirst(0);
//
// std::cout << "After additions:\n";
// for (size_t i = 0; i < dq.size(); i++) {
//     std::cout << dq.get(i) << " ";
// }
// std::cout << "\n";
//
// std::cout << "removeFirst: " << dq.removeFirst() << std::endl;
// std::cout << "removeLast: " << dq.removeLast() << std::endl;
//
// std::cout << "After removals:\n";
// for (size_t i = 0; i < dq.size(); i++) {
//     std::cout << dq.get(i) << " ";
// }
// std::cout << "\n";
//
// std::cout << "peekFirst: " << dq.peekFirst() << std::endl;
// std::cout << "peekLast: " << dq.peekLast() << std::endl;
//
// dq.add(1, 99);
//
// std::cout << "After add at index 1:\n";
// for (size_t i = 0; i < dq.size(); i++) {
//     std::cout << dq.get(i) << " ";
// }
// std::cout << "\n";
//
// std::cout << "Removed index 1: " << dq.remove(1) << std::endl;
//
// std::cout << "Final state:\n";
// for (size_t i = 0; i < dq.size(); i++) {
//     std::cout << dq.get(i) << " ";
// }
// std::cout << "\n";
//
// return 0;
