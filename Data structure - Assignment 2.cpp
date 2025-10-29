#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtBeginning(int value) {
    Node* n = new Node();
    n->data = value;
    n->next = head;
    head = n;
}

void insertAtEnd(int value) {
    Node* n = new Node();
    n->data = value;
    n->next = NULL;
    if(head == NULL) {
        head = n;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtPosition(int value, int pos) {
    if(pos == 1) {
        insertAtBeginning(value);
        return;
    }
    Node* n = new Node();
    n->data = value;
    Node* temp = head;
    for(int i=1; i<pos-1 && temp!=NULL; i++) {
        temp = temp->next;
    }
    if(temp == NULL) return;
    n->next = temp->next;
    temp->next = n;
}

void deleteAtBeginning() {
    if(head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteAtEnd() {
    if(head == NULL) return;
    if(head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void deleteAtPosition(int pos) {
    if(head == NULL) return;
    if(pos == 1) {
        deleteAtBeginning();
        return;
    }
    Node* temp = head;
    for(int i=1; i<pos-1 && temp->next!=NULL; i++) {
        temp = temp->next;
    }
    if(temp->next == NULL) return;
    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

void display() {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, value, pos;
    while(true) {
        cout << "1 Insert at Beginning" << endl;
        cout << "2 Insert at End" << endl;
        cout << "3 Insert at Position" << endl;
        cout << "4 Delete at Beginning" << endl;
        cout << "5 Delete at End" << endl;
        cout << "6 Delete at Position" << endl;
        cout << "7 Display List" << endl;
        cout << "8 Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter value: "; 
			cin >> value; 
			insertAtBeginning(value); 
			break;
            case 2: cout << "Enter value: "; 
			cin >> value; 
			insertAtEnd(value); 
			break;
            case 3: cout << "Enter value: "; 
			cin >> value; cout << "Enter position: ";
		    cin >> pos; 
			insertAtPosition(value,pos); 
			break;
            case 4: deleteAtBeginning(); 
			break;
            case 5: deleteAtEnd(); 
			break;
            case 6: cout << "Enter position: "; 
			cin >> pos; 
			deleteAtPosition(pos); 
			break;
            case 7: display(); 
			break;
            case 8: 
			return 0;
            default: cout << "Invalid choice" << endl;
        }
    }
}
