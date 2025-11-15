#include<iostream>
using namespace std;
struct Node{
	int data;
	Node*next;
	Node*prev;
};
//insertion at position

void insertAtPosition(Node*&head, int value, int position){
	Node*newNode=new Node();
	newNode->data=value;
	
	newNode->prev=nullptr;
	
	if(position==1){
		newNode->prev=nullptr;
		newNode->next=head;
		if(head!=nullptr){
			head->prev=newNode;
		}
		head=newNode;
		return;
	}

	Node*temp=head;
	int count=1;
	while(count<position-1 &&temp!=nullptr){
		temp=temp->next;
		count++;
		
	}
	if(head==nullptr){
		cout<<"Invalid position"<<endl;
		delete newNode;
		return;
	}
	 newNode->next=temp->next;
	 newNode->prev=temp;
	 
	 if(temp->next!=nullptr){
	 	temp->next->prev=newNode;
	 }
	 temp->next=newNode;
}
//deletion at position

void deleteAtPosition(Node*&head, int position){
	if(head==nullptr){
		cout<<"List is empty"<<endl;
		return;
	}
	Node*temp=head;
	int count=1;
	
	while(count<position &&temp!=nullptr){
		temp=temp->next;
		count++;
		
	}
	if(temp==nullptr){
		cout<<"Invalid position"<<endl;
		return;
	}
	if(temp->prev==nullptr){
		head=temp->next;
		if(head!=nullptr){
			head->prev=nullptr;
		}
	}
	else{
		temp->prev->next=temp->next;
		if(temp->next!=nullptr){
			temp->next->prev=temp->next;
		}
	}
	cout<<"Deleted:  "<<temp->data <<endl;
	delete temp;
}
void display(Node* head){
	Node*temp=head;
	while(temp!=nullptr){
		cout<< temp->data<<" ";
		temp=temp->next;
	}
	cout<<"Null"<<endl;
}
int main(){
	Node*head=nullptr;
	int choice,value,position;
	
	while(true){
		cout << "\n=== Doubly Linked List Menu ===" << endl;
        cout << "1. Insert at Position" << endl;
        cout << "2. Delete at Position" << endl;
        cout << "3. Display List" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice){
        	case 1:
        		cout<<"Enter value: "<<endl;
        		cin>>value;
        		cout<<"Enter position: "<<endl;
        		cin>>position;
        		insertAtPosition(head,value,position);
        		display(head);
        		break;
        		
        		case 2:
        		cout<<"Enter position to delete: "<<endl;
        		cin>>position;
        		deleteAtPosition(head,position);
        		display(head);
        		break;
        		
        		case 3:
        			display(head);
        			break;
        			
				case 4:
				cout<<"Exiting program..."<<endl;
				return 0;
				
				default:
				cout<<"Invalid choice..."<<endl;	
        		
		}
	}
}
