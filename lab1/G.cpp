#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){

    stack<char> mystack;

    string w;
    cin >> w;

    for(int i = 0; i < w.size(); ++i){
        
        if(!mystack.empty() && mystack.top() == w[i]){
            mystack.pop();
        }
        else{
            mystack.push(w[i]);
        }

    }

    if(mystack.size() == 0){
        cout << "YES" << endl;
        return 0;
    }
    else{
        cout << "NO" << endl;
        return 0;
    }
}