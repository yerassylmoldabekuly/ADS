#include <iostream>
#include <string>

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

    int size(){
        int count = 0;
        Node* curr = head;

        while(curr != nullptr){
            count++;

            curr = curr-> next;
        }

        return count;
    }

    void deletemid(int y){
        if(head == nullptr){
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;

        int index = y/2;
        int count = 0;

       while(count < index){
            prev = curr;
            curr = curr-> next;

            if(index == count + 1){
                prev-> next = curr-> next;

                delete curr;
            }

            count++;
       }

       if(y == 1){
            delete head;

            head = nullptr;
            tail = nullptr;

            return;
       }

    }

    void print(){
        Node* curr = head;

        while(curr != nullptr){
            cout << curr-> x << " ";
            curr = curr-> next;
        }
        cout << endl;
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

    int s = list.size();
    list.deletemid(s);
    list.print();
}