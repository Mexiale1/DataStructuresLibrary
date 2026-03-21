#include "../src/adjacencymatrix.h"
#include <iostream>

int main() {
    AdjacencyMatrix<int> g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);

    std::cout << g.hasEdge(0,1) << std::endl; // 1
    std::cout << g.hasEdge(1,0) << std::endl; // 0

    return 0;
}