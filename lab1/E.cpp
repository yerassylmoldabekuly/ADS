#include <iostream>
#include <vector>
#define ll long long

using namespace std;

ll isprime(ll x){
    if(x < 2){
        return false;
    }

    for(ll i = 2; i * i <= x; ++i){
        if(x % i == 0){
            return false;
        }
    }
    return x;
}

void list(ll t){
    vector<ll> numbers; 
    
    for(ll i = 2; i <= t; ++i){

        if(t % i == 0){
            numbers.push_back(i);
            t /= i;
            i -= 1;
        }
        if(i * i > t){
            numbers.push_back(t);
            t /= t;
        }
        if(t == 1){
            for(ll num: numbers){
                cout << num << " ";
            }
            break;
        }
    }
}


int main(){

    ll n;
    cin >> n;

    ll result = isprime(n);

    if(result){
        cout << result << endl;
        return 0;
    }

    list(n);

}