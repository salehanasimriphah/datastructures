#include<iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

void insertAtPosition(DNode*& head, int value, int pos) {
	
	DNode* newNode = new DNode();
    newNode->data = value;
    
    if (pos == 1) {  
        newNode->prev = NULL;
		newNode->next = head;
			
			if(head != NULL){    
				head->prev = newNode;
			}
	
		head = newNode;
        return;
    }

    DNode* temp = head;
    int count = 1;

    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Invalid position\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    newNode->prev = temp;
    temp->next = newNode;
}

void deleteAtPosition(DNode* & head, int pos){
	if(head == NULL){
		cout<<"\nList is empty. Nothing to delete!\n";
		return;
	}
	
	if(pos == 1){
		DNode* temp = head;
		head = head->next;
		
			if(head != NULL){
				head->prev = NULL;
			}
			
		cout<<"\nDeleted: " << temp->data <<endl;
		delete temp;
		return;
	}
	
	DNode* temp = head;
	int count = 1;
	while(temp != NULL && count < pos){
		temp = temp->next;
		count++;
	}
	
	if(temp == NULL){
		cout<<"\nInvalid Position!\n";
		return;
	}
	
	if(temp->next != NULL){
		temp->next->prev = temp->prev;
	}
	
	temp->prev->next = temp->next;
	cout<<"\nDeleted: "<<temp->data <<endl;
	delete temp;

}

void display(DNode* head){
	cout<<"List: ";
	while(head != NULL){
		cout<<head->data <<" -> ";
		head = head->next;
	}
	cout<<"NULL\n";
}

int main() {
    DNode* head = NULL;

    insertAtPosition(head, 10, 1); 
    insertAtPosition(head, 20, 2); 
    insertAtPosition(head, 30, 3);
    insertAtPosition(head, 15, 2); 
    display(head);
    
    cout<<"\n***Delete at position 1***";
    deleteAtPosition(head, 1); 
    display(head);

    cout<<"\n***Delete at position 2***";
    deleteAtPosition(head, 2); 
    display(head);

    cout<<"\n***Delete at position 5***";
    deleteAtPosition(head, 5); 
    display(head);

    return 0;
}

