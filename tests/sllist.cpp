#include <iostream>
#include "../src/sllist.h" 

using namespace std;

int main() {
    SLList<int> q;

    cout << "Initial queue: ";
    q.printHelper();
  
        // normal add() 
    cout << "\nAdding normally (FIFO): 1, 2, 3\n";
    q.add(1);
    q.printHelper();

    q.add(2);
    q.printHelper();

    q.add(3);
    q.printHelper();

    // remove element by element
    cout << "\nRemoving elements one by one:\n";
    while (!q.empty()) {
        cout << "Removed: " << q.remove() << endl;
        cout << "Queue now: ";
        q.printHelper();
    }
  
    cout << "\n=====Test for Twist Added=====\n";
    // (twist) addSorted() demo 
    cout << "\nAdding (sorted): 25\n";
    q.addSorted(25);
    q.printHelper();

    cout << "Adding (sorted): 10\n";
    q.addSorted(10);
    q.printHelper();

    cout << "Adding (sorted): 30\n";
    q.addSorted(30);
    q.printHelper();

    cout << "Adding (sorted): 20\n";
    q.addSorted(20);
    q.printHelper();

    cout << "Adding (sorted): 5\n";
    q.addSorted(5);
    q.printHelper();
    cout << "\n=============================\n";

    cout << "\nRemoving all (FIFO order):\n";
    while (!q.empty()) {
        cout << "Removed: " << q.remove() << endl;
        cout << "Queue now: ";
        q.printHelper();
    }

    //exception test
    cout << "\nRemove from empty queue...\n";
    try {
        q.remove();
    } catch (const runtime_error& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    return 0;
}
