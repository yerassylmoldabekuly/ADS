#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long k;

    cin >> n >> k;

    vector<long long> a(n);
    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        prefix[i + 1] = prefix[i] + a[i];
    }

    int answer = n;

    for (int left = 0; left < n; ++left) {

        int l = left;
        int r = n - 1;
        int found = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            long long sum = prefix[mid + 1] - prefix[left];

            if (sum >= k) {
                found = mid;

                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        if (found != -1) {
            int length = found - left + 1;
            answer = min(answer, length);
        }
    }

    cout << answer << '\n';

    return 0;
}