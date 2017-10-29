c-sorting-algorithms
---

Custom implementations of sorting algorithms in C

## Installation
```
./configure
make
make install
```

## Usage
```
benchmark [algorithm... ]
```

## Example
```
benchmark quick bubble
```

## Algorithms
- merge
- insertion
- selection
- bubble
- quick
- heap
- counting
- radix

## Benchmark test cases
- Warmup 3 iterations
- Test 10 iterations
- Average test iterations
- Sort 10/100/1000/MAX_INT size arrays
- Arrays to be sorted: randomly-sorted, pre-sorted, reverse-sorted
- New input array to be sorted for each test iteration
- Same input array used for each # test iteration across algorithms