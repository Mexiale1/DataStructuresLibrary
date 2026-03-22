# DataStructuresLibrary

A Library of Data Structures discovered through the CMSC 123 course.

# Overview
This repository contains our implementation of several fundamental data structures in C++. These structures were developed as part of the CMSC 123 course requirement to build a small open-source data structures library.
The goal of this project is to understand how common data structures work internally by implementing them from scratch, rather than relying on built-in libraries.

# Implemented Data Structures
**Linear Structures**
- Stack (FILO Queue)
-      Implementation: ArrayStack
- Queue (FIFO Queue)
-      Implementation: SLList (Singly Linked List)
- Deque (Double-ended Queue)
-      Implementation: ArrayDeque

**Lists**
- Array-based List
-      Implemented through ArrayDeque
- Doubly Linked List
-      Implementation: DLList

**Sets**
- Unsorted Set
-      Implementation: ChainedHashTable
- Sorted Set
-      Implementations: Skiplist & RBTreeSet (Red-Black Tree)

**Graph**
- Adjacency Matrix Representation
-      Implementation: AdjacencyMatrix

# Project Structure
**include/**
- `array.h`
- `deque.h`
- `graph.h`
- `list.h`
- `queue.h`
- `sset.h`
- `stack.h`
- `uset.h `

**src/**
- `adjacencymatrix.h`
- `arraydeque.h`
- `arraystack.h`
- `chainedhashtable.h`
- `dllist.h`
- `redblacktrees.h`
- `skiplist.h`
- `sllist.h `

**tests/**
- `adjacencymatrix.cpp`
- `arraydeque.cpp`
- `arraystack.cpp`
- `chainedhashtable.cpp`
- `dllist.cpp`
- `redblacktrees.cpp`
- `skiplist.cpp`
- `sllist.cpp`

# Instructions
Using g++, we compile a test file using: 
```shell
g++ tests/[Any Data Structure].cpp -o test 
./test
```

# Testing
Each data structure has a corresponding test file in the tests/ directory.

For instance:
`arraydeque.cpp` → tests deque operations
`arraystack.cpp` → tests stack operations
`skiplist.cpp` → tests sorted set behavior

These test files demonstrate:
- Basic operations
- Edge cases (empty structure, invalid indices)
- Correctness of implementation et al.

# Benchmarking
Basic benchmarking is included to measure performance of operations such as:
- Large number of insertions (100,000 – 1,000,000)
- Repeated removals
- Search operations
- Unique operations

Example benchmark (ArrayStack):
```c
for (int i = 0; i < 1000000; i++) {
    st.push(i);
}

for (int i = 0; i < 1000000; i++) {
    st.pop();
}
```

Execution time is measured using std::chrono.

# Contributors
Thank you very much:
- Mexiale1 (Jesse Michael Mazo)
- dobidobop (Dave Christian Gagani)
- newJean06 (Feahmar Jean Bentazal)

# References
- If there are any, insert here.

# TODO
- Somehow missed the Priority Queue ADT
- Finish benchmarking on everything
- Add unique methods to the data structures

# Contact
Dont contact please

# License
This project is licensed under the MIT License - see the LICENSE file for details.
-     MIT License

Copyright (c) 2024 CMSC-123-Final-Project

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
