#include <iostream>
#include <string>
using namespace std;

// Step 1: Define the Node Structure
struct Node {
    string value;
    Node* left;
    Node* right;
};

// Step 2: Implement the Node Creation Function
Node* createNode(string val) {
    Node* newNode = new Node();
    newNode->value = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Step 3a: Infix Traversal (Left -> Root -> Right)
void infix(Node* root) {
    if (root == nullptr) return;

    if (root->left && root->right)
        cout << "(";

    infix(root->left);
    cout << root->value;
    infix(root->right);

    if (root->left && root->right)
        cout << ")";
}

// Step 3b: Prefix Traversal (Root -> Left -> Right)
void prefix(Node* root) {
    if (root == nullptr) return;
    cout << root->value;
    prefix(root->left);
    prefix(root->right);
}

// Step 3c: Postfix Traversal (Left -> Right -> Root)
void postfix(Node* root) {
    if (root == nullptr) return;
    postfix(root->left);
    postfix(root->right);
    cout << root->value;
}

// Step 4: Construct the Input Tree (Main Function)
int main() {
   

    Node* root = createNode("+");
    root->left = createNode("3");
    root->right = createNode("*");
    root->right->left = createNode("56");
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
