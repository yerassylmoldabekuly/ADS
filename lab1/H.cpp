#include <iostream>
#include <vector>
using namespace std;


int main(){

    int n;
    cin >> n;

    vector<int> numbers;
    vector<int> result;

    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;

        int l = numbers.size();

        bool isfound = false;

        for(int j = 0; j < numbers.size(); ++j){
            
            if(x > numbers[l-1]){
                result.push_back(numbers[l-1]);
                isfound = true;
                break;
            }
            else if(numbers.size() != 0){
                l -= 1;
            }
        }

        if(isfound == false){
            result.push_back(-1);
        }
        numbers.push_back(x);
    }
    
    for(vector<int> :: iterator it = result.begin(); it != result.end(); ++it){
        cout << *it << " ";
    }
}

    
