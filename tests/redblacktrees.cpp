#include <iostream>
#include "rbt.h"
using namespace std;

int main() {
    RBTreeSet<int> tree;

    cout << "Note: In the tree diagram, |-- represents a left child, "
        "\\-- represents a right child.\n";
    cout << "\n";
    cout << "==========ADDING NODES===========\n";
    cout <<"\n";

    tree.add(20);
    cout << "Added 20:\n";
    tree.printTree();

    tree.add(10);
    cout << "Added 10:\n";
    tree.printTree();

    tree.add(30);
    cout << "Added 30:\n";
    tree.printTree();

    tree.add(25);
    cout << "Added 25:\n";
    tree.printTree();

    tree.add(5);
    cout << "Added 5:\n";
    tree.printTree();

    cout << "Current size: " << tree.size() << "\n\n";

    cout << "============FINDING NODES============\n";
    cout << "\n";

    int found25 = tree.find(25);
    if (found25 == 0)
        cout << "Finding 25 (not present): 0\n";
    else
        cout << "Finding 25: " << found25 << "\n";

    int found100 = tree.find(100);
    if (found100 == 0)
        cout << "Finding 100 (not present): 0\n";
    else
        cout << "Finding 100: " << found100 << "\n";

    cout << "\n============REMOVING NODES============\n";

    cout << "Removing 20:\n";
    tree.remove(20);
    tree.printTree();

    cout << "Removing 5:\n";
    tree.remove(5);
    tree.printTree();

    cout << "Removing 30:\n";
    tree.remove(30);
    tree.printTree();

    cout << "Final size: " << tree.size() << "\n";

    return 0;
}
