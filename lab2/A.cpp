#include <iostream>
#include <string>
#include <deque>
#include <map>

using namespace std;

void myfunc(int y){

    deque<char> q;
    map<char, int> freq;

    for(int i = 0; i < y; ++i){
        char l;
        cin >> l;

        freq[l]++;

        if(freq[l] == 1){
            q.push_back(l);
        }

        while(!q.empty() && freq[q.front()] > 1){
            q.pop_front();
        }

        if(q.empty()){
            cout << "-1" << " ";
        }
        else{
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main(){

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;

        myfunc(x);

    }

}