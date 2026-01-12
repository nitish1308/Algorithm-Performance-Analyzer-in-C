# Algorithm Performance Analyzer in C

## Project Overview
This project is a **menu-driven C application** that analyzes and compares the performance of fundamental **sorting and searching algorithms**.  
It allows users to generate arrays in **manual, random, and worst-case scenarios**, execute multiple algorithms, and observe **actual execution time along with theoretical time and space complexity**.

The project is designed for **Data Structures & Algorithms learning, GATE preparation, and technical interviews**.

---

## Objectives
- Implement classic sorting and searching algorithms in C
- Compare real execution time using CPU clock measurement
- Demonstrate theoretical time and space complexity
- Understand algorithm behavior under different input conditions
- Build a modular, memory-safe C application

---

## Algorithms Implemented

### Sorting Algorithms

| Algorithm        | Time Complexity (Worst Case) | Space Complexity |
|------------------|------------------------------|------------------|
| Bubble Sort      | O(n²)                        | O(1)             |
| Insertion Sort   | O(n²)                        | O(1)             |
| Merge Sort       | O(n log n)                   | O(n)             |
| Quick Sort       | O(n log n)*                  | O(n) worst case  |

\* Quick Sort worst case becomes O(n²) depending on pivot selection.

### Searching Algorithm

| Algorithm     | Time Complexity |
|--------------|-----------------|
| Linear Search| O(n)            |

---

## Features
- Manual array input
- Random array generation
- Worst-case input generation (descending order)
- Display current array
- Execution time comparison of all sorting algorithms
- Linear search operation
- Dynamic memory allocation using `malloc` and `free`
- Clear tabular performance output

---

## Input Modes
1. **Manual Input** – User enters array size and elements.
2. **Random Input** – Array filled with random values (0–999).
3. **Worst Case Input** – Array generated in descending order.

---

## Sample Output

Algorithm Time(s) Time Complexity Space

Bubble Sort 0.002341 O(n^2) O(1)
Insertion Sort 0.001912 O(n^2) O(1)
Merge Sort 0.000432 O(n log n) O(n)
Quick Sort 0.000389 O(n log n)* O(n) worst


---

## Code Structure

main.c
├── Utility Functions
│ ├── freeArray()
│ ├── copyArray()
│ ├── displayArray()
│
├── Input Modules
│ ├── inputArrayManual()
│ ├── inputArrayRandom()
│ ├── inputArrayWorstCase()
│
├── Sorting Algorithms
│ ├── bubbleSort()
│ ├── insertionSort()
│ ├── mergeSort()
│ ├── quickSort()
│
├── Searching
│ ├── linearSearch()
│
└── Analysis
├── runComparison()
