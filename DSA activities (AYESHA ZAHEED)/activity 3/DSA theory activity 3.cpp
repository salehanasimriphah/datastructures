#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;   
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void deleteAtPosition(Node*& head, int pos) {
    if (head == NULL) {
        cout << "List is empty, nothing to delete!" << endl;
        return;
    }

    if (pos == 1) {   
        Node* temp = head;
        head = head->next;
        cout << "Deleted: " << temp->data << endl;
        delete temp;
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    cout << "Deleted: " << del->data << endl;
    delete del;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "  ";
        temp = temp->next;
    }
   
}

int main() {
    Node* head = NULL;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);

    cout << "Original List: ";
    display(head);

    deleteAtPosition(head, 2);  

    cout << "After Deletion at Position 2: ";
    display(head);

    return 0;
}


