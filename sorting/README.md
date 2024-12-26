# Sorting Algorithms Comparison

| Algorithm         | Best Case (Ω) | Average Case (Θ) | Worst Case (Big-O) | Space Complexity | Implementation |
|---------------|-------------------------|---------------------------|--------------------------|------------------|-----------------------------|
| **Bubble Sort** | O(n)               | O(n^2)                | O(n^2)               | O(1)         | Easy                        |
| **Merge Sort**  | O(n log n)        | O(n log n)           | O(n log n)          | O(n)         | Moderate                    |
| **Insertion Sort** | O(n)           | O(n^2)                | O(n^2)               | O(1)         | Easy                        |
| **Quick Sort**  | O(n log n)        | O(n log n)           | O(n^2)               | O(log n)*   | Moderate                    |
| **Selection Sort** | O(n^2)         | O(n^2)                | O(n^2)               | O(1)         | Easy                        |
| **Heap Sort**   | O(n log n)        | O(n log n)           | O(n log n)          | O(1)         | Moderate                    |

\* Quick Sort has O(\log n) space complexity due to recursion.

### 1. Bubble Sort
Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process is repeated until the list is sorted.
