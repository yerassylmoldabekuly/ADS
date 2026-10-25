#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 0;
    int right = n - 1;

    for (int i = n - 1; i >= 0; i--) {
        int l = a[left] * a[left];
        int r = a[right] * a[right];

        if (l > r) {
            result[i] = l;
            left++;
        }
        else {
            result[i] = r;
            right--;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}