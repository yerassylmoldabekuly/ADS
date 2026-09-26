# Quick Reference: Binary Search

Below are compact notes and short examples for Binary Search in C++.

---

## Binary Search

Binary Search is used to find an element in a **sorted array**.

**Complexity:** `O(log n)`

**Requirement:** The array must be sorted.

### Basic Binary Search

```cpp
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& a, int target) {
    int left = 0;
    int right = a.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] == target) {
            return mid;
        }
        else if (a[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> a = {1, 3, 5, 7, 9};

    cout << binarySearch(a, 7); // 3
}
```

---

## How Binary Search Works

Example:

```text
array = [1, 3, 5, 7, 9, 11, 13]
target = 11
```

Start:

```text
left = 0
right = 6
mid = 3

[1, 3, 5, 7, 9, 11, 13]
           ^
          mid
```

Since:

```text
11 > 7
```

Search the right half:

```cpp
left = mid + 1;
```

If the target is smaller:

```cpp
right = mid - 1;
```

---

## Finding `mid`

Recommended:

```cpp
int mid = left + (right - left) / 2;
```

Instead of:

```cpp
int mid = (left + right) / 2;
```

Both normally give the same result, but the first version helps avoid integer overflow.

---

## STL `binary_search()`

**Header:**

```cpp
#include <algorithm>
```

Checks if an element exists.

```cpp
binary_search(a.begin(), a.end(), x);
```

Returns:

- `true` - element exists
- `false` - element does not exist

Example:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> a = {1, 3, 5, 7, 9};

    if (binary_search(a.begin(), a.end(), 5)) {
        cout << "Found";
    }
    else {
        cout << "Not Found";
    }
}
```

**Complexity:** `O(log n)`

---

# Lower Bound

`lower_bound()` finds the **first element greater than or equal to `x`**.

```text
lower_bound(x) -> first >= x
```

**Header:**

```cpp
#include <algorithm>
```

Syntax:

```cpp
lower_bound(a.begin(), a.end(), x);
```

Example:

```cpp
vector<int> a = {1, 3, 3, 3, 7, 9};

int index = lower_bound(a.begin(), a.end(), 3) - a.begin();

cout << index; // 1
```

Visualization:

```text
index:  0  1  2  3  4  5
array: [1, 3, 3, 3, 7, 9]
           ^
        first >= 3
```

Another example:

```cpp
vector<int> a = {1, 3, 3, 3, 7, 9};

int index = lower_bound(a.begin(), a.end(), 5) - a.begin();

cout << index; // 4
```

Because `7` is the first element that is `>= 5`.

---

# Upper Bound

`upper_bound()` finds the **first element greater than `x`**.

```text
upper_bound(x) -> first > x
```

Syntax:

```cpp
upper_bound(a.begin(), a.end(), x);
```

Example:

```cpp
vector<int> a = {1, 3, 3, 3, 7, 9};

int index = upper_bound(a.begin(), a.end(), 3) - a.begin();

cout << index; // 4
```

Visualization:

```text
index:  0  1  2  3  4  5
array: [1, 3, 3, 3, 7, 9]
                    ^
                 first > 3
```

---

# Lower Bound vs Upper Bound

Remember:

```text
lower_bound(x) -> first >= x
upper_bound(x) -> first > x
```

Example:

```text
array = [1, 2, 2, 2, 5, 7]
```

For `x = 2`:

```text
lower_bound(2) -> index 1
upper_bound(2) -> index 4
```

---

# First Occurrence

Find the first occurrence of `x`:

```cpp
int first = lower_bound(a.begin(), a.end(), x) - a.begin();
```

Example:

```cpp
vector<int> a = {1, 2, 2, 2, 5};

int first = lower_bound(a.begin(), a.end(), 2) - a.begin();

cout << first; // 1
```

---

# Last Occurrence

Find the last occurrence of `x`:

```cpp
int last = upper_bound(a.begin(), a.end(), x) - a.begin() - 1;
```

Example:

```cpp
vector<int> a = {1, 2, 2, 2, 5};

int last = upper_bound(a.begin(), a.end(), 2) - a.begin() - 1;

cout << last; // 3
```

---

# Count Occurrences

Number of times `x` appears:

```cpp
int count = upper_bound(a.begin(), a.end(), x)
          - lower_bound(a.begin(), a.end(), x);
```

Example:

```cpp
vector<int> a = {1, 2, 2, 2, 5, 7};

int x = 2;

int count = upper_bound(a.begin(), a.end(), x)
          - lower_bound(a.begin(), a.end(), x);

cout << count; // 3
```

---

# Manual `lower_bound`

```cpp
int lowerBound(vector<int>& a, int x) {
    int left = 0;
    int right = a.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (a[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return left;
}
```

---

# Manual `upper_bound`

```cpp
int upperBound(vector<int>& a, int x) {
    int left = 0;
    int right = a.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (a[mid] <= x) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return left;
}
```

The important difference:

```text
lower_bound -> a[mid] < x
upper_bound -> a[mid] <= x
```

---

# Quick Cheat Sheet

```cpp
// Check if x exists
binary_search(a.begin(), a.end(), x);


// First element >= x
lower_bound(a.begin(), a.end(), x);


// First element > x
upper_bound(a.begin(), a.end(), x);


// Index of first element >= x
int index = lower_bound(a.begin(), a.end(), x) - a.begin();


// First occurrence of x
int first = lower_bound(a.begin(), a.end(), x) - a.begin();


// Last occurrence of x
int last = upper_bound(a.begin(), a.end(), x) - a.begin() - 1;


// Number of occurrences of x
int count = upper_bound(a.begin(), a.end(), x)
          - lower_bound(a.begin(), a.end(), x);
```

---

# Summary

| Operation | Meaning | Complexity |
|---|---|---|
| Binary Search | Find `x` | `O(log n)` |
| `binary_search()` | Check if `x` exists | `O(log n)` |
| `lower_bound()` | First element `>= x` | `O(log n)` |
| `upper_bound()` | First element `> x` | `O(log n)` |

## Remember

```text
Binary Search  -> find x

lower_bound(x) -> first >= x

upper_bound(x) -> first > x

Time           -> O(log n)

IMPORTANT      -> array must be SORTED
```