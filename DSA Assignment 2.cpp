#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
	Node* prev;
};
//insert at position
  void insertAtPosition(Node* &head,int value,int pos){
  	Node* newNode=new Node();
  	newNode->data=value;
  	if (pos==1){
	newNode->prev=NULL;
	newNode->next=head;
	if(head!=NULL){
		head->prev=newNode;
	}
	head=newNode;
  		return;
	  }
	  
	  Node* temp=head;
	  int count=1;
	  
	  while(count<pos-1 && temp!=NULL){
	  	temp=temp->next;
	  	count++;
	  }
	  if (head==NULL){
	  	cout << "Invalid Position!" << endl;
        delete newNode;
        return;
	  }
	  newNode->next=temp->next;
	  newNode->prev=temp;
	  
	  if(temp->next!=NULL){
	  	temp->next->prev=newNode;
	  }
	  temp->next=newNode;
}
//delete at position
void deleteAtPosition(Node* &head,int pos){
	if(head==NULL){
		cout<<"List is empty! "<<endl;
		return;
	}
	
	Node* temp=head;
	int count=1;
	
	while(count<pos && temp!=NULL){
		temp=temp->next;
		count++;
	}
	
	 if (temp == NULL) {
        cout << "Invalid Position!" << endl;
        return;
    }
	
	if(temp->prev==NULL){
		head=temp->next;
		if(head!=NULL){
			head->prev=NULL;
		}
	}
	else{
		temp->prev->next=temp->next;
		if(temp->next!=NULL){
			temp->next->prev=temp->next;
		}
	}
	 cout << "Deleted: " << temp->data << endl;
    delete temp;
}
//display list forward
    void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(){
	Node* head = NULL;
    int choice, value, pos;

    while (true) {
        cout << "\n=== Doubly Linked List Menu ===" << endl;
        cout << "1. Insert at Position" << endl;
        cout << "2. Delete at Position" << endl;
        cout << "3. Display List" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                insertAtPosition(head, value, pos);
                display(head);
                break;

            case 2:
                cout << "Enter position to delete: ";
                cin >> pos;
                deleteAtPosition(head, pos);
                display(head);
                break;

            case 3:
                display(head);
                break;

            case 4:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
}