#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const long long m1 = 1000000007, m2 = 1000000009, p = 31;
vector<long long> p1, p2;
vector<long long> build(string s, long long mod) {
    vector<long long> h(s.size()+1, 0);
    for(int i = 0; i < s.size(); i++) 
        h[i+1] = (h[i] * p + s[i] - 'a' + 1) % mod;
    return h;
}
long long get(vector<long long>& h, int l, int len, vector<long long>& pw, long long mod) {
    return (h[l + len] - h[l] * pw[len] % mod + mod) % mod;
}
int main() {
    string a, b, w; cin >> a >> b >> w;
    int n = w.size();
    int lim = min(a.size(), b.size()) - n + 1;
    p1.resize(n+1, 1);
    p2.resize(n+1, 1);
    for(int i = 1; i <= n; i++) {
        p1[i] = p1[i-1] * p % m1;
        p2[i] = p2[i-1] * p % m2;
    }
    vector<long long> a1 = build(a, m1);
    vector<long long> b1 = build(b, m1);
    vector<long long> w1 = build(w, m1);
    vector<long long> a2 = build(a, m2);
    vector<long long> b2 = build(b, m2);
    vector<long long> w2 = build(w, m2);
    long long target1 = get(w1, 0, n, p1, m1);
    long long target2 = get(w2, 0, n, p2, m2);
    int ans = 0;
    for(int i = 0; i < lim; i++) {
        if(get(a1, i, n, p1, m1) == target1 && get(b1, i, n, p1, m1) == target1 && 
           get(a2, i, n, p2, m2) == target2 && get(b2, i, n, p2, m2) == target2) ans++;
    }
    cout << ans;
}