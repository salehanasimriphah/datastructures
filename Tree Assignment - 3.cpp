#include<iostream>
#include<stack>
using namespace std;

// Step 1: Node Structure
struct Node{
    char data;
    Node* left;
    Node* right;
};

// Step 2: Create Node
Node* createNode(char value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Step 3: Check Operator
bool isOperator(char c){
    return(c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Step 4: Precedence
int precedence(char c){
    if(c == '^'){
		return 3;
	}else if(c == '*' || c == '/'){
		return 2;
	}else if(c == '+' || c == '-'){
		return 1;
	}else{
		return -1;
	}
}

// Step 5: Infix to Postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for(int i = 0; i < infix.length(); i++){
        if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')){
			postfix += infix[i];
		}else if(infix[i] == '('){
			s.push(infix[i]);
		}else if(infix[i] == ')'){
            while(!s.empty() && s.top() != '('){
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }else{
            while (!s.empty() && precedence(s.top()) >= precedence(infix[i])){
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    while(!s.empty()){
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

// Step 6: Postfix to Expression Tree
Node* buildTree(string postfix){
    stack<Node*> st;
    for(int i = 0; i < postfix.length(); i++){
        if((postfix[i] >= 'a' && postfix[i] <= 'z') || (postfix[i] >= 'A' && postfix[i] <= 'Z')){
            st.push(createNode(postfix[i]));
        }else if(isOperator(postfix[i])){
            Node* newNode = createNode(postfix[i]);
            Node* rightNode = st.top(); st.pop();
            Node* leftNode = st.top(); st.pop();
            newNode->right = rightNode;
            newNode->left = leftNode;
            st.push(newNode);
        }
    }
    return st.top();
}

// Step 7: Traversals
void inorder(Node* root){
    if(root){
        if(root->left || root->right){
			cout << "(";
		}
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
        if(root->left || root->right){
			cout << ")";
		}
    }
}

void preorder(Node* root){
    if(root){
        cout << root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout << root->data;
    }
}

// Step 8:  Prefix to Postfix conversion
string prefixToPostfix(string prefix) {
    stack<string> s;
    // Loop from right to left (reverse)
    for(int i = prefix.length() - 1; i >= 0; i--) {
        if((prefix[i] >= 'a' && prefix[i] <= 'z') || (prefix[i] >= 'A' && prefix[i] <= 'Z')){
            string op(1, prefix[i]);
            s.push(op);
        }else if(isOperator(prefix[i])){
            string op1 = s.top(); 
			s.pop();
            string op2 = s.top(); 
			s.pop();
            string exp = op1 + op2 + prefix[i];
            s.push(exp);
        }
    }
    return s.top();
}

// Step 9: Main Menu
int main() {
    int mainChoice;
    do {
        cout << "\n--- Expression Conversion Menu ---\n";
        cout << "1. Enter Infix Expression\n";
        cout << "2. Enter Prefix Expression\n";
        cout << "3. Enter Postfix Expression\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        if (mainChoice == 4) {
            cout << "Exiting program...\n";
            break;
        }

        string expression, postfix;
        Node* root = NULL;

        switch(mainChoice){
            case 1: {
                cout << "Enter Infix Expression: ";
                cin >> expression;
                postfix = infixToPostfix(expression);
                root = buildTree(postfix);
                break;
            }
            case 2: {
                cout << "Enter Prefix Expression: ";
                cin >> expression;
                postfix = prefixToPostfix(expression);
                root = buildTree(postfix);
                break;
            }
            case 3: {
                cout << "Enter Postfix Expression: ";
                cin >> expression;
                root = buildTree(expression);
                break;
            }
            default:
                cout << "Invalid choice.\n";
                continue;
        }

        cout << "\n--- Result ---\n";
        cout << "Infix Expression: ";
        inorder(root);
        cout << endl;

        cout << "Prefix Expression: ";
        preorder(root);
        cout << endl;

        cout << "Postfix Expression: ";
        postorder(root);
        cout << endl;

    } while (mainChoice != 4);

    return 0;
}

