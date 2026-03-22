## BENCHMARKS FOR EACH ADT

A benchmark is performed for each Abstract Data Type (ADT) to evaluate its performance under a consistent set of operations and conditions.

## Benchmark Setup and Operations Measured

All ADTs are benchmarked under the same conditions to ensure consistency and comparability.

**Benchmark Setup:**

- Number of elements as `n`: 100,000 (Unless specified)
- Data type `T`: integers
- Data distribution: random values (through `std::rand()`)
- Timing method: Date and Time library (using `<chrono>`)
- Note: All benchmark files are located in the `benchmarks` folder.

**Operations Measured:**

Note: The benchmarking numbers may by a result of one or multiple runs, which is decided through spread of results. This will be mentioned in the Detailed Benchmarks section.

Note2: Just as you would expect, some Data structures will not test all operations due to the nature of the ADT it realizes.

1. **Insertion** – adding elements to the data structure  
   _(Insert `n` integer values into each ADT)_

2. **Deletion** – removing elements from the data structure  
   _(Remove `n` elements from each ADT)_

3. **Search / Find** – locating elements within the data structure  
   _(Search for `n` elements in each ADT)_

4. **Unique** - May differ from each data structure, can be some twist added.

## Benchmark Summary Table

| ADT            | Data Structure                         |  Insert   |  Delete   |  Search   |  Unique   |
| -------------- | -------------------------------------- | :-------: | :-------: | :-------: | :-------: |
| FILO QUEUE     | arraystack.cpp                         | 0.001028s | 0.000987s |           |
| FIFO QUEUE     | sllist.cpp                             | 0.006520s | 0.003023s |           |
| PRIORITY QUEUE | (to be implemented)                    |           |           |           |
| DEQUE          | arraydeque.cpp (`n` = 10,000,000)      | 0.238120s | 0.115319s |     -     |     -     |
| LIST           | dllist.cpp                             | 12.39130s | 13.10700s |     -     | 0.022589s |
| SORTED SET     | skiplist.cpp                           | 0.033042s | 0.032600s | 0.037054s |
| SORTED SET     | redblacktrees.cpp                      | 0.024520s | 0.010506s | 0.015013s |
| UNSORTED SET   | chainedhashtable.cpp (`n` = 1,000,000) | 0.564023s | 0.164313s | 0.161988s |
| GRAPH          | adjacencymatrix.cpp                    |           |           |           |

---

## Detailed Benchmarks Per ADT

Additional operations specific to each data structure are also evaluated.

## Summary of Functions Per ADT

| ADT            | Data Structure       | Functions Tested                                                |
| -------------- | -------------------- | --------------------------------------------------------------- |
| FILO QUEUE     | arraystack.cpp       |                                                                 |
| FIFO QUEUE     | sllist.cpp           | enqueue / add, dequeue / remove, add (Sorted) (unique)          |
| PRIORITY QUEUE | (to be implemented)  |                                                                 |
| DEQUE, LIST    | arraydeque.cpp       | addFirst, addLast, removeFirst, removeLast                      |
| LIST           | dllist.cpp           | add, remove, sort (unique)                                      |
| SORTED SET     | skiplist.cpp         | add, remove, find, add(Reverse), remove(Reverse), find(Reverse) |
| SORTED SET     | redblacktrees.cpp    | add, remove, find                                               |
| UNSORTED SET   | chainedhashtable.cpp | add, remove, find                                               |
| GRAPH          | adjacencymatrix.cpp  |                                                                 |

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

  _Note:_ This function is independent; the ADT itself still follows FIFO behavior.

<img width="299" height="158" alt="image" src="https://github.com/user-attachments/assets/db43992b-08ca-4249-882d-722552ebd8ec" />

---

### LIST & DEQUE (arraydeque.cpp)

- Insert: `addFirst(data)`, `addLast(data)`
  - Half of `n` calls `addFirst(data)` method, while the other calls `addLast(data)`
- Delete: `removeFirst()`, `removeLast()`
  - Similar to Insert, each method is called for half of `n`

Note: The result is an average of 10 repeated runs.

```
Add: (max) 0.265644s (min) 0.229743s (avg) 0.23812s
Remove: (max) 0.124376s (min) 0.109699s (avg) 0.115319s
```

---

### LIST (dllist.cpp)

- Insert: `add(index, data)`
  - For this test, both the `index` and `data` are randomized using `std::rand()`
- Delete: `remove(index)`
  - For this test, `index` is randomized using the same function
- Unique: `mySort()`:
  - Using the `Merge Sort` algorithm

  _Note:_ The results were averaged by 5 test cases due to variance. This variance may be due to the randomized indexing. Set only to 5 test cases, as 10 takes to long and crashes the program.

```
Add: (max) 13.1311s (min) 11.3485s (avg) 12.3913s
Sort: (max) 0.0242956s (min) 0.0217152s (avg) 0.0225892s
Remove: (max) 13.3233s (min) 12.954s (avg) 13.107s
```

---

### SORTED SET (skiplist.cpp)

- Insert: `add()`
- Delete: `remove()`
- Search: `find()`
- Additional Functions (Twist):
  - Reverse Skiplist (Descending Order) – `add2()`, `remove2()`, `find2()`
    - Implements a skiplist that maintains elements in descending order.

  _Note:_ These functions are independent; the ADT itself still follows standard Sorted Set behavior.

<img width="274" height="248" alt="image" src="https://github.com/user-attachments/assets/2913f7b3-e5ac-4abf-8e34-b562d0b75154" />

---

### SORTED SET (redblacktrees.cpp)

- Insert: `add()`
- Delete: `remove()`
- Search: `find()`

<img width="264" height="182" alt="image" src="https://github.com/user-attachments/assets/06b29aa6-cdca-49ee-bb0a-237f3117d5e3" />

---

### UNSORTED SET (chainedhashtable.cpp)

- Insert: `add(data)`
- Delete: `remove(data)`
- Find: `find(data)`

  _Note:_ The results were averaged by 10 test cases.

  ```
  Minimum time (add): 0.508484s
  Maximum time (add): 0.674754s
  Minimum time (find): 0.153739s
  Maximum time (find): 0.177382s
  Minimum time (remove): 0.156726s
  Maximum time (remove): 0.17758s
  Average time (add): 0.564023s
  Average time (find): 0.161988s
  Average time (remove): 0.164313s
  ```
