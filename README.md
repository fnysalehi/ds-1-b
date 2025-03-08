# Data Structure Algorithms

This repository contains implementations of various data structure algorithms.

## Algorithms

### 1. Maximum Sum Submatrix Finder

Finds the maximum sum submatrix in a given matrix using Kadane's algorithm.

#### Examples

##### Example 1: Simple positive matrix
Input:
```
1,2,3;4,5,6;7,8,9
```
Output:
```
1,2,3;4,5,6;7,8,9
```
Sum: 45

##### Example 2: Matrix with negative numbers
Input:
```
-1,-2,-3;-4,5,6;-7,8,9
```
Output:
```
5,6;8,9
```
Sum: 28

### 2. Linked List Loop Detector

Detects and removes loops in a linked list using Floyd's Cycle-Finding Algorithm (also known as "tortoise and hare" algorithm).

#### Examples

##### Example 1: List with loop
Input:
```
1,1;2,2;3,1
```
Output:
```
1,1;2,2;3,Null
```

##### Example 2: List without loop
Input:
```
1,1;2,2;3,Null
```
Output:
```
1,1;2,2;3,Null
```

## Repository Structure

```
.
├── src/
│   ├── matrix/
│   │   ├── max_submatrix.cpp
│   │   ├── matrix_utils.h
│   │   └── matrix_utils.cpp
│   └── linked_list/
│       └── loop_detector.cpp
├── tests/
│   ├── matrix_tests.cpp
│   └── loop_detector_tests.cpp
├── benchmark/
│   └── benchmark.cpp
├── .gitignore
└── README.md
```
