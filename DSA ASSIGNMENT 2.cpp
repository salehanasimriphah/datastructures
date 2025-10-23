#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};


void insertAtPosition(Node*& head, int value, int position) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

   
    if (position == 1) {
        newNode->next = head;
        if (head != nullptr) head->prev = newNode;
        head = newNode;
        return;
    }


    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        delete newNode;
        return;
    }

 
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr) temp->next->prev = newNode;
    temp->next = newNode;
}


void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node* temp = head;

   
    if (position == 1) {
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        cout << "Deleted: " << temp->data << endl;
        delete temp;
        return;
    }


    for (int i = 1; i < position && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }

  
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next ? temp->next : nullptr;
        if (temp->next != nullptr) temp->next->prev = temp->prev;
    }

    cout << "Deleted: " << temp->data << endl;
    delete temp;
}


void display(Node* head) {
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertAtPosition(head, 10, 1);
    insertAtPosition(head, 20, 2);
    insertAtPosition(head, 30, 3);
    insertAtPosition(head, 40, 4);

    cout << "Original List:" << endl;
    display(head);

   
    cout << "\nInsert 25 at position 3:" << endl;
    insertAtPosition(head, 25, 3);
    display(head);

    
    cout << "\nDelete node at position 4:" << endl;
    deleteAtPosition(head, 4);
    display(head);

    return 0;
}
