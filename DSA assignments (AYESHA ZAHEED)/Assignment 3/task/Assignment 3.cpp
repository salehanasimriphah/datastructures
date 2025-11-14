#include <iostream>
using namespace std;
struct Node {                          // NODE STRUCTUE
    char data;
    Node* left;
    Node* right;
};
Node* createNode(char value) {        // NODE CREATION
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void infix(Node* root) {             // INFIX TRAVERSAL
    if (root != NULL) {
        if (root->left || root->right)
            cout << "(";
        infix(root->left);
        cout << root->data;
        infix(root->right);
        if (root->left || root->right)
            cout << ")";
    }
}
void prefix(Node* root) {           // PREFIX TRAVERSAL
    if (root != NULL) {
        cout << root->data;
        prefix(root->left);
        prefix(root->right);
    }
}
void postfix(Node* root) {         // POSTFIX TRAVERSAL
    if (root != NULL) {
        postfix(root->left);
        postfix(root->right);
        cout << root->data;
    }
}
int main() {                       // MAIN FUCTION                  
    int choice; 
    Node* root = createNode('*');     // VALUES
    root->left = createNode('+');
    root->right = createNode('-');
    root->left->left = createNode('A');    
    root->left->right = createNode('B');
    root->right->left = createNode('C');
    root->right->right = createNode('D');              
    do {
        cout << "\n.....MENU.....\n";     // MENU
        cout << "1. Infix Expression\n";
        cout << "2. Prefix Expression\n";
        cout << "3. Postfix Expression\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {               // CASES(for the application of menu
            case 1:
                cout << "Infix Expression: ";
                infix(root);
                cout << endl;
                break;
            case 2:
                cout << "Prefix Expression: ";
                prefix(root);
                cout << endl;
                break;
            case 3:
                cout << "Postfix Expression: ";
                postfix(root);
                cout << endl;
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }
    } while (choice != 4);
    return 0;
}

