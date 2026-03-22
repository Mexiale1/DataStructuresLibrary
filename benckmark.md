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
| FILO QUEUE     | arraystack.cpp       | 0.002045s     | 0.001007s    |        |
| FIFO QUEUE     | sllist.cpp           | 0.005570s     | 0.002014s    |        |
| PRIORITY QUEUE | (to be implemented)  |               |              |        |
| DEQUE          | arraydeque.cpp       |               |              |        |
| LIST           | dllist.cpp           | 30s           | 30s          |        |
| SORTED SET     | skiplist.cpp         | 0.330321s     | 0.054175s    | 0.323220s   |
| SORTED SET     | redblacktrees.cpp    | 0.019775s     | 0.014997s    | 0.007546s   |
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

<img width="288" height="157" alt="image" src="https://github.com/user-attachments/assets/2414d7b4-4bb1-488d-9209-43fcbfe8230f" />

---

### FIFO QUEUE (sllist.cpp)

- Insert: `enqueue()` / `add()`
- Delete: `dequeue()` / `remove()`
- Additional Function (Twist):
   - Sorted SLList (`addSort()`) – inserts elements in sorted order instead of always adding at the tail (no longer strictly FIFO)

  *Note:* This function is independent; the ADT itself still follows FIFO behavior.

<img width="265" height="181" alt="image" src="https://github.com/user-attachments/assets/d96340ff-372d-4240-8660-d7a2627bbf08" />

---

### SORTED SET (skiplist.cpp)

- Insert: `add()`
- Delete: `remove()`
- Search: `find()`
- Additional Functions (Twist):
   - Reverse Skiplist (Descending Order) – `add2()`, `remove2()`, `find2()`  
        - Implements a skiplist that maintains elements in descending order.

  *Note:* These functions are independent; the ADT itself still follows standard Sorted Set behavior.
  
<img width="264" height="241" alt="image" src="https://github.com/user-attachments/assets/4a9d6dda-7cd3-44ff-b6af-7d1ab12f9c7e" />

---

### SORTED SET (redblacktrees.cpp)

- Insert: `add()`
- Delete: `remove()`
- Search: `find()`

<img width="264" height="175" alt="image" src="https://github.com/user-attachments/assets/185fa6e5-3b82-4373-906f-9e05989c66d8" />

