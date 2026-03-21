## BENCHMARKS FOR EACH ADT

| ADT            | Data Structure       | Benchmarking                 |
| -------------- | -------------------- | ---------------------------- |
| FILO QUEUE     | arraystack.cpp       |                              |
| FIFO QUEUE     | sllist.cpp           |                              |
| PRIORITY QUEUE | uh oh                |                              |
| DEQUE          | arraydeque.cpp       |                              |
| LIST           | dllist.cpp           | Add:30s Sort:0.1s Remove:30s |
| SORTED SET     | skiplist.cpp         |                              |
| SORTED SET     | redblacktrees.cpp    |                              |
| UNSORTED SET   | chainedhashtable.cpp |                              |
| GRAPH          | adjacencymatrix.cpp  |                              |

## Benchmark Setup
- Number of elements: 1,000,000
- Data type: integers
- Data distribution: random values
- Timing method: std::chrono

**Note:** All benchmark files are located in the `benchmarks` folder.

## Operations Measured
1. **Insertion** – adding elements to the structure
2. **Deletion** – removing elements
3. **Search** – finding an element
4. **More**

## Benchmark Results

| ADT            | Structure            | Insert Time | Delete Time | Search Time |
|----------------|----------------------|------------|------------|-------------|
| FILO QUEUE     | arraystack.cpp       |            |            |             |
| FIFO QUEUE     | sllist.cpp           |            |            |             |
| PRIORITY QUEUE | (heap / sorted list) |            |            |             |
| DEQUE          | arraydeque.cpp       |            |            |             |
| LIST           | dllist.cpp           | 30s        | 30s        | -           |
| SORTED SET     | skiplist.cpp         |            |            |             |
| SORTED SET     | redblacktrees.cpp    |            |            |             |
| UNSORTED SET   | chainedhashtable.cpp |            |            |             |
| GRAPH          | adjacencymatrix.cpp  |            |            |             |

