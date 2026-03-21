#include <iostream>
#include <chrono>
#include <cstdlib>
#include "../src/skl.h"

using namespace std;

const size_t UPPER_LIMIT = 1000000; //adjust for benchmarking

int main() {
    Skiplist<int> s;

    cout << "Skiplist Benchmark\n";


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

    auto startFindNT = chrono::high_resolution_clock::now();

    for (size_t i = 0; i < UPPER_LIMIT; i++) {
        int val = rand() + UPPER_LIMIT; 
        s.find(val);
    }

    auto endFindNT = chrono::high_resolution_clock::now();

    auto startRemove = chrono::high_resolution_clock::now();

    for (size_t i = 0; i < UPPER_LIMIT; i++) {
        int val = rand();
        s.remove(val);
    }

    auto endRemove = chrono::high_resolution_clock::now();

    chrono::duration<double> timeAdd = endAdd - startAdd;
    chrono::duration<double> timeFind = endFind - startFind;
    chrono::duration<double> timeRemove = endRemove - startRemove;
    chrono::duration<double> timeFindNT = endFindNT - startFindNT;

    cout << "Add:    " << timeAdd.count() << " s\n";
    cout << "Find:   " << timeFind.count() << " s\n";
    cout << "Find (Values Not There): " << timeFindNT.count() << " s\n";
    cout << "Remove: " << timeRemove.count() << " s\n";

    cout << "Current skiplist size: " << s.size() << endl;

    return 0;
}
