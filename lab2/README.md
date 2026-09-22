# Quick Reference: Linked List

## Node Structure

```cpp
class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};
```

Each node contains:

- `data` - stores the value
- `next` - pointer to the next node

Example:

```text
┌──────┬──────┐
│ data │ next │
└──────┴───┬──┘
           ↓
       next Node
```

A linked list looks like:

```text
head                      tail
 ↓                         ↓
10 → 20 → 30 → 40 → nullptr
```

---

## LinkedList Structure

```cpp
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}
};
```

- `head` - points to the first node
- `tail` - points to the last node

---

## Create a Node

```cpp
Node* newNode = new Node(10);
```

Result:

```text
newNode
   ↓
[10 | nullptr]
```

---

## Access Node Data

```cpp
node->data;        // value of current node
node->next;        // pointer to next node
node->next->data;  // value of next node
```

Move to the next node:

```cpp
node = node->next;
```

---

## push_front(x)

Adds a new node to the beginning of the list.

```cpp
void push_front(int x) {
    Node* newNode = new Node(x);

    newNode->next = head;
    head = newNode;

    if (tail == nullptr) {
        tail = newNode;
    }
}
```

Example:

```text
Before:

head              tail
 ↓                  ↓
10 → 20 → 30 → nullptr


push_front(5)


After:

head                   tail
 ↓                       ↓
5 → 10 → 20 → 30 → nullptr
```

Main idea:

```cpp
newNode->next = head;
head = newNode;
```

---

## push_back(x)

Adds a new node to the end of the list.

```cpp
void push_back(int x) {
    Node* newNode = new Node(x);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}
```

Example:

```text
Before:

head              tail
 ↓                  ↓
10 → 20 → 30 → nullptr


push_back(40)


After:

head                   tail
 ↓                       ↓
10 → 20 → 30 → 40 → nullptr
```

Main idea:

```cpp
tail->next = newNode;
tail = newNode;
```

---

## Linked List Iteration

Unlike a vector, a linked list does not have direct indexing.

Vector:

```cpp
v[0];
v[1];
v[2];
```

Linked List:

```cpp
Node* current = head;

while (current != nullptr) {
    cout << current->data << " ";
    current = current->next;
}
```

Example:

```text
current
 ↓
10 → 20 → 30 → nullptr

     current
        ↓
10 → 20 → 30 → nullptr

          current
             ↓
10 → 20 → 30 → nullptr

               current
                  ↓
10 → 20 → 30 → nullptr
               nullptr
```

---

## Print List

```cpp
void print() {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}
```

---

## Find an Element

```cpp
bool find(int x) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data == x) {
            return true;
        }

        current = current->next;
    }

    return false;
}
```

---

## Check if Empty

```cpp
bool empty() {
    return head == nullptr;
}
```

---

## Get Size

```cpp
int size() {
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}
```

---

## pop_front()

Removes the first node.

```cpp
void pop_front() {
    if (head == nullptr) {
        return;
    }

    Node* temp = head;

    head = head->next;

    delete temp;

    if (head == nullptr) {
        tail = nullptr;
    }
}
```

Example:

```text
Before:

head
 ↓
10 → 20 → 30 → nullptr


After pop_front():

head
 ↓
20 → 30 → nullptr
```

---

## Delete Every Second Node

Example:

```text
Before:

1 → 2 → 3 → 4 → 5

After:

1 → 3 → 5
```

```cpp
void deleteEverySecond() {
    Node* current = head;

    while (current != nullptr && current->next != nullptr) {
        Node* temp = current->next;

        current->next = temp->next;

        delete temp;

        current = current->next;
    }
}
```

---

## Reading Input

Input:

```text
5
1 2 3 4 5
```

Code:

```cpp
int n;
cin >> n;

LinkedList list;

for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    list.push_back(x);
}
```

Result:

```text
head                  tail
 ↓                      ↓
1 → 2 → 3 → 4 → 5 → nullptr
```

---

## Index Counter

Linked List does not have built-in indexes, but we can create a counter:

```cpp
Node* current = head;
int index = 0;

while (current != nullptr) {

    cout << "Index: " << index
         << " Value: " << current->data << endl;

    current = current->next;
    index++;
}
```

For:

```text
10 → 20 → 30 → 40
```

Indexes are:

```text
Index:    0      1      2      3
          ↓      ↓      ↓      ↓
Value:   10 →   20 →   30 →   40
```

---

## Most Important Patterns

```cpp
// Create node
Node* newNode = new Node(x);

// First node
head

// Last node
tail

// Current value
current->data

// Next node
current->next

// Move forward
current = current->next;

// Check empty
head == nullptr;

// Add to front
newNode->next = head;
head = newNode;

// Add to back
tail->next = newNode;
tail = newNode;

// Traverse the list
Node* current = head;

while (current != nullptr) {
    // work with current->data

    current = current->next;
}
```

---

## Full Basic Linked List

```cpp
#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void push_front(int x) {
        Node* newNode = new Node(x);

        newNode->next = head;
        head = newNode;

        if (tail == nullptr) {
            tail = newNode;
        }
    }

    void push_back(int x) {
        Node* newNode = new Node(x);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    LinkedList list;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        list.push_back(x);
    }

    list.print();

    return 0;
}
```

## Complexity

| Operation | Time |
|---|---:|
| `push_front()` | O(1) |
| `push_back()` with `tail` | O(1) |
| Access by position | O(n) |
| Search | O(n) |
| Print / Traverse | O(n) |
| `pop_front()` | O(1) |