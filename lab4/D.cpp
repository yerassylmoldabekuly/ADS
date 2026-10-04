#include <iostream>
#include <vector>

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

    void calculate(Node* curr, int level, vector<long long>& sum) {
        if (curr == nullptr) {
            return;
        }

        if (level == sum.size()) {
            sum.push_back(0);
        }

        sum[level] += curr->x;

        calculate(curr->left, level + 1, sum);
        calculate(curr->right, level + 1, sum);
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

    vector<long long> sum;

    tree.calculate(tree.root, 0, sum);

    cout << sum.size() << endl;

    for (long long x : sum) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}