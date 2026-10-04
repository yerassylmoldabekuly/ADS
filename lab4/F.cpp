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

    int countTriangles(Node* curr) {
        if (curr == nullptr) {
            return 0;
        }

        int cnt = 0;

        if (curr->left != nullptr && curr->right != nullptr) {
            cnt = 1;
        }

        return cnt
             + countTriangles(curr->left)
             + countTriangles(curr->right);
    }

    int solve() {
        return countTriangles(root);
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