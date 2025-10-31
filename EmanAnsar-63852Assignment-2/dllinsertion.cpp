#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAtBeginning(Node*& head, int value) {
    Node* newNode=new Node();
    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=head;

    if(head!=NULL) {
        head->prev=newNode;
    }
    head=newNode;
}


void insertAtEnd(Node*& head, int value) {
    Node* newNode=new Node();
    newNode->data=value;
    newNode->next=NULL;

    if (head==NULL) {
        newNode->prev=NULL;
        head=newNode;
        return;
    }

    Node* temp=head;
    while(temp->next != NULL) {
        temp=temp->next;
    }

    temp->next=newNode;
    newNode->prev=temp;
}


void insertAtPosition(Node*& head, int value, int pos) {
	
    if (pos<=0) {
        cout<<"Invalid position!"<<endl;
        return;
    }

    if(pos==1) {
        insertAtBeginning(head, value);
        return;
    }

    Node* temp=head;
    for(int i=1; i<pos-1 && temp!=NULL; i++) {
        temp=temp->next;
    }

    if (temp==NULL) {
        cout<<"Position out of range!"<<endl;
        return;
    }

    Node* newNode=new Node();
    newNode->data=value;

    newNode->next=temp->next;
    if (temp->next!=NULL) {
        temp->next->prev=newNode;
    }

    temp->next=newNode;
    newNode->prev=temp;
}


void display(Node* head) {
    Node* temp=head;
    cout<<"Doubly Linked List: ";
    while (temp!=NULL) {
        cout<<temp->data<<" <-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main() {
    Node* head=NULL;
    int choice, value, pos;

    do {
        cout<<"\n--- Doubly Linked List Menu ---\n";
        cout<<"1. Insert at Beginning\n";
        cout<<"2. Insert at End\n";
        cout<<"3. Insert at Position\n";
        cout<<"4. Display\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
        case 1:
            cout<<"Enter value: ";
            cin>>value;
            insertAtBeginning(head, value);
            break;

        case 2:
            cout<<"Enter value: ";
            cin>>value;
            insertAtEnd(head, value);
            break;

        case 3:
            cout<<"Enter value: ";
            cin>>value;
            cout<<"Enter position: ";
            cin>>pos;
            insertAtPosition(head, value, pos);
            break;

        case 4:
            display(head);
            break;

        case 5:
            cout<<"Exiting...\n";
            break;

        default:
            cout<<"Invalid choice! Try again.\n";
        }
    } while (choice!=5);

    return 0;
}
