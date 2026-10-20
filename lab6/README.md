# Quick Reference: Heap Sort & Quick Sort

Below are compact notes and short examples for Heap Sort and Quick Sort in C++.

---

# 1. Heap Sort

**Heap Sort** is a comparison-based sorting algorithm that uses a Binary Heap.

**Header:**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
```

**Idea:**

1. Build a Max Heap.
2. Swap the root (maximum) with the last element.
3. Reduce the heap size.
4. Restore the Max Heap property.
5. Repeat until the array is sorted.

**Complexity:**

- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n log n)
- Extra Space: O(1)

**Properties:**

- In-place sorting
- Not stable
- Uses a Binary Heap
- Guaranteed O(n log n) time

---

# 2. Max Heap Structure

A Max Heap is a complete binary tree where:

```text
Parent >= Children
```

Example:

```text
        50
       /  \
      30   40
     / \   /
    10 20 35
```

Array representation:

```text
Index:  0   1   2   3   4   5

Array: [50, 30, 40, 10, 20, 35]
```

**Heap Index Formulas:**

```cpp
// Parent (for i > 0)
int parent = (i - 1) / 2;

// Left child
int left = 2 * i + 1;

// Right child
int right = 2 * i + 2;
```

---

# 3. Heapify Down

Heapify Down restores the Max Heap property.

**Idea:**

1. Compare parent with children.
2. Find the largest element.
3. Swap parent with the largest child.
4. Continue until the heap property is restored.

### Code

```cpp
void heapify(vector<int>& a, int n, int i) {
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest]) {
        largest = left;
    }

    if (right < n && a[right] > a[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
```

**Complexity:** O(log n)

---

# 4. Heap Sort Implementation

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify(vector<int>& a, int n, int i) {
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest]) {
        largest = left;
    }

    if (right < n && a[right] > a[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(vector<int>& a) {
    int n = a.size();

    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    // Extract maximum one by one
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main() {
    vector<int> a = {12, 11, 13, 5, 6, 7};

    heapSort(a);

    for (int x : a) {
        cout << x << " ";
    }

    // Output: 5 6 7 11 12 13
}
```

---

# 5. How Heap Sort Works

Example:

```text
Original array:

[4, 10, 3, 5, 1]
```

### Step 1: Build Max Heap

```text
        10
       /  \
      5    3
     / \
    4   1
```

Array:

```text
[10, 5, 3, 4, 1]
```

### Step 2: Move Maximum to the End

Swap root with last element:

```text
[1, 5, 3, 4 | 10]
```

Restore heap:

```text
[5, 4, 3, 1 | 10]
```

### Step 3: Repeat

```text
[1, 4, 3 | 5, 10]
```

Restore heap:

```text
[4, 1, 3 | 5, 10]
```

Continue:

```text
[3, 1 | 4, 5, 10]
```

Final:

```text
[1, 3, 4, 5, 10]
```

---

# 6. Heap Sort Using STL

C++ provides heap algorithms in `<algorithm>`.

### Example

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> a = {5, 2, 8, 1, 9, 3};

    make_heap(a.begin(), a.end());

    sort_heap(a.begin(), a.end());

    for (int x : a) {
        cout << x << " ";
    }

    // Output: 1 2 3 5 8 9
}
```

**Functions:**

| Function | Description | Complexity |
|---|---|---|
| `make_heap()` | Build a heap | O(n) |
| `push_heap()` | Insert into heap | O(log n) |
| `pop_heap()` | Move maximum to end | O(log n) |
| `sort_heap()` | Sort a heap | O(n log n) |

---

# 7. Quick Sort

**Quick Sort** is a sorting algorithm based on the Divide and Conquer technique.

**Idea:**

1. Choose a pivot.
2. Partition the array around the pivot.
3. Place smaller elements on the left.
4. Place larger elements on the right.
5. Recursively sort both parts.

**Complexity:**

- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n²)
- Extra Space: O(log n) average recursion stack

**Properties:**

- Divide and Conquer
- Usually in-place
- Not stable
- Very fast in practice
- Performance depends on pivot selection

---

# 8. Pivot in Quick Sort

A **pivot** is an element used to divide the array into two parts.

Example:

```text
Array:

[8, 3, 1, 7, 0, 10, 2]

Pivot = 2
```

After partition:

```text
[1, 0 | 2 | 7, 3, 10, 8]
         ^
       Pivot
```

Left side:

```text
Elements < pivot
```

Right side:

```text
Elements > pivot
```

The pivot is now in its final sorted position.

**Common pivot choices:**

- First element
- Last element
- Middle element
- Random element
- Median of three

---

# 9. Partition Function

The partition function rearranges elements around the pivot.

This example uses the **Lomuto Partition Scheme**.

The last element is selected as the pivot.

### Code

```cpp
int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);

    return i + 1;
}
```

**Complexity:** O(n)

**Important:**

```cpp
int pivot = a[high];
```

Selects the last element as the pivot.

```cpp
if (a[j] <= pivot)
```

Moves elements smaller than or equal to the pivot to the left.

```cpp
swap(a[i + 1], a[high]);
```

Places the pivot in its final sorted position.

---

# 10. Quick Sort Implementation

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);

    return i + 1;
}

void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main() {
    vector<int> a = {10, 7, 8, 9, 1, 5};

    quickSort(a, 0, a.size() - 1);

    for (int x : a) {
        cout << x << " ";
    }

    // Output: 1 5 7 8 9 10
}
```

---

# 11. How Quick Sort Works

Example:

```text
Array:

[8, 3, 1, 7, 0, 10, 2]
```

### Step 1: Choose Pivot

```text
Pivot = 2
```

Partition:

```text
[1, 0 | 2 | 7, 3, 10, 8]
```

### Step 2: Sort Left Part

```text
[1, 0]
```

Choose pivot `0`:

```text
[0, 1]
```

### Step 3: Sort Right Part

```text
[7, 3, 10, 8]
```

Choose pivot `8`:

```text
[7, 3 | 8 | 10]
```

Sort `[7, 3]`:

```text
[3, 7]
```

### Final Result

```text
[0, 1, 2, 3, 7, 8, 10]
```

---

# 12. Quick Sort Recursion

Quick Sort recursively divides the array.

```text
        [8, 3, 1, 7, 0, 10, 2]
                   |
                 pivot 2
                   |
        -----------------------
        |          |          |
      [1, 0]      [2]    [7, 3, 10, 8]
        |                     |
      [0, 1]             [3, 7, 8, 10]
        |                     |
        -----------------------
                   |
        [0, 1, 2, 3, 7, 8, 10]
```

Base condition:

```cpp
if (low >= high) {
    return;
}
```

This means the subarray has zero or one element and is already sorted.

---

# 13. Quick Sort Pivot Selection

The choice of pivot affects performance.

### Last Element

```cpp
int pivot = a[high];
```

Simple but may cause O(n²) for already sorted arrays.

### First Element

```cpp
int pivot = a[low];
```

Also simple but can cause unbalanced partitions.

### Middle Element

```cpp
int mid = low + (high - low) / 2;
int pivot = a[mid];
```

May improve performance for some input patterns.

### Random Pivot

```cpp
int randomIndex = low + rand() % (high - low + 1);

swap(a[randomIndex], a[high]);
```

Then use the Lomuto partition function.

Random pivot selection reduces the chance of consistently unbalanced partitions.

---

# 14. Quick Sort vs Heap Sort

| Feature | Quick Sort | Heap Sort |
|---|---|---|
| Technique | Divide and Conquer | Binary Heap |
| Best Case | O(n log n) | O(n log n) |
| Average Case | O(n log n) | O(n log n) |
| Worst Case | O(n²) | O(n log n) |
| Extra Space | O(log n) average | O(1) |
| Stable | No | No |
| In-place | Usually | Yes |
| Main Operation | Partition | Heapify |
| Typical Performance | Often faster | Predictable |

**Important:**

- Quick Sort is often faster in practice.
- Heap Sort guarantees O(n log n).
- Quick Sort performance depends on partition balance.
- Heap Sort uses a Max Heap for ascending sorting.

---

# 15. STL sort()

C++ provides the `sort()` function.

**Header:**

```cpp
#include <algorithm>
```

### Ascending Order

```cpp
vector<int> a = {5, 2, 8, 1, 9};

sort(a.begin(), a.end());

// Result: 1 2 5 8 9
```

### Descending Order

```cpp
sort(a.begin(), a.end(), greater<int>());

// Result: 9 8 5 2 1
```

**Complexity:** O(n log n)

**Note:** C++ `std::sort()` is not necessarily pure Quick Sort or Heap Sort.

Many implementations use **Introsort**, which combines multiple sorting techniques.

---

# 16. Time Complexity

| Algorithm | Best | Average | Worst | Extra Space |
|---|---|---|---|---|
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) average |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Bubble Sort | O(n)* | O(n²) | O(n²) | O(1) |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) |

*Bubble Sort achieves O(n) in the best case with an early-exit optimization.*

---

# 17. Quick Cheat Sheet

## Heap Sort

```cpp
// Build Max Heap
for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(a, n, i);
}

// Extract maximum
for (int i = n - 1; i > 0; i--) {
    swap(a[0], a[i]);
    heapify(a, i, 0);
}
```

## Quick Sort

```cpp
void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}
```

## STL Sorting

```cpp
// Ascending
sort(a.begin(), a.end());

// Descending
sort(a.begin(), a.end(), greater<int>());

// Build Heap
make_heap(a.begin(), a.end());

// Heap Sort
sort_heap(a.begin(), a.end());
```

---

# 18. Remember

```text
HEAP SORT:

1. Build Max Heap
2. Swap root with last element
3. Reduce heap size
4. Heapify Down
5. Repeat

Time: O(n log n)
Space: O(1)
```

```text
QUICK SORT:

1. Choose pivot
2. Partition array
3. Sort left part
4. Sort right part
5. Repeat recursively

Average Time: O(n log n)
Worst Time: O(n²)
Average Space: O(log n)
```

```text
HEAP SORT vs QUICK SORT:

Heap Sort:
- Uses Binary Heap
- Guaranteed O(n log n)
- Constant extra space

Quick Sort:
- Uses Pivot
- Divide and Conquer
- Often faster in practice
- Worst case O(n²)
```

---

# Final Summary

| Algorithm | Main Idea | Time Complexity |
|---|---|---|
| Heap Sort | Build Heap + Extract Maximum | O(n log n) |
| Quick Sort | Pivot + Partition | O(n log n) average |

**Key Difference:**

Heap Sort uses a **Binary Heap**, while Quick Sort uses a **Pivot and Partitioning**.

Both algorithms are important for Data Structures and Algorithms (DSA).