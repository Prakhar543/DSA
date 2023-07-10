#include <iostream>
#include "Node.cpp"

using namespace std;

void deleteNode(Node * &temp, int key){
    Node * prev = NULL;
    Node * root = temp;
    while(root){
        if(key < root->data){
            prev = root;
            root = root -> left;
        }
        else if(key > root -> data){
            prev = root;
            root = root -> right
        }
        else{
            Node * toDelete = root;
            root = root -> right;
            Node * leftSubtree = root -> left;
            if(prev == NULL){
                temp = root ;
            }
            else if(prev -> data > key){
                prev -> left = ;
            }
            else {
                prev -> right = root ; 
            }
            if(leftSubtree == NULL){
                return root;
            }
            while(root -> left){
                root = root -> left;
            }
            root -> left = leftSubtree;
        }
    }
}

int main(){
    
    return 0;
}