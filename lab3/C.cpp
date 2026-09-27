#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n);

    int sum = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        sum += x;
        p[i] = sum;
    }

    for (int i = 0; i < m; ++i) {
        int mistake;
        cin >> mistake;

        int index = lower_bound(p.begin(), p.end(), mistake) - p.begin();

        cout << index + 1 << endl;
    }

    return 0;
}