#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countRange(vector<int>& a, int l, int r){
    int left = lower_bound(a.begin(), a.end(), l) - a.begin();
    int right = upper_bound(a.begin(), a.end(), r) - a.begin();

    return right - left;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> v;

    for(int i = 0; i < n; ++i){
        int t;
        cin >> t;

        v.push_back(t);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < m; ++i){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int res = countRange(v, l1, r1);
        int res2 = countRange(v, l2, r2);

        int maxl = max(l1, l2);
        int minr = min(r1, r2);

        if(maxl <= minr){
            cout << countRange(v, min(l1, l2), max(r1, r2)) << endl;
        }
        else{
            cout << res + res2 << endl;
        }
    }
}