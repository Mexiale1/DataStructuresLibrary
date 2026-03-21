#include "../src/arraydeque.h"
#include <iostream>

int main() {
    ArrayDeque<int> dq;

    dq.addLast(1);
    dq.addLast(2);
    dq.addLast(3);

    dq.addFirst(0);

    std::cout << "After additions:\n";
    for (size_t i = 0; i < dq.size(); i++) {
        std::cout << dq.get(i) << " ";
    }
    std::cout << "\n";

    std::cout << "removeFirst: " << dq.removeFirst() << std::endl; 
    std::cout << "removeLast: " << dq.removeLast() << std::endl; 

    std::cout << "After removals:\n";
    for (size_t i = 0; i < dq.size(); i++) {
        std::cout << dq.get(i) << " ";
    }
    std::cout << "\n";

    std::cout << "peekFirst: " << dq.peekFirst() << std::endl;
    std::cout << "peekLast: " << dq.peekLast() << std::endl;  

    dq.add(1, 99);

    std::cout << "After add at index 1:\n";
    for (size_t i = 0; i < dq.size(); i++) {
        std::cout << dq.get(i) << " ";
    }
    std::cout << "\n";

    std::cout << "Removed index 1: " << dq.remove(1) << std::endl;

    std::cout << "Final state:\n";
    for (size_t i = 0; i < dq.size(); i++) {
        std::cout << dq.get(i) << " ";
    }
    std::cout << "\n";

    return 0;
}
