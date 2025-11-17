#include<iostream>
using namespace std;

//NODE STRUCTURE
struct Node{
	string data; 
	Node* left;
	Node* right;
};

//NODE CREATION
Node* createNode(string data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

//INFIX TRAVERSAL ( LEFT-> ROOT-> RIGHT)
void infix(Node* root) {
    if (root == nullptr)
	return;
    if (root->left && root->right)
    cout << "(";
    infix(root->left);
    cout << root->data;
    infix(root->right);
if (root->left && root->right)
        cout << ")";
}

//PREFIX TRAVERSAL ( ROOT-> LEFT-> RIGHT)
void prefix(Node* root) {
    if (root == nullptr) 
	return;
    cout << root->data;
    prefix(root->left);
    prefix(root->right);
}

//POSTFIX TRAVERSAL ( LEFT-> RIGHT-> ROOT)
void postfix(Node* root) {
    if (root == nullptr) 
	return;
    postfix(root->left);
    postfix(root->right);
    cout << root->data;
}

//INPUT TREE (MAIN FUNCTION)
int main() {
	Node* root = createNode("*");
    root->left = createNode("61");
    root->right = createNode("+");
    root->right->left = createNode("31");
    root->right->right = createNode("2");

    cout << "Infix Expression: ";
    infix(root);
    cout << endl;

    cout << "Prefix Expression: ";
    prefix(root);
    cout << endl;

    cout << "Postfix Expression: ";
    postfix(root);
    cout << endl;

    return 0;
}

