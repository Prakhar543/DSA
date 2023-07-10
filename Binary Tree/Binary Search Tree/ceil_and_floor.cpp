#include <iostream>
#include "Node.cpp"

using namespace std;

int floor(Node *root, int key){
    int floor = -1;
    while(root){
        if(root -> data < key){
            floor = root -> data;
            root = root -> right;
        }
        else if(root -> data > key){
            root = root -> left;
        }
        else {
            return root -> data;
        }
    }
        return floor;
}

int ceil(Node * root, int key){
     int c1 = 0;
    while(root!=NULL){
        if(root -> data == key){
            return root -> right;
        }
        else if(root -> data < key){
            root = root -> right;
        }
        else{
            c1 = root ->data;
            root = root -> left;
        }
    }
    return c1;
}

int main(){
    Node * root = new Node(10);
    root -> left = new Node(5);
    root -> left -> left= new Node(2);
    root -> left -> right = new Node(6);
    root -> right = new Node(15);

    cout<<floor(root, 7)<<endl;

    Node * root1 = new Node(5);
    root1 -> right = new Node(7);
    root1 -> right -> left= new Node(6);
    root1 -> right -> right= new Node(9);
    root1 -> right -> right -> left= new Node(8);
    root1 -> right -> right -> right= new Node(10);
    root1 -> left = new Node(3);
    root1 -> left -> right= new Node(4);
    root1 -> left -> left= new Node(2);
    root1 -> left -> left -> left= new Node(1);
 
    cout<<ceil(root1, 2);


    
    return 0;
}