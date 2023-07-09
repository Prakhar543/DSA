#include <iostream>
#include "Node.cpp"
#include <stack>

using namespace std;

bool isLeaf(Node * root){
    return (root->left == NULL) && (root->right == NULL);
}

void addLeftBoundary(Node * root, stack<int> &s){
    if(root == NULL){
        return;
    }
    Node * temp = root -> left;

    while(temp){
        if(!isLeaf(temp)){
            s.push(temp->data);
        }
        if(temp -> left != NULL){
            temp = temp -> left;
        }
        else{
            temp = temp -> right;
        }
    }
}

void addLeaves(Node * root, stack<int> &s){
    if(root == NULL){
        return;
    }
    addLeaves(root -> left, s);
    if(isLeaf(root)){
        s.push(root->data);
    }
    addLeaves(root -> right, s);
}

stack<int> addRightBoundary(Node * root){
    stack<int> ans;
    if(root == NULL){
        return ans;
    }
    Node * temp = root -> right;
    while(temp){
        if(!isLeaf(temp)){
            ans.push(temp -> data);
        }
        if(temp -> right != NULL){
            temp = temp -> right;
        }
        else{
            temp = temp -> left;
        }
    }
    return ans;
}


int main(){
    Node * root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);


    stack<int> s;
    addLeftBoundary(root, s);
    addLeaves(root, s);
    stack<int> right = addRightBoundary(root);
    while(!right.empty()){
        s.push(right.top());
        right.pop();
    }
    s.push(root->data);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    
    return 0;
}