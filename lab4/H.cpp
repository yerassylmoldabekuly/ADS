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

    void greaterSum(Node* curr, int& sum) {
        if (curr == nullptr) {
            return;
        }

        greaterSum(curr->right, sum);

        sum += curr->x;
        curr->x = sum;

        greaterSum(curr->left, sum);
    }

    void print(Node* curr) {
    if (curr == nullptr) {
        return;
    }

    print(curr->right);

    cout << curr->x << " ";

    print(curr->left);
    }

    void solve() {
        int sum = 0;

        greaterSum(root, sum);

        print(root);
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

    tree.solve();

    return 0;
}