#include <iostream>

using namespace std;

class Node {
public:
    int x;
    Node* left;
    Node* right;

    Node(int x) : x(x), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;

    BST() : root(nullptr) {}

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

    Node* find(int x) {
        Node* curr = root;

        while (curr != nullptr) {
            if (curr->x == x) {
                return curr;
            }

            if (x < curr->x) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }

        return nullptr;
    }

    int countNodes(Node* curr) {
        if (curr == nullptr) {
            return 0;
        }

        return 1 + countNodes(curr->left)
                 + countNodes(curr->right);
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

    int x;
    cin >> x;

    Node* node = tree.find(x);

    cout << tree.countNodes(node) << endl;

    return 0;
}