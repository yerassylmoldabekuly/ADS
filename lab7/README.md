# Quick Reference: Merge Sort

Below are compact notes and short examples for Merge Sort in C++.

---

# 1. Merge Sort

**Merge Sort** is a sorting algorithm based on the **Divide and Conquer** technique.

**Headers:**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
```

**Idea:**

1. Divide the array into two halves.
2. Recursively sort the left half.
3. Recursively sort the right half.
4. Merge the two sorted halves.
5. Repeat until the entire array is sorted.

**Complexity:**

- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n log n)
- Extra Space: O(n)

**Properties:**

- Divide and Conquer
- Stable sorting
- Recursive algorithm
- Not in-place in the standard array implementation
- Guaranteed O(n log n) time

---

# 2. How Merge Sort Works

Example:

```text
Original Array:

[8, 3, 5, 4, 7, 6, 1, 2]
```

### Step 1: Divide

Split the array into two halves.

```text
        [8, 3, 5, 4, 7, 6, 1, 2]
                    |
          ---------------------
          |                   |
      [8, 3, 5, 4]       [7, 6, 1, 2]
```

Continue dividing:

```text
              [8, 3, 5, 4]
                    |
              -----------
              |         |
           [8, 3]     [5, 4]
             |           |
           -----       -----
           |   |       |   |
          [8] [3]     [5] [4]
```

### Step 2: Merge

Merge individual elements in sorted order.

```text
[8] + [3] -> [3, 8]

[5] + [4] -> [4, 5]
```

Then:

```text
[3, 8] + [4, 5] -> [3, 4, 5, 8]
```

### Step 3: Final Merge

```text
Left Sorted:  [3, 4, 5, 8]

Right Sorted: [1, 2, 6, 7]
```

Merge:

```text
[1, 2, 3, 4, 5, 6, 7, 8]
```

---

# 3. Divide and Conquer

Merge Sort uses three main steps:

```text
DIVIDE
Split the array into two halves.

CONQUER
Recursively sort each half.

COMBINE
Merge the sorted halves.
```

Example:

```text
            [6, 3, 8, 2]
                  |
           ---------------
           |             |
         [6, 3]        [8, 2]
           |             |
         -----         -----
         |   |         |   |
        [6] [3]       [8] [2]
         |   |         |   |
         -----         -----
           |             |
         [3, 6]        [2, 8]
           |             |
           ---------------
                  |
            [2, 3, 6, 8]
```

---

# 4. Merge Function

The `merge()` function combines two sorted subarrays into one sorted subarray.

**Parameters:**

```cpp
merge(a, left, mid, right);
```

Where:

```text
left  -> Starting index

mid   -> Middle index

right -> Ending index
```

The two sorted parts are:

```text
a[left ... mid]

a[mid + 1 ... right]
```

### Code

```cpp
void merge(vector<int>& a, int left, int mid, int right) {

    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {

        if (a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        }
        else {
            temp.push_back(a[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(a[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(a[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        a[left + k] = temp[k];
    }
}
```

**Complexity:** O(n) for merging a total of n elements.

---

# 5. How Merge Function Works

Example:

```text
Left Array:  [2, 5, 8]

Right Array: [1, 3, 7]
```

We use two pointers:

```text
i -> Left Array

j -> Right Array
```

### Step 1

Compare:

```text
2 and 1
```

Since:

```text
1 < 2
```

Add `1` to the result.

```text
Result: [1]
```

Move `j`.

### Step 2

Compare:

```text
2 and 3
```

Since:

```text
2 < 3
```

Add `2`.

```text
Result: [1, 2]
```

Move `i`.

### Step 3

Compare:

```text
5 and 3
```

Add `3`.

```text
Result: [1, 2, 3]
```

### Step 4

Compare:

```text
5 and 7
```

Add `5`.

```text
Result: [1, 2, 3, 5]
```

### Step 5

Compare:

```text
8 and 7
```

Add `7`.

```text
Result: [1, 2, 3, 5, 7]
```

### Step 6

Copy remaining elements.

```text
Result: [1, 2, 3, 5, 7, 8]
```

---

# 6. Merge Sort Function

The `mergeSort()` function recursively divides the array.

### Code

```cpp
void mergeSort(vector<int>& a, int left, int right) {

    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(a, left, mid);

    mergeSort(a, mid + 1, right);

    merge(a, left, mid, right);
}
```

### Explanation

```cpp
if (left >= right) {
    return;
}
```

Base condition: stop when the subarray contains one or zero elements.

```cpp
int mid = left + (right - left) / 2;
```

Find the middle index.

```cpp
mergeSort(a, left, mid);
```

Sort the left half.

```cpp
mergeSort(a, mid + 1, right);
```

Sort the right half.

```cpp
merge(a, left, mid, right);
```

Merge the two sorted halves.

---

# 7. Complete Merge Sort Implementation

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& a, int left, int mid, int right) {

    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {

        if (a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        }
        else {
            temp.push_back(a[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(a[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(a[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        a[left + k] = temp[k];
    }
}

void mergeSort(vector<int>& a, int left, int right) {

    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(a, left, mid);

    mergeSort(a, mid + 1, right);

    merge(a, left, mid, right);
}

int main() {

    vector<int> a = {8, 3, 5, 4, 7, 6, 1, 2};

    mergeSort(a, 0, a.size() - 1);

    for (int x : a) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
```

**Output:**

```text
1 2 3 4 5 6 7 8
```

---

# 8. Understanding the Pointers

The merge function uses three important variables.

```cpp
int i = left;
int j = mid + 1;
```

Where:

```text
i -> Current element in left half

j -> Current element in right half

temp -> Stores sorted elements
```

Example:

```text
Array:

[2, 5, 8 | 1, 3, 7]
 ^         ^
 i         j
```

Compare:

```cpp
if (a[i] <= a[j]) {
    temp.push_back(a[i]);
    i++;
}
else {
    temp.push_back(a[j]);
    j++;
}
```

If the left element is smaller:

```text
Move i ->
```

If the right element is smaller:

```text
Move j ->
```

**Important:** The pointers move forward independently.

---

# 9. Why Do We Need Remaining Elements?

The main loop:

```cpp
while (i <= mid && j <= right)
```

stops when one of the two halves is exhausted.

Example:

```text
Left:  [1, 2]

Right: [3, 4, 5]
```

After comparing:

```text
temp = [1, 2]
```

The left half is finished, but the right half still contains:

```text
[3, 4, 5]
```

Therefore, we need:

```cpp
while (i <= mid) {
    temp.push_back(a[i]);
    i++;
}

while (j <= right) {
    temp.push_back(a[j]);
    j++;
}
```

These loops copy all remaining elements.

---

# 10. Time Complexity

Merge Sort divides the array into two halves.

```text
n -> n/2 -> n/4 -> n/8 -> ... -> 1
```

Number of levels:

```text
O(log n)
```

At each level, merging all subarrays requires:

```text
O(n)
```

Therefore:

```text
O(n) * O(log n) = O(n log n)
```

### Complexity Table

| Case | Time Complexity |
|---|---|
| Best Case | O(n log n) |
| Average Case | O(n log n) |
| Worst Case | O(n log n) |
| Extra Space | O(n) |

**Important:** Merge Sort guarantees O(n log n) time.

---

# 11. Space Complexity

Merge Sort requires additional memory for merging.

Example:

```cpp
vector<int> temp;
```

The temporary vector stores the merged elements.

```text
Array Size: n

Extra Memory: O(n)
```

The recursion stack requires:

```text
O(log n)
```

Overall auxiliary space:

```text
O(n)
```

---

# 12. Stable Sorting

Merge Sort is a **stable sorting algorithm** when equal elements preserve their original order.

Example:

```text
Original:

[(3,A), (1,B), (3,C)]
```

After sorting by the first value:

```text
[(1,B), (3,A), (3,C)]
```

The relative order of equal elements remains unchanged.

In our merge function:

```cpp
if (a[i] <= a[j])
```

Using `<=` ensures that equal elements from the left half are selected first.

---

# 13. Merge Sort vs Quick Sort vs Heap Sort

| Feature | Merge Sort | Quick Sort | Heap Sort |
|---|---|---|---|
| Technique | Divide and Conquer | Divide and Conquer | Binary Heap |
| Best Case | O(n log n) | O(n log n) | O(n log n) |
| Average Case | O(n log n) | O(n log n) | O(n log n) |
| Worst Case | O(n log n) | O(n²) | O(n log n) |
| Extra Space | O(n) | O(log n) average | O(1) |
| Stable | Yes | No | No |
| Main Operation | Merge | Partition | Heapify |

### When to Use Merge Sort

Merge Sort is useful when:

- Stable sorting is required.
- Guaranteed O(n log n) time is important.
- Sorting linked lists.
- Working with large datasets using external sorting.

---

# 14. STL stable_sort()

C++ provides `stable_sort()`.

**Header:**

```cpp
#include <algorithm>
```

### Example

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> a = {5, 2, 8, 1, 9};

    stable_sort(a.begin(), a.end());

    for (int x : a) {
        cout << x << " ";
    }

    // Output: 1 2 5 8 9
}
```

**Important:**

- `stable_sort()` preserves the relative order of equal elements.
- It is not required to use Merge Sort internally.
- It typically uses O(n) additional memory.
- With sufficient extra memory, it performs O(n log n) comparisons.

---

# 15. Merge Sort vs STL sort()

### Merge Sort

```cpp
mergeSort(a, 0, a.size() - 1);
```

### STL sort()

```cpp
sort(a.begin(), a.end());
```

### STL stable_sort()

```cpp
stable_sort(a.begin(), a.end());
```

| Function | Stable | Complexity |
|---|---|---|
| `mergeSort()` | Yes | O(n log n) |
| `sort()` | No guarantee | O(n log n) |
| `stable_sort()` | Yes | O(n log n) with sufficient extra memory |

---

# 16. Quick Cheat Sheet

## Merge Sort Function

```cpp
void mergeSort(vector<int>& a, int left, int right) {

    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(a, left, mid);

    mergeSort(a, mid + 1, right);

    merge(a, left, mid, right);
}
```

## Merge Function

```cpp
void merge(vector<int>& a, int left, int mid, int right) {

    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {

        if (a[i] <= a[j]) {
            temp.push_back(a[i++]);
        }
        else {
            temp.push_back(a[j++]);
        }
    }

    while (i <= mid) {
        temp.push_back(a[i++]);
    }

    while (j <= right) {
        temp.push_back(a[j++]);
    }

    for (int k = 0; k < temp.size(); k++) {
        a[left + k] = temp[k];
    }
}
```

## Usage

```cpp
vector<int> a = {5, 3, 8, 1, 2};

mergeSort(a, 0, a.size() - 1);
```

## STL

```cpp
// Normal sorting
sort(a.begin(), a.end());

// Stable sorting
stable_sort(a.begin(), a.end());
```

---

# 17. Remember

```text
MERGE SORT:

1. Divide array into two halves
2. Recursively sort left half
3. Recursively sort right half
4. Merge sorted halves
5. Repeat
```

```text
DIVIDE AND CONQUER:

Divide  -> Split into halves

Conquer -> Sort each half

Combine -> Merge sorted halves
```

```text
MERGE POINTERS:

i -> Left half

j -> Right half

temp -> Sorted result
```

```text
COMPLEXITY:

Best:    O(n log n)

Average: O(n log n)

Worst:   O(n log n)

Space:   O(n)
```

```text
IMPORTANT:

Merge Sort is STABLE.

Merge Sort uses RECURSION.

Merge Sort uses DIVIDE AND CONQUER.

Merge Sort guarantees O(n log n).
```

---

# Final Summary

| Algorithm | Main Idea | Average Time |
|---|---|---|
| Merge Sort | Divide + Merge | O(n log n) |
| Quick Sort | Pivot + Partition | O(n log n) |
| Heap Sort | Heapify + Extract Max | O(n log n) |

**Key Difference:**

- **Merge Sort:** Divides the array and merges sorted halves.
- **Quick Sort:** Uses a pivot to partition the array.
- **Heap Sort:** Uses a Binary Heap to sort elements.

**Most Important Functions:**

```cpp
mergeSort(a, left, right);

merge(a, left, mid, right);
```