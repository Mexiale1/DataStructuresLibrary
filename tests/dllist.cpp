#include "../src/dllist.h"

int main() {
  DLList<int> dog; // Testing if it has no errors

  for (size_t i = 0; i < 100; i++) {
    dog.addFirst(i);
  }

  dog.printList();

  std::cout << "Remove test\n";

  for (size_t i = 0; i < 90; i++) {
    std::cout << i << ": " << dog.size() << std::endl;
    dog.remove(0);
  }

  dog.printList();

  return 0;
}
