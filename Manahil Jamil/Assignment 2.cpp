#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};


void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtPosition(Node*& head, int data, int position) {
    Node* newNode = new Node(data);

   
    if (position == 1) {
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    int count = 1;

    while (temp != nullptr && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position is invalid" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}


void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    if (position == 1) {
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        delete temp;
        return;
    }

    int count = 1;
    while (temp != nullptr && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Positionis invalid" << endl;
        return;
    }

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    delete temp;
}

int main() {
    Node* head = nullptr;

   
    insertAtPosition(head, 10, 1);
    insertAtPosition(head, 20, 2);
    insertAtPosition(head, 30, 3);

    cout << "Double Linked List: ";
    printList(head);

  
    insertAtPosition(head, 15, 2);
    cout << "After inserting at position 2: ";
    printList(head);

   
    insertAtPosition(head, 5, 1);
    cout << "After inserting  at position 1: ";
    printList(head);

 
    deleteAtPosition(head, 3);
    cout << "After deleting node at position 3: ";
    printList(head);


    deleteAtPosition(head, 1);
    cout << "After deleting node at position 1: ";
    printList(head);

    return 0;
}
