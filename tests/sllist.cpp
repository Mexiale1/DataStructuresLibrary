#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "../src/sllist.h"

using namespace std;

const size_t UPPER_LIMIT = 100000;
const int RUNS = 10;

int main() {

    vector<double> addTimes;
    vector<double> removeTimes;
    vector<double> uniqueTimes;

    for (int r = 0; r < RUNS; r++) {

        vector<int> data;
        for (size_t i = 0; i < UPPER_LIMIT; i++) {
            data.push_back(rand());
        }

        SLList<int> q;

        auto startAdd = chrono::high_resolution_clock::now();

        for (size_t i = 0; i < UPPER_LIMIT; i++) {
            q.add(data[i]);
        }

        auto endAdd = chrono::high_resolution_clock::now();

        auto startRemove = chrono::high_resolution_clock::now();

        while (!q.empty()) {
            q.remove();
        }

        auto endRemove = chrono::high_resolution_clock::now();

        addTimes.push_back(chrono::duration<double>(endAdd - startAdd).count());
        removeTimes.push_back(chrono::duration<double>(endRemove - startRemove).count());

        SLList<int> u;

        auto startUnique = chrono::high_resolution_clock::now();

        for (size_t i = 0; i < UPPER_LIMIT; i++) {
            u.addSorted(data[i]);
        }

        auto endUnique = chrono::high_resolution_clock::now();

        uniqueTimes.push_back(chrono::duration<double>(endUnique - startUnique).count());
    }

    auto computeStats = [](vector<double>& v, double& minV, double& maxV, double& avgV) {
        minV = *min_element(v.begin(), v.end());
        maxV = *max_element(v.begin(), v.end());

        double sum = 0;
        for (double x : v) sum += x;
        avgV = sum / v.size();
    };

    double addMin, addMax, addAvg;
    double removeMin, removeMax, removeAvg;
    double uniqueMin, uniqueMax, uniqueAvg;

    computeStats(addTimes, addMin, addMax, addAvg);
    computeStats(removeTimes, removeMin, removeMax, removeAvg);
    computeStats(uniqueTimes, uniqueMin, uniqueMax, uniqueAvg);

    cout << "Add:    (max) " << addMax
         << "s (min) " << addMin
         << "s (avg) " << addAvg << "s\n";

    cout << "Remove: (max) " << removeMax
         << "s (min) " << removeMin
         << "s (avg) " << removeAvg << "s\n";

    cout << "Unique: (max) " << uniqueMax
         << "s (min) " << uniqueMin
         << "s (avg) " << uniqueAvg << "s\n";

    cout << "\n";

    return 0;
}


//#include <iostream>
//#include "../src/sllist.h" 
//
//using namespace std;
//
//int main() {
//    SLList<int> q;
//
//    cout << "Initial queue: ";
//    q.printHelper();
//  
//
//    cout << "\nAdding normally (FIFO): 1, 2, 3\n";
//    q.add(1);
//    q.printHelper();
//
//    q.add(2);
//    q.printHelper();
//
//    q.add(3);
//    q.printHelper();
//
//
//    cout << "\nRemove elements one by one:\n";
//    while (!q.empty()) {
//        cout << "Removed: " << q.remove() << endl;
//        cout << "Queue now: ";
//        q.printHelper();
//    }
//  
//    cout << "\n=====Test for Twist Added=====\n";
//   
//    cout << "\nAdding (sorted): 25\n";
//    q.addSorted(25);
//    q.printHelper();
//
//    cout << "Adding (sorted): 10\n";
//   q.addSorted(10);
//    q.printHelper();
//
//    cout << "Adding (sorted): 30\n";
//    q.addSorted(30);
//    q.printHelper();
//
//    cout << "Adding (sorted): 20\n";
//    q.addSorted(20);
//    q.printHelper();
//
//    cout << "Adding (sorted): 5\n";
//    q.addSorted(5);
//    q.printHelper();
//    cout << "\n=============================\n";
//
//    cout << "\nRemoving all (FIFO order):\n";
//    while (!q.empty()) {
//        cout << "Removed: " << q.remove() << endl;
//        cout << "Queue now: ";
//        q.printHelper();
//    }
//
    //exception test
//    cout << "\nRemove from empty queue...\n";
//    try {
//        q.remove();
//    } catch (const runtime_error& e) {
//        cout << "Caught exception: " << e.what() << endl;
//    }
//
//    return 0;
//}
