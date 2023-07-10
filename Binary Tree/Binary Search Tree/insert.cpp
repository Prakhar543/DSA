#include <iostream>
#include "Node.cpp"

using namespace std;

bool isLeaf(Node * root){
    return (root->left == NULL) && (root->right == NULL);
}

void insert(Node * root, int temp){
    while(true){
        if(isLeaf(root)){
            Node * newNode = new Node(temp);
            if(root->data >temp){
                root -> left = newNode;
            }
            else{
                root -> right = newNode;
            }
        }
        if(root ->data > temp){
            root = root -> left;
        }
        else{
            root = root -> right;
        }
    }
}

int main(){
    
    return 0;
}