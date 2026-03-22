#include <iostream>
#include <chrono>
#include <cstdlib>
#include "../src/sllist.h"

using namespace std;

const size_t UPPER_LIMIT = 100000; 

int main() {
    SLList<int> q;

    auto startAdd = chrono::high_resolution_clock::now();

    for (size_t i = 0; i < UPPER_LIMIT; i++) {
        int val = rand();
        q.add(val);
    }

    auto endAdd = chrono::high_resolution_clock::now();

    auto startRemove = chrono::high_resolution_clock::now();


     while (!q.empty()) {
            q.remove();
    }

    auto endRemove = chrono::high_resolution_clock::now();

    chrono::duration<double> timeAdd = endAdd - startAdd;
    chrono::duration<double> timeRemove = endRemove - startRemove;

    cout << "Time for add() (FIFO):      " << timeAdd.count() << "s\n";
    cout << "Time for remove():          " << timeRemove.count() << "s\n";

    return 0;
}
