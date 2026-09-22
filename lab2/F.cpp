#include <iostream>

using namespace std;

class Node{
public:
    int x;
    Node* next;

    Node(int x) : x(x), next(nullptr) {}
};

class LinkedList{
public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(int x){
        Node* newNode = new Node(x);

        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail-> next = newNode;
            tail = newNode;
        }
    }

    void solve(LinkedList& list2){
        Node* curr = head;
        Node* curr2 = list2.head;

        if(curr == nullptr){
            head = list2.head;
            tail = list2.tail;

            while(curr2 != nullptr){
                cout << curr2-> x << " ";
                curr2 = curr2-> next;
            }

            return;
        }
        else if(list2.head == nullptr){
            while(curr != nullptr){
                cout << curr-> x << " ";
                curr = curr-> next;
            }
            return;
        }
        else if(curr == nullptr && curr2 == nullptr){
            cout << endl;

            return;
        }

        Node* newHead = nullptr;
        Node* mergedtail = nullptr;

        if(curr-> x > curr2-> x){
            newHead = curr2;
            mergedtail = curr2;

            curr2 = curr2-> next;
        }
        else{
            newHead = curr;
            mergedtail = curr;

            curr = curr-> next;
        }
        while(curr != nullptr && curr2 != nullptr){
            if(curr-> x >= curr2-> x){
                mergedtail-> next = curr2;
                mergedtail = curr2;

                curr2 = curr2-> next;
            }
            else if(curr-> x < curr2-> x){
                mergedtail-> next = curr;
                mergedtail = curr;

                curr = curr-> next;
            }
        }

        if(curr == nullptr){
            mergedtail-> next = curr2;
        }
        else if(curr2 == nullptr){
            mergedtail-> next = curr;
        }

        mergedtail = newHead;

        while(mergedtail != nullptr){
            cout << mergedtail-> x << " ";
            mergedtail = mergedtail-> next;
        }
    }
};

int main(){
    int n;
    cin >> n;
    
    LinkedList list;
    LinkedList list2;

    for(int i = 0; i < n; ++i){
        int t;
        cin >> t;

        list.push_back(t);
    }

    int k;
    cin >> k;

    for(int i = 0; i < k; ++i){
        int l;
        cin >> l;

        list2.push_back(l);
    }

    list.solve(list2);
    cout << endl;
}