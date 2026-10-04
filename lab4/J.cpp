#include <iostream>
#include <stack>

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

    int kthSmallest(int k) {
        stack<Node*> st;
        Node* curr = root;

        int count = 0;

        while (curr != nullptr || !st.empty()) {

            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            count++;

            if (count == k) {
                return curr->x;
            }

            curr = curr->right;
        }

        return -1;
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    BST tree;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        tree.insert(x);
    }

    if (k > n) {
        cout << -1 << endl;
    }
    else {
        cout << tree.kthSmallest(k) << endl;
    }

    return 0;
}