#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

// Insert at end
void insertAtEnd(Node *&head, int value) {
    Node *newnode = new Node();
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

// Insert at position
void insertAtPosition(Node*& head, int value, int pos) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (pos == 1) {
        newNode->next = head;
        if(head != NULL){
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count < pos - 1 && temp != nullptr) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Invalid position!" << endl;
        delete newNode;
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;

        if(temp->next != NULL){
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }
}

// Delete at given position
void deleteAtGiven(Node *&head, int pos) {
    if (head == NULL) {
        cout << "The list is empty, nothing to delete" << endl;
        return;
    }

    if (pos == 1) { // delete first node
        Node *temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        cout << "Deletion is done of " << temp->data << endl;
        delete temp;
        return;
    }

    Node *temp = head;
    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position" << endl;
        return;
    }

    Node *del = temp->next;
    temp->next = del->next;
    if(del->next!=NULL)
    {
        del->next->prev = temp;
    }
    cout << "Deletion is done of " << del->data << endl;
    delete del;
}

// Display the list
void display(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << "The elements are = " << temp->data << endl;
        temp = temp->next;
    }
}

int main(){
	Node *head= NULL;
	
	insertAtEnd(head,10);
	insertAtEnd(head,20);
	insertAtEnd(head,30);
	insertAtEnd(head,40);
	insertAtEnd(head,50);
	insertAtEnd(head,60);
	display(head);
	
	int choice;
	do{
	cout<<"----MENU----"<<endl;
	cout<<"1. insertion at given position "<<endl;
	cout<<"2. deletion at given position "<<endl;
	cout<<"3. exit "<<endl;
	
	cout<<"Enter the number from menu ";
	cin>>choice;
	
	switch(choice){
		case 1:
			int val, at;
			cout<<"Enter the number u want to insert in list = ";
			cin>>val;
			cout<<"Enter the position u want to insert the " <<val<< " in list = ";
			cin>>at;
		    insertAtPosition(head,val,at);
		    display(head);
		
		case 2:
		    int y;
		    cout<<"Enter the position of the value u want to insert in list = ";
			cin>>y;
			deleteAtGiven(head,y);
			display(head);
		
		case 3:
		   cout<<"You have been exited from program ";
		break;
		
		default:
		   cout<<"Invalid choice ";				
	}
	
}while(choice!=3);
}