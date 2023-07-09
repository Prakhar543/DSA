#include <iostream>
#include "Node.cpp"

using namespace std;

int max_depth(Node * root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(max_depth(root->right), max_depth(root->left));
}

int main(){
    Node * root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    

    cout<<max_depth(root);
    return 0;
}