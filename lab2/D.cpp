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

    void reverselist(){
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;

        while(curr != nullptr){
            next = curr-> next;
            curr-> next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
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
    int n;
    cin >> n;

    LinkedList list;

    for(int i = 0; i < n; ++i){
        int t;
        cin >> t;

        list.push_back(t);
    }
    
    list.reverselist();
    list.print();
}