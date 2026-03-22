#include <iostream>
#include <chrono>
#include <cstdlib>
#include "../src/skiplist.h"

using namespace std;

const size_t UPPER_LIMIT = 100000; //adjust for benchmarking

int main() {
    Skiplist<int> s;

    cout << "\n";
    cout << "Skiplist Benchmark\n";
    cout << "--------------------------\n";

    auto startAdd = chrono::high_resolution_clock::now();

    for (size_t i = 0; i < UPPER_LIMIT; i++) {
        int val = rand();
        s.add(val);
    }

    auto endAdd = chrono::high_resolution_clock::now();

    auto startFind = chrono::high_resolution_clock::now();

    for (size_t i = 0; i < UPPER_LIMIT; i++) {
        int val = rand();
        s.find(val);
    }

    auto endFind = chrono::high_resolution_clock::now();

    auto startRemove = chrono::high_resolution_clock::now();

    for (size_t i = 0; i < UPPER_LIMIT; i++) {
        int val = rand();
        s.remove(val);
    }

    auto endRemove = chrono::high_resolution_clock::now();

    auto startAdd2 = chrono::high_resolution_clock::now();

    for (size_t i = 0; i < UPPER_LIMIT; i++) {
        int val = rand();
        s.add2(val);
    }

    auto endAdd2 = chrono::high_resolution_clock::now();

    auto startFind2 = chrono::high_resolution_clock::now();

    for (size_t i = 0; i < UPPER_LIMIT; i++) {
        int val = rand();
        s.find2(val);
    }

    auto endFind2 = chrono::high_resolution_clock::now();

    auto startRemove2   = chrono::high_resolution_clock::now();

    for (size_t i = 0; i < UPPER_LIMIT; i++) {
        int val = rand();
        s.remove2(val);
    }

    auto endRemove2 = chrono::high_resolution_clock::now();


    chrono::duration<double> timeAdd = endAdd - startAdd;
    chrono::duration<double> timeFind = endFind - startFind;
    chrono::duration<double> timeRemove = endRemove - startRemove;
    chrono::duration<double> timeAdd2 = endAdd2 - startAdd2;
    chrono::duration<double> timeFind2 = endFind2 - startFind2;
    chrono::duration<double> timeRemove2 = endRemove2 - startRemove2;

    cout << "Operation      Time (s)\n";
    cout << "--------------------------\n";
    cout << "Add:           " << timeAdd.count() << " s\n";
    cout << "Find:          " << timeFind.count() << " s\n";
    cout << "Remove:        " << timeRemove.count() << " s\n";
    cout << "Add2:          " << timeAdd2.count() << " s\n";
    cout << "Find2:         " << timeFind2.count() << " s\n";
    cout << "Remove2:       " << timeRemove2.count() << " s\n";
    cout << "\n";

    return 0;
}
