#include<stack>
#include <iostream>
#include "Node.cpp"

using namespace std;

void preorder(Node * root){
    if(root == NULL){
        return;
    }
    stack<Node *> s;
    s.push(root);
    while(!s.empty()){
        Node * newNode = s.top();
        s.pop();
        cout<<newNode ->data<<" ";
        if(newNode ->right != NULL){
            s.push(newNode -> right);
        }
        if(newNode ->left != NULL){
            s.push(newNode -> left);
        }
    }
}

void postorder(Node * root){
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root);
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
        Node * temp = s2.top();
        if(temp -> left != NULL){
            s1.push(temp -> left);
        }
        if(temp -> right != NULL){
            s1.push(temp -> right);
        }
    }
    while(!s2.empty()){
        cout<<s2.top() -> data<<" ";
        s2.pop();
    }

}
Node * temp;
//postorder with one stack
void postorder1(Node * root){
    if(root == NULL){
        return;
    }
    stack<Node *> s;
    Node * curr = root;
    while(!s.empty() || curr!=NULL){
        if(curr != NULL){
            s.push(curr);
            curr = curr -> left;
        }
        else{
            temp = s.top() -> right;
            if(temp == NULL){
                temp = s.top();
                s.pop();
                cout<<temp ->data<<' ';
                while(!s.empty() && temp == s.top()->right){
                    temp = s.top();
                    s.pop();
                    cout<<temp->data;
                }
            }
            else{
                curr = temp;    
            }
        }
    }
}

void all_traversals(Node * root){
    vector<int> preorder_list;
    vector<int> postorder_list;
    vector<int> inorder_list;

    stack<pair<Node *, int> > s;
    s.push(make_pair(root, 1));
    while(!s.empty()){
        pair<Node *, int> temp = s.top();
        if(temp.second == 1){
            preorder_list.push_back(temp.first->data);
            s.pop();
            temp.second++;
            s.push(temp);
            if(temp.first->left!=NULL){
                s.push(make_pair(temp.first->left, 1));
            }
        }
        if(s.top().second == 2){
            inorder_list.push_back(temp.first->data);
            s.pop();
            temp.second++;
            s.push(temp);
            if(temp.first->right!=NULL){
                s.push(make_pair(temp.first->right, 1));
            }
        }
        if(s.top().second == 3){
            postorder_list.push_back(temp.first->data);
            s.pop();
        }
    } 
    for(auto i: preorder_list){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i: inorder_list){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i: postorder_list){
        cout<<i<<" ";
    }
    cout<<endl;
}

void inorder(Node * root){
    vector<int> ans;
    if(root == NULL){
        return ;
    }
    stack<Node *> s;
    Node * newNode = root;
    do{
        if(newNode != NULL){
            s.push(newNode);
            newNode = newNode -> left;
        }
        else{
            if(s.empty()){
                break;
            }
            cout<<(s.top()->data)<<" ";
            newNode = s.top() -> right;
            s.pop();
        }
    }while(true);
}


int main(){
    Node * root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);
    all_traversals(root);
    // preorder(root);
    // cout<<endl;
    // inorder(root);
    // cout<<endl;
    // postorder1(root);
    return 0;
}