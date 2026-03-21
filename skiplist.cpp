#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../src/skl.h"

using namespace std;

int main() {
    srand(time(0)); // seed randomness for heights

    Skiplist<int> s;

    // normal add()
    cout << "================NORMAL SKIPLIST================\n";

    cout << "\nAdding: 20, 10, 30, 25, 5\n";
    s.add(20);
    s.print();
    cout << "\n";

    s.add(10);
    s.print();
    cout << "\n";

    s.add(30);
    s.print();
    cout << "\n";

    s.add(25);
    s.print();
    cout << "\n";

    s.add(5);
    s.print();
    cout << "\n";
    
    cout << "\nCurrent size: " << s.size() << endl;

    // find(x) test
    cout << "\nFinding 25: " << s.find(25) << endl;
    cout << "Finding 100 (not present): " << s.find(100) << endl;

    // remove(x) test
    cout << "\nRemoving 20\n";
    s.remove(20);
    s.print();
    cout << "\n";

    cout << "Removing 5\n";
    s.remove(5);
    s.print();
    cout << "\n";

    cout << "Current size: " << s.size() << endl;


    // (twist) reverse skiplist (descending) functions
    cout << "\n==========REVERSE SKIPLIST (DESCENDING)==========\n";

    Skiplist<int> r;

    //add2(x) test (for reverse skiplist only)
    cout << "\nAdding (descending): 20, 10, 30, 25, 5\n";

    cout << "\n";

    r.add2(20);
    r.printReverse();
    cout << "\n";

    r.add2(10);
    r.printReverse();
    cout << "\n";

    r.add2(30);
    r.printReverse();
    cout << "\n";

    r.add2(25);
    r.printReverse();
    cout << "\n";

    r.add2(5);
    r.printReverse();

    cout << "\nCurrent size: " << r.size() << endl;

    // find2(x) test (for reverse skiplist only)
    cout << "\nFinding 25: " << r.find2(25) << endl;
    cout << "Finding 100: " << r.find2(100) << endl;

    // remove2(x) test (for reverse skiplist only)
    cout << "\nRemoving 20\n";
    r.remove2(20);
    r.printReverse();
    cout << "\n";

    cout << "Removing 30\n";
    r.remove2(30);
    r.printReverse();
    cout << "\n";

    cout << "Current size: " << r.size() << endl;

    return 0;
}
