#include <iostream>
#include "Node.cpp"

using namespace std;

int height(Node * root){
    if(root == NULL){
        return 0;
    }
    int lf = height(root -> left);
    int rf = height(root -> right);
    return 1 + max(lf, rf);
}

bool check(Node * root){
    if(root == NULL){
        return true;
    }
    int left = height(root -> left);
    int right = height(root -> right);
    if(abs(left - right) >1){
        return false; 
    }

    return (abs(left - right) <=1) && check(root->left) && check(root -> right);
}   

//better solution in O(n)

int checkBalanced(Node * root){
    if(root == NULL){
        return 0;
    }
    int lh = checkBalanced(root -> left);
    int rh = checkBalanced(root -> right);
    if(lh == -1 && rh == -1){
        return -1;
    }
    if(abs(lh-rh)>1){
        return -1;
    }
    return 1 + max(lh, rh);
}

int main(){
    Node * root = new Node (1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);
    
    if(checkBalanced(root) > -1){
        cout << true;
    }
    else{
        cout << false;
    }
    
    return 0;
}