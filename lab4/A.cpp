#include <iostream>
#include <string>

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
            if (x <= curr->x) {
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

    bool checkPath(string path) {
        Node* curr = root;

        for (char direction : path) {
            if (direction == 'L') {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }

            if (curr == nullptr) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    BST tree;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        tree.insert(x);
    }

    for (int i = 0; i < m; ++i) {
        string path;
        cin >> path;

        if (tree.checkPath(path)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}