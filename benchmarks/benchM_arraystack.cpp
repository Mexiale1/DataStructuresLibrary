#include <iostream>
#include <chrono>
#include <cstdlib>
#include "../src/arraystack.h"

using namespace std;

const size_t UPPER_LIMIT = 100000;

int main() {
    ArrayStack<int> s;

    cout << "\n";
    cout << "ArrayStack Benchmark \n";
    cout << "----------------------------\n";

    auto startAdd = chrono::high_resolution_clock::now();
    for (size_t i = 0; i < UPPER_LIMIT; i++) {
        int val = rand();
        s.push(val);
    }
    auto endAdd = chrono::high_resolution_clock::now();

    auto startRemove = chrono::high_resolution_clock::now();
    for (size_t i = 0; i < UPPER_LIMIT; i++) {
        s.pop();
    }
    auto endRemove = chrono::high_resolution_clock::now();

    chrono::duration<double> timeAdd = endAdd - startAdd;
    chrono::duration<double> timeRemove = endRemove - startRemove;

    cout << "Operation           Time (s)\n";
    cout << "----------------------------\n";
    cout << "Push:               " << timeAdd.count() << " s\n";
    cout << "Pop:                " << timeRemove.count() << " s\n";
    cout << "\n";

    return 0;
}
