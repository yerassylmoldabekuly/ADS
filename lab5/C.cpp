#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }

    long long ans = 0;

    for (int i = 0; i < x; i++) {
        int seats = pq.top();
        pq.pop();

        ans += seats;

        if (seats > 1) {
            pq.push(seats - 1);
        }
    }

    cout << ans << endl;

    return 0;
}