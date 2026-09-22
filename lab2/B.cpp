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
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteEven(){
        Node* curr = head;

        while(curr != nullptr && curr-> next != nullptr){
            Node* temp = curr-> next;

            curr-> next = temp-> next;

            delete temp;

            curr = curr-> next;
        }
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
        int x;
        cin >> x;

        list.push_back(x);

    }
    list.deleteEven();
    list.print();

}