## BENCHMARKS FOR EACH ADT

A benchmark is performed for each Abstract Data Type (ADT) to evaluate its performance under a consistent set of operations and conditions.

---

## Benchmark Setup

* Number of elements: 100,000
* Data type: integers
* Data distribution: random values
* Timing method: `std::chrono`

**Note:** All benchmark files are located in the `benchmarks` folder.

---

## Operations Measured

1. **Insertion** – adding elements to the data structure
   (Inserting 100,000 integer values)

2. **Deletion** – removing elements from the data structure
   (Removing 100,000 elements)

3. **Search/Find** – locating elements within the data structure
   (Searching for 100,000 elements)

---

## Benchmark Summary Table

| ADT            | Data Structure       | Insert    | Delete    | Search |
| -------------- | -------------------- | --------- | --------- | ------ |
| FILO QUEUE     | arraystack.cpp       |           |           | N/A    |
| FIFO QUEUE     | sllist.cpp           | 0.006503s | 0.004010s | N/A    |
| PRIORITY QUEUE | (to be implemented)  |           |           | N/A    |
| DEQUE          | arraydeque.cpp       |           |           | N/A    |
| LIST           | dllist.cpp           | 30s       | 30s       | N/A    |
| SORTED SET     | skiplist.cpp         |           |           |        |
| SORTED SET     | redblacktrees.cpp    |           |           |        |
| UNSORTED SET   | chainedhashtable.cpp |           |           |        |
| GRAPH          | adjacencymatrix.cpp  |           |           |        |

---

## Detailed Benchmarks Per ADT

Each ADT is tested using the same benchmark setup.
Additional operations specific to each data structure are also evaluated.

---

## Summary of Functions Per ADT

| ADT            | Data Structure       | Functions Tested                                  |
| -------------- | -------------------- | ------------------------------------------------- |
| FILO QUEUE     | arraystack.cpp       |                                                   |
| FIFO QUEUE     | sllist.cpp           | enqueue / add, dequeue / remove, add (Sorted)     |
| PRIORITY QUEUE | (to be implemented)  |                                                   |
| DEQUE          | arraydeque.cpp       |                                                   |
| LIST           | dllist.cpp           |                                                   |
| SORTED SET     | skiplist.cpp         | add, remove, find, add(Reverse), remove(Reverse)  |
| SORTED SET     | redblacktrees.cpp    | add, remove, find                                 |
| UNSORTED SET   | chainedhashtable.cpp |                                                   |
| GRAPH          | adjacencymatrix.cpp  |                                                   |

---



### FIFO QUEUE (sllist.cpp)

* Insert: `enqueue()` / `add()`
* Delete: `dequeue()` / `remove()`

Functions Added (Twist):
* Add Sorted: inserts elements in sorted order instead of always adding at tail (no longer FIFO)
    -Note:  This function is independent; the ADT itself still follows FIFO behavior.

**Results:**

* Insert: 0.006503 s
* Delete: 0.00401 s
* Add Sorted: 55.076 s
<img width="275" height="102" alt="image" src="https://github.com/user-attachments/assets/f1949df4-75ba-4277-9cd0-76845df1af6d" />

---

### SORTED SET (skiplist.cpp)

* Insert: `add()`
* Delete: `remove()`
* Search: `find()`

**Results:**

* Insert: ___
* Delete: ___
* Search: ___

---

### SORTED SET (redblacktrees.cpp)

* Insert: `add()`
* Delete: `remove()`
* Search: `find()`

**Results:**

* Insert: ___
* Delete: ___
* Search: ___

---

* Insert: ___
* Delete: ___
* Search: ___

---
