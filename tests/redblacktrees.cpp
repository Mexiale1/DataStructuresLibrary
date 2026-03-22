#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "../src/redblacktrees.h"

using namespace std;

const size_t UPPER_LIMIT = 100000;
const int RUNS = 10;

int main() {

    vector<double> addTimes;
    vector<double> findTimes;
    vector<double> removeTimes;

    for (int r = 0; r < RUNS; r++) {

        vector<int> data;
        for (size_t i = 0; i < UPPER_LIMIT; i++) {
            data.push_back(rand());
        }

        RBTreeSet<int> tree;

        auto startAdd = chrono::high_resolution_clock::now();
        for (size_t i = 0; i < UPPER_LIMIT; i++) {
            tree.add(data[i]);}
        auto endAdd = chrono::high_resolution_clock::now();
  
        auto startFind = chrono::high_resolution_clock::now();
        for (size_t i = 0; i < UPPER_LIMIT; i++) {
            tree.find(std::rand());  }
        auto endFind = chrono::high_resolution_clock::now();

        auto startRemove = chrono::high_resolution_clock::now();
        for (size_t i = 0; i < UPPER_LIMIT; i++) {
            tree.remove(data[i]);}
        auto endRemove = chrono::high_resolution_clock::now();

        addTimes.push_back(chrono::duration<double>(endAdd - startAdd).count());
        findTimes.push_back(chrono::duration<double>(endFind - startFind).count());
        removeTimes.push_back(chrono::duration<double>(endRemove - startRemove).count());
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
    cout << "Add:    (max) " << maxV << "s (min) " << minV << "s (avg) " << avgV << "s\n";

    stats(findTimes, minV, maxV, avgV);
    cout << "Find:   (max) " << maxV << "s (min) " << minV << "s (avg) " << avgV << "s\n";

    stats(removeTimes, minV, maxV, avgV);
    cout << "Remove: (max) " << maxV << "s (min) " << minV << "s (avg) " << avgV << "s\n";

    cout << "\n";

    return 0;
}

//commented my demo tests

//#include <iostream>
//#include "../src/redblacktrees.h"
//using namespace std;
//
//int main() {
//    RBTreeSet<int> tree;
//
//    cout << "Note: In the tree diagram, |-- represents a left child, "
//        "\\-- represents a right child.\n";
//    cout << "\n";
//    cout << "==========ADDING NODES===========\n";
//    cout <<"\n";
//
//    tree.add(20);
//    cout << "Added 20:\n";
//    tree.printTree();
//
//    tree.add(10);
//    cout << "Added 10:\n";
//    tree.printTree();
//
//    tree.add(30);
//    cout << "Added 30:\n";
//    tree.printTree();
//
//    tree.add(25);
//    cout << "Added 25:\n";
//    tree.printTree();
//
//    tree.add(5);
//    cout << "Added 5:\n";
//    tree.printTree();
//
//    cout << "Current size: " << tree.size() << "\n\n";
//
//    cout << "============FINDING NODES============\n";
//    cout << "\n";
//
//    int found25 = tree.find(25);
//    if (found25 == 0)
//        cout << "Finding 25 (not present): 0\n";
//    else
//        cout << "Finding 25: " << found25 << "\n";
//
//    int found100 = tree.find(100);
//    if (found100 == 0)
//        cout << "Finding 100 (not present): 0\n";
//    else
//        cout << "Finding 100: " << found100 << "\n";
//
//    cout << "\n============REMOVING NODES============\n";
//
//    cout << "Removing 20:\n";
//    tree.remove(20);
//    tree.printTree();
//
//    cout << "Removing 5:\n";
//    tree.remove(5);
//    tree.printTree();
//
//    cout << "Removing 30:\n";
//    tree.remove(30);
//    tree.printTree();
//
//    cout << "Final size: " << tree.size() << "\n";
//
//    return 0;
//}
