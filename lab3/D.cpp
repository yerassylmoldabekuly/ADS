#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    int p;
    cin >> p;

    while (p--) {
        long long power;
        cin >> power;

        int pos = upper_bound(a.begin(), a.end(), power) - a.begin();

        cout << pos << " " << prefix[pos] << '\n';
    }

    return 0;
}