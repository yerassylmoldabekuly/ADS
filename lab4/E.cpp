#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
    int x;
    Node* left;
    Node* right;

    Node(int x) : x(x), left(nullptr), right(nullptr) {}
};

void calculate(Node* curr, int level, vector<int>& cnt) {
    if (curr == nullptr) {
        return;
    }

    if (level == cnt.size()) {
        cnt.push_back(0);
    }

    cnt[level]++;

    calculate(curr->left, level + 1, cnt);
    calculate(curr->right, level + 1, cnt);
}

int main() {
    int n;
    cin >> n;

    vector<Node*> nodes(n + 1);

    for (int i = 1; i <= n; ++i) {
        nodes[i] = new Node(i);
    }

    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        cin >> x >> y >> z;

        if (z == 0) {
            nodes[x]->left = nodes[y];
        }
        else {
            nodes[x]->right = nodes[y];
        }
    }

    vector<int> cnt;

    calculate(nodes[1], 0, cnt);

    int answer = 0;

    for (int x : cnt) {
        answer = max(answer, x);
    }

    cout << answer << endl;

    return 0;
}