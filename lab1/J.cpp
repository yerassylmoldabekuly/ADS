#include <iostream>
#include <deque>

using namespace std;

int main(){

    int n = 5;

    deque<int> boris;
    deque<int> nursik;

    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;

        boris.push_back(x);
    }

    for(int i = 0; i < n; ++i){
        int y;
        cin >> y;

        nursik.push_back(y);
    }


    int count = 0;

    while(true){
        if(nursik.size() == 0){
            cout << "Boris " << count << endl;
            break;
        }
        if(boris.size() == 0){
            cout << "Nursik " << count << endl;
            break;
        }

        if(boris.front() == 0 && nursik.front() == 9){
            boris.push_back(boris.front());
            boris.pop_front();

            boris.push_back(nursik.front());
            nursik.pop_front();

            count += 1;

            if(nursik.size() == 0){
                cout << "Boris " << count << endl;
                break;
            }
            if(boris.size() == 0){
                cout << "Nursik " << count << endl;
                break;
            }
        }
        else if(nursik.front() == 0 && boris.front() == 9){
            nursik.push_back(boris.front());
            boris.pop_front();

            nursik.push_back(nursik.front());
            nursik.pop_front();

            count += 1;

            if(nursik.size() == 0){
                cout << "Boris " << count << endl;
                break;
            }
            if(boris.size() == 0){
                cout << "Nursik " << count << endl;
                break;
            }
        }

        else if(nursik.front() > boris.front()){
            nursik.push_back(boris.front());
            boris.pop_front();

            nursik.push_back(nursik.front());
            nursik.pop_front();

            count += 1;
        }
        else{
            boris.push_back(boris.front());
            boris.pop_front();

            boris.push_back(nursik.front());
            nursik.pop_front();

            count += 1;
        }
    }
}