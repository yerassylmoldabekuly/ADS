#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canDivide(const vector<long long>& a, int k, long long limit){
    int blocks = 1;
    long long sum = 0;

    for(long long x : a){

        if(sum + x <= limit){
            sum += x;
        }
        else{
            blocks++;
            sum = x;
        }

        if(blocks > k){
            return false;
        }
    }

    return true;
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);

    long long left = 0;
    long long right = 0;

    for(int i = 0; i < n; ++i){
        cin >> a[i];

        left = max(left, a[i]);
        right += a[i];
    }

    while(left < right){

        long long mid = left + (right - left) / 2;

        if(canDivide(a, k, mid)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }

    cout << left << '\n';

    return 0;
}