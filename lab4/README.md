# Quick Reference: Binary Search Tree (BST)

Below are compact notes and short examples for Binary Search Tree in C++.

---

# Binary Search Tree

A **Binary Search Tree (BST)** is a binary tree where each node has at most two children.

For every node:

```text
left subtree  <  node  <  right subtree
```

Example:

```text
        8
       / \
      3   10
     / \    \
    1   6    14
       / \   /
      4   7 13
```

For node `8`:

```text
Left values  < 8
Right values > 8
```

---

# Node Structure

A node usually contains:

- value
- pointer to left child
- pointer to right child

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
```

Example:

```cpp
Node* root = new Node(8);
```

Tree:

```text
    8
   / \
null null
```

---

# Insert

To insert a value:

```text
value < node  -> go left
value > node  -> go right
```

Recursive implementation:

```cpp
Node* insert(Node* root, int value) {

    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}
```

Usage:

```cpp
Node* root = nullptr;

root = insert(root, 8);
root = insert(root, 3);
root = insert(root, 10);
root = insert(root, 1);
root = insert(root, 6);
```

Result:

```text
        8
       / \
      3   10
     / \
    1   6
```

---

# Search

Search works similarly to Binary Search.

```text
target == node -> Found

target < node  -> Search left

target > node  -> Search right
```

Recursive version:

```cpp
bool search(Node* root, int target) {

    if (root == nullptr) {
        return false;
    }

    if (root->data == target) {
        return true;
    }

    if (target < root->data) {
        return search(root->left, target);
    }

    return search(root->right, target);
}
```

Usage:

```cpp
if (search(root, 6)) {
    cout << "Found";
}
else {
    cout << "Not Found";
}
```

---

# Iterative Search

Search can also be written without recursion:

```cpp
bool search(Node* root, int target) {

    while (root != nullptr) {

        if (root->data == target) {
            return true;
        }

        if (target < root->data) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }

    return false;
}
```

---

# Tree Traversals

There are three common DFS traversals:

```text
Inorder
Preorder
Postorder
```

---

# Inorder Traversal

Order:

```text
Left -> Root -> Right
```

Code:

```cpp
void inorder(Node* root) {

    if (root == nullptr) {
        return;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}
```

For:

```text
        8
       / \
      3   10
     / \
    1   6
```

Output:

```text
1 3 6 8 10
```

Important:

> Inorder traversal of a BST gives values in **sorted order**.

---

# Preorder Traversal

Order:

```text
Root -> Left -> Right
```

Code:

```cpp
void preorder(Node* root) {

    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}
```

Example output:

```text
8 3 1 6 10
```

---

# Postorder Traversal

Order:

```text
Left -> Right -> Root
```

Code:

```cpp
void postorder(Node* root) {

    if (root == nullptr) {
        return;
    }

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}
```

Example output:

```text
1 6 3 10 8
```

---

# Traversal Cheat Sheet

```text
Inorder:
Left -> Root -> Right

Preorder:
Root -> Left -> Right

Postorder:
Left -> Right -> Root
```

Easy way to remember:

```text
            Root position

Preorder    ROOT Left Right
             ^

Inorder     Left ROOT Right
                  ^

Postorder   Left Right ROOT
                       ^
```

---

# Find Minimum

The minimum value is the **leftmost node**.

```text
        8
       / \
      3   10
     /
    1

Minimum = 1
```

Code:

```cpp
Node* findMin(Node* root) {

    if (root == nullptr) {
        return nullptr;
    }

    while (root->left != nullptr) {
        root = root->left;
    }

    return root;
}
```

Usage:

```cpp
cout << findMin(root)->data;
```

---

# Find Maximum

The maximum value is the **rightmost node**.

```text
        8
       / \
      3   10
            \
             14

Maximum = 14
```

Code:

```cpp
Node* findMax(Node* root) {

    if (root == nullptr) {
        return nullptr;
    }

    while (root->right != nullptr) {
        root = root->right;
    }

    return root;
}
```

---

# Delete

Deleting a node has **3 cases**.

## Case 1: Leaf Node

Node has no children.

Before:

```text
    5
   / \
  3   7
```

Delete `3`:

```text
    5
     \
      7
```

Simply delete the node.

---

## Case 2: One Child

Example:

```text
    5
     \
      7
       \
        9
```

Delete `7`:

```text
    5
     \
      9
```

Replace the deleted node with its child.

---

## Case 3: Two Children

Example:

```text
        8
       / \
      3   10
         /  \
        9    14
```

Delete `10`.

We can replace it with the smallest value from its right subtree.

```text
Successor = 14
```

Then remove the old successor node.

---

# Delete Implementation

```cpp
Node* deleteNode(Node* root, int value) {

    if (root == nullptr) {
        return nullptr;
    }

    if (value < root->data) {

        root->left = deleteNode(root->left, value);

    }
    else if (value > root->data) {

        root->right = deleteNode(root->right, value);

    }
    else {

        // No left child
        if (root->left == nullptr) {

            Node* temp = root->right;

            delete root;

            return temp;
        }

        // No right child
        if (root->right == nullptr) {

            Node* temp = root->left;

            delete root;

            return temp;
        }

        // Two children
        Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right =
            deleteNode(root->right, temp->data);
    }

    return root;
}
```

Usage:

```cpp
root = deleteNode(root, 10);
```

---

# Height of BST

Height is the longest path from a node to a leaf.

Example:

```text
        8
       / \
      3   10
     /
    1
   /
  0
```

Recursive implementation:

```cpp
int height(Node* root) {

    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}
```

This version counts the height in **nodes**.

For an empty tree:

```text
height = 0
```

For one node:

```text
height = 1
```

---

# Count Nodes

```cpp
int countNodes(Node* root) {

    if (root == nullptr) {
        return 0;
    }

    return 1
        + countNodes(root->left)
        + countNodes(root->right);
}
```

---

# Count Leaves

A leaf is a node with no children.

```text
        8
       / \
      3   10
     / \
    1   6

Leaves: 1, 6, 10
```

Code:

```cpp
int countLeaves(Node* root) {

    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr &&
        root->right == nullptr) {

        return 1;
    }

    return countLeaves(root->left)
         + countLeaves(root->right);
}
```

---

# Complete BST Example

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {

    int data;

    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};


Node* insert(Node* root, int value) {

    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}


bool search(Node* root, int target) {

    if (root == nullptr) {
        return false;
    }

    if (root->data == target) {
        return true;
    }

    if (target < root->data) {
        return search(root->left, target);
    }

    return search(root->right, target);
}


void inorder(Node* root) {

    if (root == nullptr) {
        return;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}


void preorder(Node* root) {

    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}


void postorder(Node* root) {

    if (root == nullptr) {
        return;
    }

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}


Node* findMin(Node* root) {

    while (root != nullptr &&
           root->left != nullptr) {

        root = root->left;
    }

    return root;
}


Node* findMax(Node* root) {

    while (root != nullptr &&
           root->right != nullptr) {

        root = root->right;
    }

    return root;
}


int height(Node* root) {

    if (root == nullptr) {
        return 0;
    }

    return 1 + max(
        height(root->left),
        height(root->right)
    );
}


int countNodes(Node* root) {

    if (root == nullptr) {
        return 0;
    }

    return 1
        + countNodes(root->left)
        + countNodes(root->right);
}


int main() {

    Node* root = nullptr;

    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 7);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\nMinimum: "
         << findMin(root)->data;

    cout << "\nMaximum: "
         << findMax(root)->data;

    cout << "\nHeight: "
         << height(root);

    cout << "\nNodes: "
         << countNodes(root);

    cout << "\n";

    return 0;
}
```

---

# Time Complexity

For a **balanced BST**:

| Operation | Average |
|---|---|
| Search | `O(log n)` |
| Insert | `O(log n)` |
| Delete | `O(log n)` |
| Find Min | `O(log n)` |
| Find Max | `O(log n)` |
| Traversal | `O(n)` |

But a BST can become unbalanced.

Example:

```text
1
 \
  2
   \
    3
     \
      4
       \
        5
```

In this case:

```text
Search -> O(n)
Insert -> O(n)
Delete -> O(n)
```

So:

```text
Balanced BST:

        4
       / \
      2   6
     / \ / \
    1  3 5  7

Operations -> O(log n)


Worst case:

1
 \
  2
   \
    3
     \
      4

Operations -> O(n)
```

---

# Quick Cheat Sheet

```cpp
// Create root
Node* root = nullptr;


// Insert
root = insert(root, value);


// Search
search(root, value);


// Minimum
findMin(root);


// Maximum
findMax(root);


// Delete
root = deleteNode(root, value);


// Inorder
inorder(root);


// Preorder
preorder(root);


// Postorder
postorder(root);


// Height
height(root);


// Number of nodes
countNodes(root);


// Number of leaves
countLeaves(root);
```

---

# Remember

```text
BST Rule:

LEFT < ROOT < RIGHT
```

```text
Search:

target < root -> go LEFT
target > root -> go RIGHT
target = root -> FOUND
```

```text
Traversals:

Inorder   -> Left Root Right
Preorder  -> Root Left Right
Postorder -> Left Right Root
```

```text
Minimum -> leftmost node
Maximum -> rightmost node
```

```text
Delete:

0 children -> delete node
1 child    -> replace with child
2 children -> replace with successor
```

```text
Balanced BST:

Search -> O(log n)
Insert -> O(log n)
Delete -> O(log n)

Worst case:

Search -> O(n)
Insert -> O(n)
Delete -> O(n)
```

**Important:** Inorder traversal of a Binary Search Tree produces the values in sorted order.