#include <iostream>
#include <algorithm>

using namespace std;

class Node {
public:
    int x;
    Node* left;
    Node* right;

    Node(int x) {
        this->x = x;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void insert(int x) {
        Node* newNode = new Node(x);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* curr = root;

        while (true) {
            if (x == curr->x) {
                delete newNode;
                return;
            }

            if (x < curr->x) {
                if (curr->left == nullptr) {
                    curr->left = newNode;
                    return;
                }

                curr = curr->left;
            }
            else {
                if (curr->right == nullptr) {
                    curr->right = newNode;
                    return;
                }

                curr = curr->right;
            }
        }
    }

    int height(Node* curr, int& diameter) {
        if (curr == nullptr) {
            return 0;
        }

        int leftHeight = height(curr->left, diameter);
        int rightHeight = height(curr->right, diameter);

        int path = leftHeight + rightHeight + 1;

        diameter = max(diameter, path);

        return max(leftHeight, rightHeight) + 1;
    }

    int solve() {
        int diameter = 0;

        height(root, diameter);

        return diameter;
    }
};

int main() {
    int n;
    cin >> n;

    BST tree;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        tree.insert(x);
    }

    cout << tree.solve() << endl;

    return 0;
}