#include <iostream>
#include <deque>
using namespace std;

void royal_flush(int y){
    int num = y;

    deque<int> result;
    result.push_back(y);

    for(int i = y; i > 1; --i){
        num -= 1;

        result.push_front(num);

        for(int j = num; j > 0; --j){
            result.push_front(result.back());
            result.pop_back();
        }
    }

    for(int n: result){
        cout << n << " ";
    }
    cout << endl;
}

int main(){

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;

        royal_flush(x);
    }
}