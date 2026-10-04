#include <iostream>

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

    int countLeaves(Node* curr) {
        if (curr == nullptr) {
            return 0;
        }

        if (curr->left == nullptr && curr->right == nullptr) {
            return 1;
        }

        return countLeaves(curr->left) + countLeaves(curr->right);
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

    cout << tree.countLeaves(tree.root) << endl;

    return 0;
}