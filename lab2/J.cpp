#include <iostream>
using namespace std;

class Node {
public:
    int x;
    Node* next;

    Node(int x) : x(x), next(nullptr) {}
};


// 1. Insert x at position p
Node* inserts(Node* head, int x, int p) {
    Node* newNode = new Node(x);

    // Insert at the beginning
    if (p == 0) {
        newNode->next = head;
        return newNode;
    }

    Node* curr = head;

    // Find node at position p - 1
    for (int i = 0; i < p - 1; ++i) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}


// 2. Remove node at position p
Node* removeNode(Node* head, int p) {
    if (p == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;

        return head;
    }

    Node* curr = head;

    // Find node at position p - 1
    for (int i = 0; i < p - 1; ++i) {
        curr = curr->next;
    }

    Node* temp = curr->next;

    curr->next = temp->next;
    delete temp;

    return head;
}


// 3. Print list
void print(Node* head) {
    if (head == nullptr) {
        cout << -1 << endl;
        return;
    }

    Node* curr = head;

    while (curr != nullptr) {
        cout << curr->x;

        if (curr->next != nullptr) {
            cout << " ";
        }

        curr = curr->next;
    }

    cout << endl;
}


// 4. Move node from position p1 to position p2
Node* replace(Node* head, int p1, int p2) {
    if (p1 == p2) {
        return head;
    }

    Node* movedNode;

    // Remove node from p1
    if (p1 == 0) {
        movedNode = head;
        head = head->next;
    }
    else {
        Node* prev = head;

        for (int i = 0; i < p1 - 1; ++i) {
            prev = prev->next;
        }

        movedNode = prev->next;
        prev->next = movedNode->next;
    }

    // Insert movedNode at p2
    if (p2 == 0) {
        movedNode->next = head;
        head = movedNode;

        return head;
    }

    Node* curr = head;

    for (int i = 0; i < p2 - 1; ++i) {
        curr = curr->next;
    }

    movedNode->next = curr->next;
    curr->next = movedNode;

    return head;
}


// 5. Reverse entire list
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* next = curr->next;

        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}


// 6. Cyclic shift left x times
Node* cyclic_left(Node* head, int x) {
    if (head == nullptr || head->next == nullptr || x == 0) {
        return head;
    }

    Node* curr = head;

    // Find node at position x - 1
    for (int i = 0; i < x - 1; ++i) {
        curr = curr->next;
    }

    Node* newHead = curr->next;

    // Cut list
    curr->next = nullptr;

    // Find old tail
    Node* tail = newHead;

    while (tail->next != nullptr) {
        tail = tail->next;
    }

    // Connect old tail to old head
    tail->next = head;

    return newHead;
}


// 7. Cyclic shift right x times
Node* cyclic_right(Node* head, int x) {
    if (head == nullptr || head->next == nullptr || x == 0) {
        return head;
    }

    // Find length
    int n = 0;
    Node* curr = head;

    while (curr != nullptr) {
        n++;
        curr = curr->next;
    }

    // Right x = left n - x
    int leftShift = n - x;

    curr = head;

    // Find new tail
    for (int i = 0; i < leftShift - 1; ++i) {
        curr = curr->next;
    }

    Node* newHead = curr->next;

    // Cut
    curr->next = nullptr;

    // Find old tail
    Node* tail = newHead;

    while (tail->next != nullptr) {
        tail = tail->next;
    }

    // Connect with old head
    tail->next = head;

    return newHead;
}


int main() {
    Node* head = nullptr;

    int command;

    while (cin >> command) {

        if (command == 0) {
            break;
        }

        // insert
        if (command == 1) {
            int x, p;
            cin >> x >> p;

            head = inserts(head, x, p);
        }

        // remove
        else if (command == 2) {
            int p;
            cin >> p;

            head = removeNode(head, p);
        }

        // print
        else if (command == 3) {
            print(head);
        }

        // replace
        else if (command == 4) {
            int p1, p2;
            cin >> p1 >> p2;

            head = replace(head, p1, p2);
        }

        // reverse
        else if (command == 5) {
            head = reverse(head);
        }

        // cyclic left
        else if (command == 6) {
            int x;
            cin >> x;

            head = cyclic_left(head, x);
        }

        // cyclic right
        else if (command == 7) {
            int x;
            cin >> x;

            head = cyclic_right(head, x);
        }
    }

    return 0;
}