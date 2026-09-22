#include <iostream>
#include <deque>

using namespace std;

int main(){
    string s;

    deque<string> d;

    while(cin >> s){
        if(s == "exit"){
            cout << "goodbye" << endl;
            break;
        }
        else if(s == "add_front"){
            cin >> s;

            d.push_front(s);
            cout << "ok" << endl;
        }
        else if(s == "add_back"){
            cin >> s;

            d.push_back(s);
            cout << "ok" << endl;
        }
        else if(s == "erase_front"){

            if(d.empty()){
                cout << "error" << endl;
            }
            else{
                cout << d.front() << endl;
                d.pop_front();
            }
        }
        else if(s == "erase_back"){

            if(d.empty()){
                cout << "error" << endl;
            }
            else{
                cout << d.back() << endl;
                d.pop_back();
            }
            
        }
        else if(s == "back"){

            if(d.empty()){
                cout << "error" << endl;
            }
            else{
                cout << d.back() << endl;
            }
            
        }
        else if(s == "front"){
            if(d.empty()){
                cout << "error" << endl;
            }
            else{
                cout << d.front() << endl;
            }
            
        }
        else if(s == "clear"){
            d.clear();
            cout << "ok" << endl;
        }
    }
}