#include "../src/adjacencymatrix.h"
#include <iostream>

int main() {
    AdjacencyMatrix<int> g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);

    std::cout << "Has edge (0,1): " << g.hasEdge(0,1) << std::endl;
    std::cout << "Has edge (1,0): " << g.hasEdge(1,0) << std::endl;
    
    // Test outEdges 
    List<int>* out = g.outEdges(0);
    if (out) {
        std::cout << "Out edges from 0: ";
        for (size_t i = 0; i < out->size(); i++) {
            std::cout << out->get(i) << " ";
        }
        std::cout << std::endl;
        delete out;  
    }
    
    // Test inEdges
    List<int>* in = g.inEdges(1);
    if (in) {
        std::cout << "In edges to 1: ";
        for (size_t i = 0; i < in->size(); i++) {
            std::cout << in->get(i) << " ";
        }
        std::cout << std::endl;
        delete in;  
    }

    return 0;
}