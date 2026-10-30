# Quick Reference: Hash Tables & Rabin-Karp Algorithm

Below are compact notes and short examples for Hash Tables, Hashing, Rolling Hash, and Rabin-Karp Algorithm in C++.

---

# 1. Hash Tables

A **Hash Table** is a data structure that stores data using a hash function.

**Idea:**

1. Take a key.
2. Calculate its hash value.
3. Convert the hash into an index.
4. Store or find the value using that index.

Example:

```text
Key = 25

Hash Function:
h(key) = key % 10

h(25) = 25 % 10 = 5

Hash Table:

Index:  0  1  2  3  4  5  6  7  8  9
                         |
                        25
```

**Complexity (average):**

- Insert: O(1)
- Search: O(1)
- Delete: O(1)

**Worst Case:** O(n)

---

# 2. Hash Function

A **Hash Function** converts a key into a hash value.

Example:

```cpp
int hashFunction(int key, int tableSize) {
    return key % tableSize;
}
```

Usage:

```cpp
cout << hashFunction(25, 10); // 5
cout << hashFunction(37, 10); // 7
cout << hashFunction(42, 10); // 2
```

**Important:**

A good hash function should:

- Be fast to calculate.
- Be deterministic.
- Distribute keys evenly.
- Minimize collisions.

---

# 3. Hash Collisions

A **collision** happens when different keys produce the same hash index.

Example:

```text
h(key) = key % 10

h(15) = 5
h(25) = 5
h(35) = 5
```

All three keys map to index `5`.

```text
Index 5 -> 15 -> 25 -> 35
```

### Collision Handling

Two common methods:

1. Separate Chaining
2. Open Addressing

---

# 4. Separate Chaining

Each hash table index stores multiple elements.

Example:

```text
Hash Table:

0 -> NULL
1 -> 21 -> 31
2 -> 12
3 -> NULL
4 -> 14
5 -> 15 -> 25 -> 35
```

Implementation using vectors:

```cpp
#include <iostream>
#include <vector>

using namespace std;

class HashTable {
private:
    int size;
    vector<vector<int>> table;

public:
    HashTable(int n) : size(n), table(n) {}

    int hashFunction(int key) {
        return (key % size + size) % size;
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    bool search(int key) {
        int index = hashFunction(key);

        for (int x : table[index]) {
            if (x == key) {
                return true;
            }
        }

        return false;
    }
};
```

Usage:

```cpp
HashTable ht(10);

ht.insert(15);
ht.insert(25);
ht.insert(35);

cout << ht.search(25); // 1
cout << ht.search(40); // 0
```

---

# 5. Open Addressing

In Open Addressing, all elements are stored directly inside the hash table.

If a collision occurs, another position is searched.

### Linear Probing

Formula:

```text
index = (hash(key) + i) % tableSize
```

Where:

```text
i = 0, 1, 2, 3, ...
```

Example:

```text
Table Size = 10

Insert 15:
15 % 10 = 5

Insert 25:
25 % 10 = 5 -> collision
Try index 6

Insert 35:
35 % 10 = 5 -> collision
Try index 6 -> occupied
Try index 7
```

Result:

```text
Index: 0 1 2 3 4 5  6  7  8 9
                 15 25 35
```

**Note:** Linear probing can cause clustering.

---

# 6. STL unordered_map

**Header:**

```cpp
#include <unordered_map>
```

**Type:**

```cpp
unordered_map<Key, Value>
```

Stores key-value pairs using hashing.

**Operations:**

- `mp[key]` - Access or insert a value.
- `mp.insert()` - Insert a key-value pair.
- `mp.find(key)` - Find a key.
- `mp.count(key)` - Check if a key exists.
- `mp.erase(key)` - Remove a key.
- `mp.size()` - Number of elements.
- `mp.empty()` - Check if empty.

**Complexity:**

Average O(1) for insert, search, and erase.

Worst case O(n).

### Example

```cpp
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> mp;

    mp["apple"] = 3;
    mp["banana"] = 5;
    mp["orange"] = 2;

    cout << mp["apple"] << endl; // 3

    if (mp.find("banana") != mp.end()) {
        cout << "Found";
    }

    mp.erase("orange");
}
```

**Note:** `unordered_map` does not maintain sorted order.

---

# 7. STL unordered_set

**Header:**

```cpp
#include <unordered_set>
```

**Type:**

```cpp
unordered_set<T>
```

Stores unique elements using hashing.

**Operations:**

- `insert(x)` - Insert element.
- `erase(x)` - Remove element.
- `find(x)` - Search element.
- `count(x)` - Check existence.
- `size()` - Number of elements.
- `empty()` - Check if empty.

### Example

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<int> s;

    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(20);

    cout << s.size(); // 3

    if (s.count(20)) {
        cout << "\nFound";
    }
}
```

**Important:** Duplicate elements are not stored.

---

# 8. Frequency Counting Using Hash Tables

One of the most common applications of hashing.

### Example

Count occurrences of each number.

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    vector<int> a = {1, 2, 2, 3, 3, 3};

    unordered_map<int, int> freq;

    for (int x : a) {
        freq[x]++;
    }

    cout << freq[1] << endl; // 1
    cout << freq[2] << endl; // 2
    cout << freq[3] << endl; // 3
}
```

**Complexity:** O(n) average.

---

# 9. String Hashing

String hashing converts a string into a numerical hash value.

Useful for:

- String comparison
- Pattern matching
- Substring search
- Rabin-Karp Algorithm

### Polynomial Hash

Formula:

```text
H(s) = (s[0] * p^(m-1)
      + s[1] * p^(m-2)
      + ...
      + s[m-1]) % MOD
```

Where:

```text
p   = Base (e.g. 31)
MOD = Large prime number (e.g. 1e9+7)
m   = String length
```

### Example

```text
String = "abc"

a = 1
b = 2
c = 3

p = 31

Hash = 1*31² + 2*31 + 3

Hash = 961 + 62 + 3

Hash = 1026
```

---

# 10. Polynomial Hash Implementation

```cpp
#include <iostream>
#include <string>

using namespace std;

const long long MOD = 1000000007;
const long long BASE = 31;

long long calculateHash(string s) {
    long long hash = 0;

    for (char c : s) {
        hash = (hash * BASE + (c - 'a' + 1)) % MOD;
    }

    return hash;
}

int main() {
    cout << calculateHash("abc"); // 1026
}
```

**Complexity:** O(m), where m is the string length.

**Important:** This example assumes lowercase English letters.

---

# 11. Rolling Hash

A **Rolling Hash** allows us to calculate the hash of the next substring without recalculating everything.

Example:

```text
Text = "abcdef"

Window Size = 3

abc -> bcd -> cde -> def
```

Instead of calculating each hash from scratch, we:

1. Remove the contribution of the first character.
2. Shift the remaining hash.
3. Add the new character.

### Formula

```text
newHash = ((oldHash - oldChar * BASE^(m-1))
           * BASE + newChar) % MOD
```

Where:

```text
m = Window size
```

**Complexity:** O(1) per window shift.

---

# 12. Rolling Hash Example

Text:

```text
"abcd"
```

Window size:

```text
3
```

First substring:

```text
"abc"
```

Using:

```text
a = 1
b = 2
c = 3
d = 4

BASE = 31
```

Hash:

```text
H("abc") = 1*31² + 2*31 + 3

H("abc") = 1026
```

Now shift to `"bcd"`.

Remove `a`:

```text
1026 - 1*31² = 65
```

Multiply by base:

```text
65 * 31 = 2015
```

Add `d`:

```text
2015 + 4 = 2019
```

Result:

```text
H("bcd") = 2019
```

No need to calculate the entire hash again.

---

# 13. Rabin-Karp Algorithm

**Rabin-Karp** is a string matching algorithm based on hashing.

It finds occurrences of a pattern inside a text.

**Idea:**

1. Calculate the hash of the pattern.
2. Calculate the hash of the first text window.
3. Compare the hashes.
4. If hashes match, verify the actual characters.
5. Move the window using Rolling Hash.
6. Repeat until the end of the text.

Example:

```text
Text:    "ababcabc"
Pattern: "abc"
```

Windows:

```text
aba
 bab
  abc  -> MATCH
   bca
    cab
     abc -> MATCH
```

Output:

```text
Pattern found at index 2
Pattern found at index 5
```

---

# 14. Rabin-Karp Implementation

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const long long MOD = 1000000007;
const long long BASE = 31;

vector<int> rabinKarp(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();

    vector<int> result;

    if (m == 0 || m > n) {
        return result;
    }

    long long patternHash = 0;
    long long windowHash = 0;
    long long power = 1;

    // Calculate BASE^(m-1) % MOD
    for (int i = 1; i < m; i++) {
        power = (power * BASE) % MOD;
    }

    // Calculate initial hashes
    for (int i = 0; i < m; i++) {
        patternHash =
            (patternHash * BASE + (unsigned char)pattern[i]) % MOD;

        windowHash =
            (windowHash * BASE + (unsigned char)text[i]) % MOD;
    }

    // Sliding window
    for (int i = 0; i <= n - m; i++) {

        // Compare hashes
        if (patternHash == windowHash) {

            // Verify characters to avoid hash collisions
            if (text.compare(i, m, pattern) == 0) {
                result.push_back(i);
            }
        }

        // Move window
        if (i < n - m) {
            long long oldChar = (unsigned char)text[i];
            long long newChar = (unsigned char)text[i + m];

            windowHash =
                (windowHash - oldChar * power % MOD + MOD) % MOD;

            windowHash =
                (windowHash * BASE + newChar) % MOD;
        }
    }

    return result;
}

int main() {
    string text = "ababcabc";
    string pattern = "abc";

    vector<int> positions = rabinKarp(text, pattern);

    for (int index : positions) {
        cout << index << " ";
    }

    // Output: 2 5
}
```

---

# 15. How Rabin-Karp Works

Example:

```text
Text = "ababcabc"
Pattern = "abc"
```

### Step 1: Calculate Pattern Hash

```text
Pattern = "abc"

H("abc") = 1026
```

### Step 2: Calculate First Window Hash

```text
Window = "aba"

H("aba") = 1024
```

Compare:

```text
1024 != 1026

No match
```

### Step 3: Shift Window

```text
Window = "bab"

H("bab") = 1955
```

Compare:

```text
1955 != 1026

No match
```

### Step 4: Shift Again

```text
Window = "abc"

H("abc") = 1026
```

Compare:

```text
1026 == 1026

Verify characters -> MATCH
```

Position:

```text
Index = 2
```

Continue searching.

Final result:

```text
2 5
```

---

# 16. Hash Collisions in Rabin-Karp

Different strings can have the same hash value.

Example:

```text
H("abc") == H("xyz")
```

This is possible because hash values are calculated modulo a fixed number.

This is called a **Hash Collision**.

Therefore:

```cpp
if (patternHash == windowHash) {
    if (text.compare(i, m, pattern) == 0) {
        result.push_back(i);
    }
}
```

The second comparison verifies that the strings are actually equal.

**Important:** Equal hashes do not always mean equal strings.

---

# 17. Rabin-Karp Time Complexity

Let:

```text
n = Text length
m = Pattern length
```

### Preprocessing

Calculate initial hashes:

```text
O(m)
```

### Sliding Window

There are:

```text
n - m + 1
```

possible windows.

Each rolling hash update takes:

```text
O(1)
```

### Complexity

| Case | Complexity |
|---|---|
| Best Case | O(n + m) |
| Average Case | O(n + m) expected |
| Worst Case | O(nm) |
| Extra Space | O(1) excluding results |

**Why O(nm) in the worst case?**

If many windows have matching hashes, the algorithm must verify the characters.

Each verification may require O(m) time.

---

# 18. Rabin-Karp vs Naive String Matching

### Naive Algorithm

Compare every possible substring character by character.

```cpp
for (int i = 0; i <= n - m; i++) {
    if (text.compare(i, m, pattern) == 0) {
        cout << i << " ";
    }
}
```

**Worst Case:** O(nm)

### Rabin-Karp

Uses Rolling Hash to avoid comparing every character in every window.

**Expected Time:** O(n + m)

**Worst Case:** O(nm)

| Feature | Naive Search | Rabin-Karp |
|---|---|---|
| Main Idea | Character Comparison | Hash Comparison |
| Preprocessing | O(1) | O(m) |
| Expected Time | O(nm) upper bound | O(n + m) |
| Worst Case | O(nm) | O(nm) |
| Rolling Hash | No | Yes |
| Hash Collisions | No | Yes |

---

# 19. Hash Tables vs String Hashing

| Feature | Hash Table | String Hashing |
|---|---|---|
| Purpose | Store and retrieve data | Represent strings numerically |
| Main Idea | Key -> Hash -> Bucket | String -> Hash Value |
| Common Use | Fast lookup | Pattern matching |
| STL | unordered_map, unordered_set | Custom hash function |
| Average Lookup | O(1) | Depends on application |
| Collisions | Possible | Possible |

**Important:** Hash Tables and Rabin-Karp both use hashing, but for different purposes.

---

# 20. Quick Cheat Sheet

## Hash Table

```cpp
#include <unordered_map>
#include <unordered_set>

// Key-value storage
unordered_map<int, int> mp;

// Insert
mp[10] = 100;

// Access
cout << mp[10];

// Search
if (mp.find(10) != mp.end()) {
    cout << "Found";
}

// Delete
mp.erase(10);

// Unique elements
unordered_set<int> s;

s.insert(5);
s.insert(10);

// Check existence
if (s.count(5)) {
    cout << "Exists";
}
```

## Polynomial Hash

```cpp
const long long MOD = 1000000007;
const long long BASE = 31;

long long hashString(string s) {
    long long hash = 0;

    for (char c : s) {
        hash = (hash * BASE + (unsigned char)c) % MOD;
    }

    return hash;
}
```

## Rolling Hash

```cpp
// Remove old character
hash = (hash - oldChar * power % MOD + MOD) % MOD;

// Shift and add new character
hash = (hash * BASE + newChar) % MOD;
```

## Rabin-Karp

```cpp
// Compare hashes
if (patternHash == windowHash) {

    // Verify actual characters
    if (text.compare(i, m, pattern) == 0) {
        result.push_back(i);
    }
}
```

---

# 21. Remember

```text
HASH TABLE:

Key -> Hash Function -> Index -> Value

Average Insert: O(1)
Average Search: O(1)
Average Delete: O(1)

Worst Case: O(n)
```

```text
HASH COLLISION:

Different keys -> Same hash index

Solutions:
1. Separate Chaining
2. Open Addressing
```

```text
POLYNOMIAL HASH:

H(s) = (s[0]*p^(m-1) + ... + s[m-1]) % MOD

Time: O(m)
```

```text
ROLLING HASH:

Remove old character
Multiply by BASE
Add new character

Time per shift: O(1)
```

```text
RABIN-KARP:

1. Calculate pattern hash
2. Calculate first window hash
3. Compare hashes
4. Verify characters if hashes match
5. Shift window using Rolling Hash
6. Repeat

Expected Time: O(n + m)
Worst Time: O(nm)
```

---

# Final Summary

| Topic | Main Idea | Complexity |
|---|---|---|
| Hash Table | Store data using hash function | O(1) average lookup |
| Hash Function | Convert key into hash value | Depends on key |
| Collision Handling | Resolve identical hash positions | Depends on method |
| Polynomial Hash | Convert string into number | O(m) |
| Rolling Hash | Update substring hash | O(1) |
| Rabin-Karp | Find pattern using hashes | O(n + m) expected |

**Key Difference:**

- **Hash Table:** Uses hashing for fast data storage and retrieval.
- **Rolling Hash:** Efficiently updates the hash when a window moves.
- **Rabin-Karp:** Uses Rolling Hash to search for patterns in a text.

**Most Important STL Containers:**

```cpp
unordered_map<Key, Value>
unordered_set<T>
```

**Most Important Formula:**

```text
newHash = ((oldHash - oldChar * BASE^(m-1))
           * BASE + newChar) % MOD
```

**Most Important Concept:**

Equal strings always have equal hashes, but equal hashes do not always mean equal strings.