## BENCHMARKS FOR EACH ADT

A benchmark is performed for each Abstract Data Type (ADT) to evaluate its performance under a consistent set of operations and conditions.

## Benchmark Setup and Operations Measured

All ADTs are benchmarked under the same conditions to ensure consistency and comparability.

**Benchmark Setup:**

- Number of elements: 100,000  
- Data type: integers  
- Data distribution: random values  
- Timing method: `std::chrono`  
- Note: All benchmark files are located in the `benchmarks` folder.

**Operations Measured:**

1. **Insertion** – adding elements to the data structure  
   *(Insert 100,000 integer values into each ADT)*

2. **Deletion** – removing elements from the data structure  
   *(Remove 100,000 elements from each ADT)*

3. **Search / Find** – locating elements within the data structure  
   *(Search for 100,000 elements in each ADT)*

## Benchmark Summary Table

| ADT            | Data Structure       | Insert        | Delete       | Search |
| -------------- | -------------------- | ------------- | ------------ | ------ |
| FILO QUEUE     | arraystack.cpp       | 0.001028s     | 0.000987s    |        |
| FIFO QUEUE     | sllist.cpp           | 0.006520s     | 0.003023s    |        |
| PRIORITY QUEUE | (to be implemented)  |               |              |        |
| DEQUE          | arraydeque.cpp       |               |              |        |
| LIST           | dllist.cpp           | 30s           | 30s          |        |
| SORTED SET     | skiplist.cpp         | 0.033042s     | 0.032600s    | 0.037054s   |
| SORTED SET     | redblacktrees.cpp    | 0.024520s     | 0.010506s    | 0.015013s   |
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

---

### FILO QUEUE (arraystack.cpp)
- Insert: `push()`
- Remove: `pop()`

<img width="289" height="159" alt="image" src="https://github.com/user-attachments/assets/e5052182-649b-4e1a-8285-7df141025a81" />

---

### FIFO QUEUE (sllist.cpp)

- Insert: `enqueue()` / `add()`
- Delete: `dequeue()` / `remove()`
- Additional Function (Twist):
   - Sorted SLList (`addSort()`) – inserts elements in sorted order instead of always adding at the tail (no longer strictly FIFO)

  *Note:* This function is independent; the ADT itself still follows FIFO behavior.

<img width="299" height="158" alt="image" src="https://github.com/user-attachments/assets/db43992b-08ca-4249-882d-722552ebd8ec" />

---

### SORTED SET (skiplist.cpp)

- Insert: `add()`
- Delete: `remove()`
- Search: `find()`
- Additional Functions (Twist):
   - Reverse Skiplist (Descending Order) – `add2()`, `remove2()`, `find2()`  
        - Implements a skiplist that maintains elements in descending order.

  *Note:* These functions are independent; the ADT itself still follows standard Sorted Set behavior.
  
<img width="274" height="248" alt="image" src="https://github.com/user-attachments/assets/2913f7b3-e5ac-4abf-8e34-b562d0b75154" />

---

### SORTED SET (redblacktrees.cpp)

- Insert: `add()`
- Delete: `remove()`
- Search: `find()`

<img width="264" height="182" alt="image" src="https://github.com/user-attachments/assets/06b29aa6-cdca-49ee-bb0a-237f3117d5e3" />
