#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    while (n--) {
        long long x;
        cin >> x;
        q.push(x);
    }
    int ans = 0;
    while (q.top() < k) {
        if (q.size() < 2) {
            cout << -1;
            return 0;
        }
        long long a = q.top(); q.pop();
        long long b = q.top(); q.pop();
        q.push(a + 2 * b);
        ans++;
    }
    cout << ans;
}