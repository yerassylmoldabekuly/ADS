#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

bool canCut(const vector<double>& ropes, double length, long long k){
    long long pieces = 0;

    for(double rope : ropes){
        pieces += (long long)(rope / length);

        if(pieces >= k){
            return true;
        }
    }

    return false;
}

int main(){
    int n;
    long long k;

    cin >> n >> k;

    vector<double> ropes(n);

    for(int i = 0; i < n; ++i){
        cin >> ropes[i];
    }

    double left = 0.0;
    double right = *max_element(ropes.begin(), ropes.end());

    for(int i = 0; i < 100; ++i){
        double mid = (left + right) / 2.0;

        if(canCut(ropes, mid, k)){
            left = mid;
        }
        else{
            right = mid;
        }
    }

    cout << fixed << setprecision(9) << left << '\n';

    return 0;
}