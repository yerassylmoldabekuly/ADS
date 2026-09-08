#include <iostream>
using namespace std;

bool isprime(int n){

    if(n < 2){
        return false;
    }

    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}


int main(){

    int x;
    cin >> x;

    if(isprime(x)){

        cout << "YES" << endl;
        return 0;
    }
    else{

        cout << "NO" << endl;
    }
}