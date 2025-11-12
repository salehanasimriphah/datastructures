#include <iostream>
//#include <string>
using namespace std;

struct Node {
    string data;
    Node *left;
    Node *right;

    Node(string val) 
	{
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Infix Traversal 
void inorder(Node* node) 
{
    if (node==nullptr){
        return;
    }

    bool haveLeaf = (node->left == nullptr && node->right == nullptr);
    if (!haveLeaf) 
	{
	    cout<<"(";
    }
    inorder(node->left);
    cout<<node->data;
    inorder(node->right);
    if (!haveLeaf) 
	{
	cout<<")";
    }  
}

// Prefix Traversal
void preorder(Node* node) 
{
    if (node==nullptr)
	{
        return;
    }
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

// Postfix Traversal 
void postorder(Node* node) 
{
    if (node==nullptr){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}

int main() 
{
    Node *a = new Node("a");
    Node *b = new Node("b");
    Node *c = new Node("c");
    Node *d = new Node("d");

    Node *plus = new Node("+");
    Node *minus = new Node("-");
    Node *multiply = new Node("*");

    plus->left = a;
    plus->right = b;

    minus->left = c;
    minus->right = d;

    multiply->left = plus;
    multiply->right = minus;

    Node* root = multiply;
    
    // Expression: (a + b) * (c - d)

    cout<<"Infix Expression = ";
    inorder(root);
    cout<<endl;

    cout<<"Prefix Expression = ";
    preorder(root);
    cout<<endl;

    cout<<"Postfix Expression = ";
    postorder(root);
    cout<<endl;

    return 0;
}
