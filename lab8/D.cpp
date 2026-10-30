#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long prev = 0;
    long long power = 1;
    string result = "";
    for (int i = 0; i < n; i++) {
        long long h;
        cin >> h;
        long long x = (h - prev) / power;
        char c = char(x + 'a');
        result += c;
        prev = h;
        power *= 2;
    }
    cout << result << endl;
    return 0;
}