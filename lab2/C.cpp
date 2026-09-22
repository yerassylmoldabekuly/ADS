#include <iostream>
#include <deque>

using namespace std;

int main(){

    int n;
    cin >> n;

    deque<string> d;

    for(int i = 0; i < n; ++i){
        string name;
        cin >> name;

        if(d.size() == 0){
            d.push_back(name);

            continue;
        }

        if(d.back() == name){
            continue;
        }
        else{
            d.push_back(name);
        }
    }

    cout << d.size() << endl;

    while(!d.empty()){
        cout << d.front() << endl;
        d.pop_front();
    }
}