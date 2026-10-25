#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b) {
    int sumA = 0;
    int sumB = 0;

    for (int x : a) {
        sumA += x;
    }

    for (int x : b) {
        sumB += x;
    }

    if (sumA != sumB) {
        return sumA > sumB;
    }

    return a < b;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0) cout << " ";
            cout << v[i][j];
        }
        cout << endl;
    }

    return 0;
}