#include<iostream>
using namespace std;

struct Node{
	char data;
	Node* left;
	Node* right;
};
Node* createnode(int value){
	Node* newNode = new Node();
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void infix(Node* root)
{if(root != NULL){
	if (root->left)cout<<"(";
	infix(root->left);
	cout<<root->data;
	infix(root->right);
	if (root->right)cout<<")";
}}

void prefix(Node* root){
	if (root!=NULL){
		cout<<root->data;
		prefix(root->left);
		prefix(root->right);
	}
}

void postfix(Node* root)
{
	if (root != NULL){
		postfix(root->left);
		postfix(root->right );
		cout<<root->data;
	}
}
int main(){
	int choice;
	Node* root = createnode('*');
	root->left = createnode('+');
	root->right = createnode('-');
	
	root->left->left = createnode('A');
	root->left->right = createnode('B');
	
	root->right->left = createnode('C');
	root->right->right = createnode('D');
do{
	cout<<"\n_______Menu_______\n";
	cout<<"\n 1)Infix_Expression\n";
	cout<<"\n 2)Prefix_Expression\n";
	cout<<"\n 3)Postfix_Expression\n";
	cout<<"\n 4)Exit \n";
	cout<<"\n Enter your choice: \n";
	cin>>choice;

switch(choice){

case 1:
	cout<<"Infix Expression ";
	infix(root);
	cout<<endl;
	break;
	
	case 2:
	cout<<"Prefix Expression ";
	prefix(root);
	cout<<endl;
	break;
	
	case 3:
	cout<<"Postfix Expression ";
	postfix(root);
	cout<<endl;
	break;
	
	case 4:
		cout<<"Exit Program_!!! \n";
		break;
			
		default:
			cout<<"Invalid Choice_!!! \n";
}}
while(choice != 4);

	return 0;
	
}
