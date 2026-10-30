#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

const long long mod = 1000000007LL;
string hashing(const string& s) {
    long long h = 0, p = 1;
    for(char c : s) {
        h = (h + ((c - 47) * p) % mod) % mod;
        p = (p * 11) % mod;
    }
    return to_string(h);
}
int main() {
    int n; cin >> n;
    vector<string> v;
    unordered_map<string, int> mp;
    v.reserve(2*n); mp.reserve(4*n);
    for(int i = 0; i < 2*n; i++) {
        string s; cin >> s;
        v.push_back(s);
        mp[s]++;
    }
    int cnt = 0;
    for(int i = 0; i < v.size(); i++) {
        if(cnt == n) break;
        string hs = hashing(v[i]);
        if(mp.count(hs)) {
            cout << "Hash of string \"" << v[i] << "\" is " << hs << '\n';
            cnt++; 
        }
    }
    return 0;
}