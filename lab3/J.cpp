#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canCatch(const vector<int>& need, int L, int k){
    int count = 0;

    for(int x : need){
        if(x <= L){
            count++;

            if(count >= k){
                return true;
            }
        }
    }

    return false;
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> need(n);

    for(int i = 0; i < n; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        need[i] = max(x2, y2);
    }

    int left = 1;
    int right = 1000000000;

    while(left < right){
        int mid = left + (right - left) / 2;

        if(canCatch(need, mid, k)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }

    cout << left << '\n';

    return 0;
}