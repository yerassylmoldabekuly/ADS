#include <iostream>
#include <string>
using namespace std;

int main(){

    string w, w2;
    cin >> w >> w2;

    for(int i = 0; i < w.size(); ++i){
        char r = '#';

        if(w[i] == r && i == 0){
            w.erase(i, 1);
        }
        if(w[i] == r && i != 0){
            w.erase(i-1, 2);

            i -= 2;
        }
    }

    for(int i = 0; i < w2.size(); ++i){
        char r = '#';

        if(w2[i] == r && i == 0){
            w2.erase(i, 1);
        }
        if(w2[i] == r && i != 0){
            w2.erase(i-1, 2);

            i -= 2;
        }
    }

    if(w == w2){
        cout << "Yes" << endl;
        return 0;
    }
    else{
        cout << "No" << endl;
        return 0;
    }
}