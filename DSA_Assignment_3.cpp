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
	Node* root = createnode('*');
	root->left = createnode('+');
	root->right = createnode('-');
	
	root->left->left = createnode('5');
	root->left->right = createnode('4');
	
	root->right->left = createnode('3');
	root->right->right = createnode('2');


	cout<<"Infix Expression ";
	infix(root);
	cout<<endl;
	
	cout<<"Prefix Expression ";
	prefix(root);
	cout<<endl;
	
	cout<<"Postfix Expression ";
	postfix(root);
	cout<<endl;
	
	return 0;
	
}
