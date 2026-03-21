# DataStructuresLibrary
A Library of Data Structures discovered through the CMSC 123 course.

# Overview
This repository contains our implementation of several fundamental data structures in C++. These structures were developed as part of the CMSC 123 course requirement to build a small open-source data structures library.
The goal of this project is to understand how common data structures work internally by implementing them from scratch, rather than relying on built-in libraries.

# Implemented Data Structures
**Linear Structures**
- Stack (FILO Queue)
-     Implementation: ArrayStack
- Queue (FIFO Queue)
-     Implementation: SLList (Singly Linked List)
- Deque (Double-ended Queue)
-     Implementation: ArrayDeque

**Lists**
- Array-based List
Implemented through ArrayDeque
- Doubly Linked List
Implementation: DLList

**Sets**
- Unsorted Set
Implementation: ChainedHashTable
- Sorted Set
Implementations:
Skiplist
RBTreeSet (Red-Black Tree)

**Graph**
- Adjacency Matrix Representation
Implementation: AdjacencyMatrix

# Project Structure
**include/ **
array.h 
deque.h 
graph.h 
list.h 
queue.h 
sset.h 
stack.h 
uset.h 

**src/ **
adjacencymatrix.h 
arraydeque.h 
arraystack.h 
chainedhashtable.h 
dllist.h 
redblacktrees.h 
skiplist.h 
sllist.h 

**tests/ **
adjacencymatrix.cpp 
arraydeque.cpp 
arraystack.cpp 
chainedhashtable.cpp 
dllist.cpp 
redblacktrees.cpp 
skiplist.cpp 
sllist.cpp

# Instructions
Using g++, we compile a test file using: 
g++ tests/arraydeque.cpp -o test 
./test

Replace arraydeque.cpp with any test file you want to run.

# Testing
Each data structure has a corresponding test file in the tests/ directory.

For instance:
arraydeque.cpp → tests deque operations
arraystack.cpp → tests stack operations
skiplist.cpp → tests sorted set behavior

These test files demonstrate:
- Basic operations
- Edge cases (empty structure, invalid indices)
- Correctness of implementation et al.

# Benchmarking
Basic benchmarking is included to measure performance of operations such as:
- Large number of insertions (100,000 – 1,000,000)
- Repeated removals
- Search operations

Example benchmark (ArrayStack):
for (int i = 0; i < 1000000; i++) {
    st.push(i);
}

for (int i = 0; i < 1000000; i++) {
    st.pop();
}

Execution time is measured using std::chrono.

# Miscellaneous (Won't edit pa atm kay basin needed pani and naay iadd jesse)
We have format:

| Input | Description        |
|-------|--------------------|
| A     | Add elements       |
| B     | Remove elements    |
| C     | Shuffles elements  |
| D     | Breakdance         |
| E     | Backflip           |
| F     | End program        |

# Benchmarking

| Data Structure | Speed |
|----------------|-------|
| A              | XXms  |
| B              | XXms  |
| C              | XXms  |
| D              | XXms  |
| E              | XXms  |
| F              | XXms  |

# Contributors
Thank you very much:
- Mexiale1 (Jesse Michael Mazo)
- dobidobop (Dave Christian Gagani)
- Piyaa-bot (Feahmar Jean Bentazal)

# References
- If there are any, insert here.

# TODO

- Add the rest of the thingies
- Make a format for the `.cpp` files for running
- Make the big input .txt file that does all everything
- Complete project by December 23, 2025

# Contact

Do not contact please
