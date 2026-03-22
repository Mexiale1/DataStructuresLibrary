#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "../src/skiplist.h"

using namespace std;

const size_t UPPER_LIMIT = 100000;
const int RUNS = 10;

int main() {

    vector<double> addTimes, findTimes, removeTimes;
    vector<double> add2Times, find2Times, remove2Times;

    for (int r = 0; r < RUNS; r++) {

        vector<int> data;
        for (size_t i = 0; i < UPPER_LIMIT; i++) {
            data.push_back(rand());
        }

        Skiplist<int> s;

        auto startAdd = chrono::high_resolution_clock::now();
        for (size_t i = 0; i < UPPER_LIMIT; i++) s.add(data[i]);
        auto endAdd = chrono::high_resolution_clock::now();

        auto startFind = chrono::high_resolution_clock::now();
        for (size_t i = 0; i < UPPER_LIMIT; i++) s.find(std::rand());
        auto endFind = chrono::high_resolution_clock::now();

        auto startRemove = chrono::high_resolution_clock::now();
        for (size_t i = 0; i < UPPER_LIMIT; i++) s.remove(data[i]);
        auto endRemove = chrono::high_resolution_clock::now();

        auto startAdd2 = chrono::high_resolution_clock::now();
        for (size_t i = 0; i < UPPER_LIMIT; i++) s.add2(data[i]);
        auto endAdd2 = chrono::high_resolution_clock::now();

        auto startFind2 = chrono::high_resolution_clock::now();
        for (size_t i = 0; i < UPPER_LIMIT; i++) s.find2(std::rand());
        auto endFind2 = chrono::high_resolution_clock::now();

        auto startRemove2 = chrono::high_resolution_clock::now();
        for (size_t i = 0; i < UPPER_LIMIT; i++) s.remove2(data[i]);
        auto endRemove2 = chrono::high_resolution_clock::now();

        addTimes.push_back(chrono::duration<double>(endAdd - startAdd).count());
        findTimes.push_back(chrono::duration<double>(endFind - startFind).count());
        removeTimes.push_back(chrono::duration<double>(endRemove - startRemove).count());

        add2Times.push_back(chrono::duration<double>(endAdd2 - startAdd2).count());
        find2Times.push_back(chrono::duration<double>(endFind2 - startFind2).count());
        remove2Times.push_back(chrono::duration<double>(endRemove2 - startRemove2).count());
    }

    auto stats = [](vector<double>& v, double& minV, double& maxV, double& avgV) {
        minV = *min_element(v.begin(), v.end());
        maxV = *max_element(v.begin(), v.end());
        double sum = 0;
        for (double x : v) sum += x;
        avgV = sum / v.size();
    };

    double minV, maxV, avgV;

    stats(addTimes, minV, maxV, avgV);
    cout << "Add:      (max) " << maxV << "s (min) " << minV << "s (avg) " << avgV << "s\n";

    stats(findTimes, minV, maxV, avgV);
    cout << "Find:     (max) " << maxV << "s (min) " << minV << "s (avg) " << avgV << "s\n";

    stats(removeTimes, minV, maxV, avgV);
    cout << "Remove:   (max) " << maxV << "s (min) " << minV << "s (avg) " << avgV << "s\n";

    stats(add2Times, minV, maxV, avgV);
    cout << "Add2:     (max) " << maxV << "s (min) " << minV << "s (avg) " << avgV << "s\n";

    stats(find2Times, minV, maxV, avgV);
    cout << "Find2:    (max) " << maxV << "s (min) " << minV << "s (avg) " << avgV << "s\n";

    stats(remove2Times, minV, maxV, avgV);
    cout << "Remove2:  (max) " << maxV << "s (min) " << minV << "s (avg) " << avgV << "s\n";

    cout << "\n";

    return 0;
}

//commented my demo tests 

//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include "../src/skiplist.h"
//
//using namespace std;
//
//int main() {
//    srand(time(0)); // seed randomness for heights
//
//    Skiplist<int> s;
//
//
//    cout << "================NORMAL SKIPLIST================\n";
//
//    cout << "\nAdding: 20, 10, 30, 25, 5\n";
//    s.add(20);
//    s.print();
//    cout << "\n";
//
//    s.add(10);
//    s.print();
//    cout << "\n";
//
//    s.add(30);
//    s.print();
//    cout << "\n";
//
//    s.add(25);
//    s.print();
//    cout << "\n";
//
//    s.add(5);
//    s.print();
//    cout << "\n";
//    
//    cout << "\nCurrent size: " << s.size() << endl;
//
//    
//    cout << "\nFinding 25: " << s.find(25) << endl;
//    cout << "Finding 100 (not present): " << s.find(100) << endl;
//
//
//    cout << "\nRemoving 20\n";
//    s.remove(20);
//    s.print();
//    cout << "\n";
//
//    cout << "Removing 5\n";
//    s.remove(5);
//    s.print();
//    cout << "\n";
//
//    cout << "Current size: " << s.size() << endl;
//
//
//    // (twist) reverse skiplist (descending) functions
//    cout << "\n==========REVERSE SKIPLIST (DESCENDING)==========\n";
//
//    Skiplist<int> r;
//
//    //add2(x) test (for reverse skiplist only)
//    cout << "\nAdding (descending): 20, 10, 30, 25, 5\n";
//
//    cout << "\n";
//
//    r.add2(20);
//    r.printReverse();
//    cout << "\n";
//
//    r.add2(10);
//    r.printReverse();
//    cout << "\n";
//
//    r.add2(30);
//    r.printReverse();
//    cout << "\n";
//
//    r.add2(25);
//    r.printReverse();
//    cout << "\n";
//
//    r.add2(5);
//    r.printReverse();
//
//    cout << "\nCurrent size: " << r.size() << endl;
//
//    // find2(x) test (for reverse skiplist only)
//    cout << "\nFinding 25: " << r.find2(25) << endl;
//    cout << "Finding 100: " << r.find2(100) << endl;
//
//    // remove2(x) test (for reverse skiplist only)
//    cout << "\nRemoving 20\n";
//    r.remove2(20);
//    r.printReverse();
//    cout << "\n";
//
//    cout << "Removing 30\n";
//    r.remove2(30);
//    r.printReverse();
//    cout << "\n";
//
//    cout << "Current size: " << r.size() << endl;
//
//    return 0;
//}
