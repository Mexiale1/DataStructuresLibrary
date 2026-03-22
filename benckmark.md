## BENCHMARKS FOR EACH ADT

A benchmark is performed for each Abstract Data Type (ADT) to evaluate its performance under a consistent set of operations and conditions.


## Benchmark Setup

* Number of elements: 100,000
* Data type: integers
* Data distribution: random values
* Timing method: `std::chrono`

**Note:** All benchmark files are located in the `benchmarks` folder.


## Operations Measured

1. **Insertion** – adding elements to the data structure
   (Insert 100,000 integer values to each ADT)

2. **Deletion** – removing elements from the data structure
   (Remove 100,000 elements from each ADT)

3. **Search/Find** – locating elements within the data structure
   (Searching for 100,000 elements in each ADT )


## Benchmark Summary Table

| ADT            | Data Structure       | Insert        | Delete       | Search |
| -------------- | -------------------- | ------------- | ------------ | ------ |
| FILO QUEUE     | arraystack.cpp       |               |              |        |
| FIFO QUEUE     | sllist.cpp           | 0.007080s     | 0.006000s    |        |
| PRIORITY QUEUE | (to be implemented)  |               |              |        |
| DEQUE          | arraydeque.cpp       |               |              |        |
| LIST           | dllist.cpp           | 30s           | 30s          |        |
| SORTED SET     | skiplist.cpp         | 0.312762s     | 0.054806s    | 0.320001s   |
| SORTED SET     | redblacktrees.cpp    | 0.018605s     | 0.009507s    | 0.030595s   |
| UNSORTED SET   | chainedhashtable.cpp |               |              |        |
| GRAPH          | adjacencymatrix.cpp  |               |              |        |

---

## Detailed Benchmarks Per ADT

Additional operations specific to each data structure are also evaluated.


## Summary of Functions Per ADT

| ADT            | Data Structure       | Functions Tested                                   |
| -------------- | -------------------- | -------------------------------------------------- |
| FILO QUEUE     | arraystack.cpp       |                                                    |
| FIFO QUEUE     | sllist.cpp           | enqueue / add, dequeue / remove, add (Sorted)      |
| PRIORITY QUEUE | (to be implemented)  |                                                    |
| DEQUE          | arraydeque.cpp       |                                                    |
| LIST           | dllist.cpp           |                                                    |
| SORTED SET     | skiplist.cpp         | add, remove, find, add(Reverse), remove(Reverse), find(Reverse)    |
| SORTED SET     | redblacktrees.cpp    | add, remove, find                                  |
| UNSORTED SET   | chainedhashtable.cpp |                                                    |
| GRAPH          | adjacencymatrix.cpp  |                                                    |


### FIFO QUEUE (sllist.cpp)

- Insert: `enqueue()` / `add()`
- Delete: `dequeue()` / `remove()`
- Additional Function (Twist):
   - Sorted SLList (`addSort()`) – inserts elements in sorted order instead of always adding at the tail (no longer strictly FIFO)

  *Note:* This function is independent; the ADT itself still follows FIFO behavior.

<img width="225" height="135" alt="image" src="https://github.com/user-attachments/assets/62d6aaf2-8073-4378-a7e8-20406a01b5e8" />

---

### SORTED SET (skiplist.cpp)

- Insert: `add()`
- Delete: `remove()`
- Search: `find()`
- Additional Functions (Twist):
   - Reverse Skiplist (Descending Order) – `add2()`, `remove2()`, `find2()`  
        - Implements a skiplist that maintains elements in descending order.

  *Note:* These functions are independent; the ADT itself still follows standard Sorted Set behavior.

<img width="224" height="195" alt="image" src="https://github.com/user-attachments/assets/3f1e7bc8-b588-43b1-a023-b3fe01121892" />

---

### SORTED SET (redblacktrees.cpp)

- Insert: `add()`
- Delete: `remove()`
- Search: `find()`

<img width="264" height="139" alt="image" src="https://github.com/user-attachments/assets/9ccfbbc8-4ff6-4e73-88a2-e4993f164b9b" />
