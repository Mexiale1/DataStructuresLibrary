#include <iostream>
#include <chrono>
#include <cstdlib>
#include "../src/rbt.h"

using namespace std;

const size_t UPPER_LIMIT = 1000000; 

int main() {
    RBTreeSet<int> tree;

    cout << "RBTreeSet Benchmark\n";

    auto startAdd = chrono::high_resolution_clock::now();
    for (size_t i = 0; i < UPPER_LIMIT; i++) {
        int val = rand();
        tree.add(val);
    }
    auto endAdd = chrono::high_resolution_clock::now();

    auto startFind = chrono::high_resolution_clock::now();
    for (size_t i = 0; i < UPPER_LIMIT; i++) {
        int val = rand() % UPPER_LIMIT; // likely exists
        tree.find(val);
    }
    auto endFind = chrono::high_resolution_clock::now();

    auto startFindNT = chrono::high_resolution_clock::now();
    for (size_t i = 0; i < UPPER_LIMIT; i++) {
        int val = rand() + UPPER_LIMIT; // likely not in tree
        tree.find(val);
    }
    auto endFindNT = chrono::high_resolution_clock::now();

    auto startRemove = chrono::high_resolution_clock::now();
    for (size_t i = 0; i < UPPER_LIMIT / 2; i++) { 
        int val = rand() % UPPER_LIMIT;
        tree.remove(val);
    }
    auto endRemove = chrono::high_resolution_clock::now();

    chrono::duration<double> timeAdd = endAdd - startAdd;
    chrono::duration<double> timeFind = endFind - startFind;
    chrono::duration<double> timeFindNT = endFindNT - startFindNT;
    chrono::duration<double> timeRemove = endRemove - startRemove;

    cout << "Add:                     " << timeAdd.count() << " s\n";
    cout << "Find (Values Likely There): " << timeFind.count() << " s\n";
    cout << "Find (Values Not There): " << timeFindNT.count() << " s\n";
    cout << "Remove:                  " << timeRemove.count() << " s\n";

    cout << "Current tree size: " << tree.size() << endl;

    return 0;
}  
