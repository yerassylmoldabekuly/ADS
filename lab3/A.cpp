#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& a, int target){
    int left = 0;
    int right = a.size() - 1;

    while(left <= right){
        int mid = left + (right - left)/2;

        if(a[mid] == target){
            return true;
        }
        else if(a[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return false;
}

int main(){
    int n;
    cin >> n;

    vector<int> v;

    for(int i = 0; i < n; ++i){
        int t;
        cin >> t;

        v.push_back(t);
    }

    int target;
    cin >> target;

    if(binarySearch(v, target)){
        cout << "Yes" << endl;
        return 0;
    }
    else{
        cout << "No" << endl;
        return 0;
    }

}