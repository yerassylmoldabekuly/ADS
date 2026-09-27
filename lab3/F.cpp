#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canSteal(const vector<long long>& bags, long long k, long long H) {
    long long hours = 0;

    for (long long bag : bags) {
        hours += (bag + k - 1) / k;

        if (hours > H) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    long long H;

    cin >> n >> H;

    vector<long long> bags(n);

    for (int i = 0; i < n; ++i) {
        cin >> bags[i];
    }

    long long left = 1;
    long long right = *max_element(bags.begin(), bags.end());

    while (left < right) {
        long long mid = left + (right - left) / 2;

        if (canSteal(bags, mid, H)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    cout << left << '\n';

    return 0;
}