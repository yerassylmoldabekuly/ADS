#include <iostream>
#include <vector>
using namespace std;


int isprime(int x){

    if(x < 2){
        return false;
    }
    for(int i = 2; i < x; ++i){
        if(x % i == 0){
            return false;
        }
    }
    return x;
}

void list(int n){

    vector<int> numbers;

    for(int i = 2; i <= 7919; ++i){
        if(isprime(i)){
            numbers.push_back(i);
        }
    }

    cout << numbers[n-1] << endl;

}



int main(){


    int n;
    cin >> n;

    list(n);
    return 0;

}