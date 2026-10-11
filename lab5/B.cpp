#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        if (a != b) {
            pq.push(a - b);
        }
    }

    if (pq.empty()) {
        cout << 0 << endl;
    }
    else {
        cout << pq.top() << endl;
    }

    return 0;
}