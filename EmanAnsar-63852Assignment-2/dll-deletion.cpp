#include<iostream>
using namespace std;
struct Node{
	
	Node* prev;
	int data;
	Node* next;
};

void  delAtBeg(Node* &head){
	if(head==NULL){
		cout<<"List is empty! Nothing to delete"<<endl;
		return;
	}
	
	Node* temp=head;
	head=head->next;
	
	if(head!=NULL){
		head->prev=NULL;
	}
	
	cout<<"Deleted: "<<temp->data<<endl;
	delete temp;
}

void delAtEnd(Node* &head){
	if(head==NULL){
	cout<<"No list to delete"<<endl;
	return;
	}
	
	if(head->next==NULL){
		cout<<"Deleted: "<<head->data<<endl;
		delete head;
		head=NULL;
		return;
	}
	
	Node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	
	cout<<"Deleted: "<<temp->data<<endl;
	temp->prev->next=NULL;
	delete temp;
}

void delAtPos(Node* &head,int pos){
	if(head==NULL){
	cout<<"No list to display"<<endl;
	return;
	}
	
	if(pos<=0){
	cout<<"Invalid Position!"<<endl;
	return;
	}
	
	if(pos==1){
	delAtBeg(head);
	return;
	}
	
	Node* temp=head;
	for(int i=1;i<pos && temp!=NULL;i++){
	temp=temp->next;
	}
	
	if(temp==NULL){
	cout<<"Position out of range"<<endl;
	return;
	}
	
	if(temp->next!=NULL){
		temp->next->prev=temp->prev;
	}
	
	if(temp->prev!=NULL){
		temp->prev->next=temp->next;
	}
	
	cout<<"Deleted: "<<temp->data<<endl;
	delete temp;
}

void display(Node* &head){
	
	if(head==NULL){
		cout<<"No list to display"<<endl;
	}
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp!=NULL) {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }

}
int main(){
	Node* head=NULL;
	Node* n1=new Node{NULL,10,NULL};
	Node* n2=new Node{n1,20,NULL};
	Node* n3=new Node{n2,30,NULL};
	n1->next=n2;
	n2->next=n3;
	head=n1;
	int choice,pos;
	do{
	cout<<"-----MENU-----"<<endl;
	cout<<"1. Deletion at the beginning"<<endl;
	cout<<"2. Deletion at the end"<<endl;
	cout<<"3. Deletion at a specific position"<<endl;
	cout<<"4. Display"<<endl;
	cout<<"5. Exit!"<<endl;
	cout<<"Enter your choice"<<endl;
	cin>>choice;
	switch(choice){
		case 1:
			delAtBeg(head);
			break;
		
		case 2:
			delAtEnd(head);
			break;
			
		case 3:
			cout<<"Enter position you want to delete"<<endl;
			cin>>pos;
			delAtPos(head,pos);
			break;
			
		case 4:
			display(head);
			break;
			
		case 5:
			cout<<"Exiting!"<<endl;
			break;
			
		default:
			cout<<"Invalid Input! Try Again."<<endl;
	
	}}while(choice!=5);
		
	
	
}

