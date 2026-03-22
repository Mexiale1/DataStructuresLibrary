#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>
#include "../src/arraystack.h"

using namespace std;

const size_t UPPER_LIMIT = 100000;
const int RUNS = 10;

int main() {

    chrono::duration<double> minPush = chrono::duration<double>::max();
    chrono::duration<double> maxPush = chrono::duration<double>::zero();
    chrono::duration<double> minPop = chrono::duration<double>::max();
    chrono::duration<double> maxPop = chrono::duration<double>::zero();
    chrono::duration<double> avgPush = chrono::duration<double>::zero();
    chrono::duration<double> avgPop = chrono::duration<double>::zero();

    for (int run = 0; run < RUNS; run++) {
        ArrayStack<int> s;

        auto startPush = chrono::high_resolution_clock::now();
        for (size_t i = 0; i < UPPER_LIMIT; i++) {
            s.push(std::rand());
        }
        auto endPush = chrono::high_resolution_clock::now();

        auto startPop = chrono::high_resolution_clock::now();
        for (size_t i = 0; i < UPPER_LIMIT; i++) {
            s.pop();
        }
        auto endPop = chrono::high_resolution_clock::now();

        chrono::duration<double> pushTime = endPush - startPush;
        chrono::duration<double> popTime = endPop - startPop;

        if (pushTime < minPush) minPush = pushTime;
        if (pushTime > maxPush) maxPush = pushTime;
        if (popTime < minPop) minPop = popTime;
        if (popTime > maxPop) maxPop = popTime;

        avgPush += pushTime;
        avgPop += popTime;
    }

    avgPush /= RUNS;
    avgPop /= RUNS;

    cout << "Push: (max) " << maxPush.count() << "s"
        << "  (min) " << minPush.count() << "s"
        << "  (avg) " << avgPush.count() << "s\n";

    cout << "Pop:  (max) " << maxPop.count() << "s"
        << "  (min) " << minPop.count() << "s"
        << "  (avg) " << avgPop.count() << "s\n";

    return 0;
}

//commented dave's tests
// #include "../src/arraystack.h"
// #include <iostream>
// int main() {
//    ArrayStack<int> st;
//   st.push(10);
//   st.push(20);

//    std::cout << st.top() << std::endl; // 20
//  std::cout << st.pop() << std::endl; // 20
//    std::cout << st.pop() << std::endl; // 10

//   return 0;
//}
