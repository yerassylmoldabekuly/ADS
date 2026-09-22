#include <iostream>

using namespace std;

class Node{
public:
    string x;
    Node* next;

    Node(string x) : x(x), next(nullptr) {}
};

class LinkedList{
public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(string x){
        Node* newNode = new Node(x);

        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

   void solve(int y){
    Node* temp = head;
    Node* prev = nullptr;
    Node* oldhead = head;

    int i = 0;

    while(i < y){
        prev = temp;
        temp = temp->next;

        i++;
    }
    head = temp;
    prev->next = nullptr;


    tail->next = oldhead;
    tail = prev;

    }


    void print(){
        Node* curr = head;

        while(curr != nullptr){
            cout << curr-> x << " ";
            curr = curr-> next;
        }
    }
};

int main(){

    int n, k;
    cin >> n >> k;

    LinkedList list;

    for(int i = 0; i < n; ++i){
        string t;
        cin >> t;

        list.push_back(t);
    }

    list.solve(k);
    list.print();

}