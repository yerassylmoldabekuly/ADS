#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main() {
    int q, k;
    cin >> q >> k;

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    long long sum = 0;

    while (q--) {
        string command;
        cin >> command;

        if (command == "insert") {
            long long n;
            cin >> n;

            if (pq.size() < k) {
                pq.push(n);
                sum += n;
            }
            else if (n > pq.top()) {
                sum -= pq.top();
                pq.pop();

                pq.push(n);
                sum += n;
            }
        }
        else if (command == "print") {
            cout << sum << endl;
        }
    }

    return 0;
}