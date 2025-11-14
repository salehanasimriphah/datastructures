#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};
Node* head = NULL;
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
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
    newNode->prev = temp;
}
void deleteAtBeginning() {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    delete temp;
    cout << "Node deleted from beginning.\n";
}
void deleteAtEnd() {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Last node deleted.\n";
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
    cout << "Node deleted from end.\n";
}
void deleteAtPosition(int pos) {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }
    if (pos == 1) {
        deleteAtBeginning();
        return;
    }
    Node* temp = head;
    int count = 1;
    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        cout << "Invalid position.\n";
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    delete temp;
    cout << "Node at position " << pos << " deleted.\n";
}
void display() {
    Node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    int choice, value, pos;
    while (true) {
        cout << "\n#####Doubly Linked List Menu#####\n";
        cout << "1. Insert at End\n";
        cout << "2. Delete at Beginning\n";
        cout << "3. Delete at End\n";
        cout << "4. Delete at Position\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 2:
                deleteAtBeginning();
                break;
            case 3:
                deleteAtEnd();
                break;
            case 4:
                cout << "Enter position: ";
                cin >> pos;
                deleteAtPosition(pos);
                break;
            case 5:
                display();
                break;
            case 6:
                cout << "Exiting the program...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
return 0;
}

