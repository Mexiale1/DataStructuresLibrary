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

| ADT            | Data Structure                         |   Insert   |   Delete   |   Search   |   Unique   |
| -------------- | -------------------------------------- | :--------: | :--------: | :--------: | :--------: |
| FILO QUEUE     | arraystack.cpp                         | 0.0014107s | 0.0011280s |      -     |      -     |
| FIFO QUEUE     | sllist.cpp                             | 0.0038425s | 0.0027372s |      -     | 19.862600s |
| PRIORITY QUEUE | (to be implemented)                    |            |            |      -     |      -     |
| DEQUE          | arraydeque.cpp (`n` = 10,000,000)      | 0.2381200s | 0.1153190s |      -     |      -     |
| LIST           | dllist.cpp                             | 12.391300s | 13.107000s |      -     | 0.022589s  |
| SORTED SET     | skiplist.cpp                           | 0.0323282s | 0.0252603s | 0.0316317s | 0.0315943s |
| SORTED SET     | redblacktrees.cpp                      | 0.0188939s | 0.0119735s | 0.0137733s |
| UNSORTED SET   | chainedhashtable.cpp (`n` = 1,000,000) | 0.5640230s | 0.1643130s | 0.1619880s |
| GRAPH          | adjacencymatrix.cpp                    |            |            |            |

## Detailed Benchmarks Per ADT

Additional operations specific to each data structure are also evaluated.

## Summary of Functions Per ADT

| ADT            | Data Structure       | Functions Tested                                                |
| -------------- | -------------------- | --------------------------------------------------------------- |
| FILO QUEUE     | arraystack.cpp       | push, pop                                                       |
| FIFO QUEUE     | sllist.cpp           | add, remove, addSorted (unique)                                 |
| PRIORITY QUEUE | (to be implemented)  |                                                                 |
| DEQUE, LIST    | arraydeque.cpp       | addFirst, addLast, removeFirst, removeLast                      |
| LIST           | dllist.cpp           | add, remove, sort (unique)                                      |
| SORTED SET     | skiplist.cpp         | add, remove, find, (unique): add2, remove2, find2               |
| SORTED SET     | redblacktrees.cpp    | add, remove, find                                               |
| UNSORTED SET   | chainedhashtable.cpp | add, remove, find                                               |
| GRAPH          | adjacencymatrix.cpp  |                                                                 |

---

### FILO QUEUE (arraystack.cpp)

- Insert: `push(data)`
- Remove: `pop()`

_Note:_ The result is an average of 10 repeated runs.

```
Push: (max) 0.002553s  (min) 0.000983s  (avg) 0.0014107s
Pop:  (max) 0.001524s  (min) 0.000979s  (avg) 0.001128s
```
---

### FIFO QUEUE (sllist.cpp)

- Insert: `add(data)`
- Delete: `remove()`
- Unique: `addSorted(data)`
  - Elements are sorted in order(ascending) instead of always adding at the tail (no longer strictly FIFO)

   _Note:_ This function is independent; the ADT itself still follows FIFO behavior.

_Note_: The result is an average of 10 repeated runs.

```
Add:    (max) 0.008609s (min) 0.002987s (avg) 0.0038425s
Remove: (max) 0.006172s (min) 0.001997s (avg) 0.0027372s
Unique: (max) 35.0308s (min) 14.8552s (avg) 19.8626s
```
---

### LIST & DEQUE (arraydeque.cpp)

- Insert: `addFirst(data)`, `addLast(data)`
  - Half of `n` calls `addFirst(data)` method, while the other calls `addLast(data)`
- Delete: `removeFirst()`, `removeLast()`
  - Similar to Insert, each method is called for half of `n`

_Note:_ The result is an average of 10 repeated runs.

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

- Insert: `add(data)`
- Delete: `remove(data)`
- Search: `find(data)`
  - `data` is generated using std::rand()
- Unique: `add2(data)`, `remove2(data)`, `find2(data))`
  - Implements a skiplist that maintains elements in descending order.
   _Note:_ These functions are independent; the ADT itself still follows standard Sorted Set behavior.

_Note:_ The result is an average of 10 repeated runs.

```
Add:      (max) 0.038639s (min) 0.02752s (avg) 0.0323282s
Find:     (max) 0.052502s (min) 0.026083s (avg) 0.0316317s
Remove:   (max) 0.029134s (min) 0.022821s (avg) 0.0252603s
Add2:     (max) 0.038036s (min) 0.02859s (avg) 0.031464s
Find2:    (max) 0.047631s (min) 0.027574s (avg) 0.0315943s  
Remove2:  (max) 0.068427s (min) 0.021285s (avg) 0.0293766s
```

---

### SORTED SET (redblacktrees.cpp)

- Insert: `add(data)`
- Delete: `remove(data)`
- Search: `find(data)`
  - `data` is generated using std::rand() 

_Note:_ The result is an average of 10 repeated runs.

```
Add:    (max) 0.020566s (min) 0.016543s (avg) 0.0188939s
Find:   (max) 0.016741s (min) 0.010568s (avg) 0.0137733s
Remove: (max) 0.018495s (min) 0.009615s (avg) 0.0119735s
```
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
