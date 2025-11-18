#include <iostream>
#include <stack>
#include <string>
using namespace std;


struct TreeNode {
    char val;
    TreeNode* L;
    TreeNode* R;
    TreeNode(char c) { val = c; L = R = nullptr; }
};


TreeNode* mkNode(char c) {
    return new TreeNode(c);
}


bool isOp(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}


int prec(char c) {
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return -1;
}


string infix2postfix(const string &in) {
    stack<char> st;
    string out = "";
    for(size_t i=0;i<in.size();++i){
        char ch = in[i];
        if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') ) {
            out.push_back(ch);
        } else if(ch == '(') {
            st.push(ch);
        } else if(ch == ')') {
            while(!st.empty() && st.top()!='(') {
                out.push_back(st.top()); st.pop();
            }
            if(!st.empty() && st.top()=='(') st.pop();
        } else { 
            while(!st.empty() && prec(st.top()) >= prec(ch)) {
                out.push_back(st.top()); st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()) { out.push_back(st.top()); st.pop(); }
    return out;
}


TreeNode* postfix2tree(const string &post) {
    stack<TreeNode*> st;
    for(size_t i=0;i<post.size();++i){
        char ch = post[i];
        if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') ) {
            st.push(mkNode(ch));
        } else if(isOp(ch)) {
           
            TreeNode* r = nullptr;
            TreeNode* l = nullptr;
            if(!st.empty()){ r = st.top(); st.pop(); }
            if(!st.empty()){ l = st.top(); st.pop(); }
            TreeNode* opn = mkNode(ch);
            opn->L = l; opn->R = r;
            st.push(opn);
        }
    }
    if(st.empty()) return nullptr;
    return st.top();
}


string prefix2postfix(const string &pre) {
    stack<string> st;
    
    for(int i = (int)pre.size()-1; i>=0; --i) {
        char ch = pre[i];
        if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') ) {
            string s(1,ch);
            st.push(s);
        } else if(isOp(ch)) {
            if(st.size() < 2) return ""; // invalid
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            string comb = a + b + ch;
            st.push(comb);
        }
    }
    return st.empty() ? string("") : st.top();
}


// Infix 
void printInfix(TreeNode* node) {
    if(!node) return;
    bool isInternal = (node->L != nullptr || node->R != nullptr);
    if(isInternal) cout << "(";
    printInfix(node->L);
    cout << node->val;
    printInfix(node->R);
    if(isInternal) cout << ")";
}

// Prefix
void printPrefix(TreeNode* node) {
    if(!node) return;
    cout << node->val;
    printPrefix(node->L);
    printPrefix(node->R);
}

// Postfix
void printPostfix(TreeNode* node) {
    if(!node) return;
    printPostfix(node->L);
    printPostfix(node->R);
    cout << node->val;
}

int main() {
    int cho;
    do {
        cout << "\n===  Menu ===\n";
        cout << "1) Give Infix\n";
        cout << "2) Give Prefix\n";
        cout << "3) Give Postfix\n";
        cout << "4) Quit\n";
        cout << "Pick: ";
        cin >> cho;
        if(cho == 4) {
            cout << "Bye!\n";
            break;
        }
        string expr;
        string post;
        TreeNode* root = nullptr;

        if(cho == 1) {
            cout << "Type infix (e.g. (a+b)*c): ";
            cin >> expr;
            post = infix2postfix(expr);
            root = postfix2tree(post);
        } else if(cho == 2) {
            cout << "Type prefix (e.g. *+abc): ";
            cin >> expr;
            post = prefix2postfix(expr);
            if(post.empty()){
                cout << "Invalid prefix or conversion failed.\n";
                continue;
            }
            root = postfix2tree(post);
        } else if(cho == 3) {
            cout << "Type postfix (e.g. ab+c*): ";
            cin >> expr;
            root = postfix2tree(expr);
        } else {
            cout << "Invalid pick.\n";
            continue;
        }

        if(root == nullptr) {
            cout << "Could not build expression tree (invalid input?).\n";
            continue;
        }

        cout << "\n-- Results --\n";
        cout << "Infix : ";
        printInfix(root);
        cout << "\nPrefix: ";
        printPrefix(root);
        cout << "\nPostf : ";
        printPostfix(root);
        cout << "\n";

        
    } while(true);

    return 0;
}
