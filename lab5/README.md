# Quick Reference: Priority Queue & Heap

Below are compact notes and short examples for Priority Queue and Heap in C++.

---

# 1. Priority Queue

A **Priority Queue** is a data structure where elements are removed based on their priority.

Unlike a normal queue (FIFO), the element with the highest priority is removed first.

**Header:**

```cpp
#include <queue>
```

**Type:**

```cpp
priority_queue<T>
```

**Operations:**

- `push(x)` - Insert an element.
- `pop()` - Remove the highest-priority element.
- `top()` - Access the highest-priority element.
- `empty()` - Check if the queue is empty.
- `size()` - Return the number of elements.

**Complexity:**

| Operation | Complexity |
|---|---|
| push() | O(log n) |
| pop() | O(log n) |
| top() | O(1) |
| empty() | O(1) |
| size() | O(1) |

---

# 2. Max Heap (Default Priority Queue)

A **Max Heap** is a binary heap where the parent is greater than or equal to its children.

```text
        50
       /  \
      30   40
     / \   /
    10 20 35
```

**Rule:**

```text
Parent >= Children
```

The largest element is always at the root.

### Example

```cpp
#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(50);

    cout << pq.top() << endl; // 50

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    // Output: 50 30 20 10
}
```

**Note:** By default, C++ `priority_queue` is a Max Heap.

---

# 3. Min Heap

A **Min Heap** is a binary heap where the parent is smaller than or equal to its children.

```text
        10
       /  \
      20   15
     / \   /
    40 30 25
```

**Rule:**

```text
Parent <= Children
```

The smallest element is always at the root.

### Syntax

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

**Headers:**

```cpp
#include <queue>
#include <vector>
#include <functional>
```

### Example

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    cout << pq.top() << endl; // 5

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    // Output: 5 10 20 30
}
```

---

# 4. Max Heap vs Min Heap

| Feature | Max Heap | Min Heap |
|---|---|---|
| Root | Largest element | Smallest element |
| Parent | >= Children | <= Children |
| Default STL | Yes | No |
| top() | Maximum | Minimum |
| push() | O(log n) | O(log n) |
| pop() | O(log n) | O(log n) |

### Syntax Comparison

```cpp
// Max Heap
priority_queue<int> maxHeap;

// Min Heap
priority_queue<int, vector<int>, greater<int>> minHeap;
```

---

# 5. Heap Structure

A **Binary Heap** is a complete binary tree.

A complete binary tree means:

- All levels are completely filled except possibly the last.
- The last level is filled from left to right.

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

A heap can be stored in a vector without pointers.

---

# 6. Heap Index Formulas

For a 0-indexed array:

```cpp
// Parent index
int parent = (i - 1) / 2;

// Left child index
int left = 2 * i + 1;

// Right child index
int right = 2 * i + 2;
```

Example:

```text
        50 (0)
       /      \
    30 (1)   40 (2)
    /   \
 10 (3) 20 (4)
```

For index `1`:

```text
Parent = (1 - 1) / 2 = 0

Left Child = 2 * 1 + 1 = 3

Right Child = 2 * 1 + 2 = 4
```

**Important:** The parent formula is intended for `i > 0`.

---

# 7. Heap Insertion

When inserting an element:

1. Add the element at the end.
2. Compare it with its parent.
3. Swap if the heap property is violated.
4. Repeat until the heap property is restored.

This process is called **Heapify Up** or **Sift Up**.

### Example

Insert `60` into a Max Heap.

Before:

```text
        50
       /  \
      30   40
     / \
    10 20
```

Insert at the end:

```text
        50
       /  \
      30   40
     / \   /
    10 20 60
```

Swap with parent:

```text
        50
       /  \
      30   60
     / \   /
    10 20 40
```

Swap again:

```text
        60
       /  \
      30   50
     / \   /
    10 20 40
```

### Manual Heapify Up

```cpp
void heapifyUp(vector<int>& heap, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent] >= heap[i]) {
            break;
        }

        swap(heap[parent], heap[i]);
        i = parent;
    }
}
```

### Insert Function

```cpp
void insert(vector<int>& heap, int value) {
    heap.push_back(value);
    heapifyUp(heap, heap.size() - 1);
}
```

**Complexity:** O(log n)

---

# 8. Heap Deletion

In a Max Heap, deletion usually removes the root (maximum element).

Steps:

1. Replace the root with the last element.
2. Remove the last element.
3. Compare the new root with its children.
4. Swap with the larger child if needed.
5. Repeat until the heap property is restored.

This process is called **Heapify Down** or **Sift Down**.

### Manual Heapify Down

```cpp
void heapifyDown(vector<int>& heap, int i) {
    int n = heap.size();

    while (true) {
        int largest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < n && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest == i) {
            break;
        }

        swap(heap[i], heap[largest]);
        i = largest;
    }
}
```

### Delete Maximum

```cpp
void deleteMax(vector<int>& heap) {
    if (heap.empty()) {
        return;
    }

    heap[0] = heap.back();
    heap.pop_back();

    if (!heap.empty()) {
        heapifyDown(heap, 0);
    }
}
```

**Complexity:** O(log n)

---

# 9. STL Heap Functions

C++ provides heap algorithms in `<algorithm>`.

**Header:**

```cpp
#include <algorithm>
```

### make_heap()

Converts a vector into a Max Heap.

```cpp
vector<int> v = {10, 30, 20, 50, 40};

make_heap(v.begin(), v.end());

cout << v.front(); // 50
```

**Complexity:** O(n)

### push_heap()

Adds a new element to an existing heap.

```cpp
vector<int> v = {50, 30, 40, 10, 20};

v.push_back(60);

push_heap(v.begin(), v.end());

cout << v.front(); // 60
```

**Complexity:** O(log n)

### pop_heap()

Moves the maximum element to the end.

```cpp
vector<int> v = {50, 30, 40, 10, 20};

pop_heap(v.begin(), v.end());

cout << v.back(); // 50

v.pop_back();
```

**Complexity:** O(log n)

**Note:** `pop_heap()` does not remove the element from the vector. Use `pop_back()` afterward.

### sort_heap()

Sorts the heap in ascending order.

```cpp
vector<int> v = {10, 30, 20, 50, 40};

make_heap(v.begin(), v.end());

sort_heap(v.begin(), v.end());

for (int x : v) {
    cout << x << " ";
}

// Output: 10 20 30 40 50
```

**Complexity:** O(n log n)

---

# 10. Priority Queue with Pairs

Priority queues can store pairs.

By default, pairs are compared lexicographically:

1. Compare the first values.
2. If equal, compare the second values.

### Example

```cpp
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
    priority_queue<pair<int, int>> pq;

    pq.push({2, 100});
    pq.push({5, 200});
    pq.push({3, 300});

    while (!pq.empty()) {
        cout << pq.top().first << " "
             << pq.top().second << endl;

        pq.pop();
    }
}
```

Output:

```text
5 200
3 300
2 100
```

---

# 11. Min Heap with Pairs

Useful for algorithms such as Dijkstra.

```cpp
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;
```

Example:

```cpp
pq.push({10, 1});
pq.push({5, 2});
pq.push({20, 3});

cout << pq.top().first; // 5
```

The pair with the smallest first value has the highest priority.

---

# 12. Heap Sort

Heap Sort uses a heap to sort elements.

Steps:

1. Build a Max Heap.
2. Swap the root with the last element.
3. Reduce the heap size.
4. Restore the heap property.
5. Repeat.

### Example

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v = {5, 2, 8, 1, 9, 3};

    make_heap(v.begin(), v.end());

    sort_heap(v.begin(), v.end());

    for (int x : v) {
        cout << x << " ";
    }

    // Output: 1 2 3 5 8 9
}
```

**Complexity:**

```text
Time: O(n log n)
Extra Space: O(1)
```

---

# 13. Priority Queue vs Queue

| Feature | Queue | Priority Queue |
|---|---|---|
| Order | FIFO | Priority |
| Header | `<queue>` | `<queue>` |
| Insert | push() | push() |
| Remove | pop() | pop() |
| Access | front() | top() |
| Insert Complexity | O(1) | O(log n) |
| Remove Complexity | O(1) | O(log n) |

Example:

```cpp
queue<int> q;

q.push(10);
q.push(30);
q.push(20);

cout << q.front(); // 10
```

Priority Queue:

```cpp
priority_queue<int> pq;

pq.push(10);
pq.push(30);
pq.push(20);

cout << pq.top(); // 30
```

---

# 14. Complete Priority Queue Example

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main() {

    // Max Heap
    priority_queue<int> maxHeap;

    maxHeap.push(10);
    maxHeap.push(40);
    maxHeap.push(20);
    maxHeap.push(30);

    cout << "Max Heap: ";

    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    cout << endl;

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(10);
    minHeap.push(40);
    minHeap.push(20);
    minHeap.push(30);

    cout << "Min Heap: ";

    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    cout << endl;

    return 0;
}
```

Output:

```text
Max Heap: 40 30 20 10
Min Heap: 10 20 30 40
```

---

# 15. Time Complexity

| Operation | Complexity |
|---|---|
| Access Root | O(1) |
| Insert | O(log n) |
| Delete Root | O(log n) |
| Search Element | O(n) |
| Build Heap | O(n) |
| Heap Sort | O(n log n) |
| Get Size | O(1) |

**Important:** A heap is not a Binary Search Tree.

In a heap, only the parent-child ordering is guaranteed.

---

# Quick Cheat Sheet

```cpp
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

// Max Heap
priority_queue<int> maxHeap;

// Min Heap
priority_queue<int, vector<int>, greater<int>> minHeap;

// Insert
maxHeap.push(10);

// Get maximum
maxHeap.top();

// Remove maximum
maxHeap.pop();

// Check empty
maxHeap.empty();

// Size
maxHeap.size();

// Build heap from vector
make_heap(v.begin(), v.end());

// Insert into STL heap
v.push_back(x);
push_heap(v.begin(), v.end());

// Remove maximum from STL heap
pop_heap(v.begin(), v.end());
v.pop_back();

// Sort heap
sort_heap(v.begin(), v.end());

// Parent index (i > 0)
int parent = (i - 1) / 2;

// Left child
int left = 2 * i + 1;

// Right child
int right = 2 * i + 2;
```

---

# Remember

```text
Priority Queue:
Highest-priority element comes first.
```

```text
Max Heap:
Parent >= Children
Root = Maximum
```

```text
Min Heap:
Parent <= Children
Root = Minimum
```

```text
Heap Index Formulas:

Parent = (i - 1) / 2
Left   = 2 * i + 1
Right  = 2 * i + 2
```

```text
Heap Operations:

Insert      -> O(log n)
Delete Root -> O(log n)
Get Root    -> O(1)
Build Heap  -> O(n)
Heap Sort   -> O(n log n)
Search      -> O(n)
```

```text
Heapify Up   -> Used after insertion
Heapify Down -> Used after root deletion
```

**Important:**

- A Binary Heap is a complete binary tree.
- A Max Heap stores the maximum element at the root.
- A Min Heap stores the minimum element at the root.
- C++ `priority_queue` uses a Max Heap by default.
- A Heap does not keep all elements sorted.