#include <iostream>
#include "Node.cpp"

using namespace std;

Node * search(Node * root, int val){
    if(root == NULL){
        return NULL;
    }
    Node * ans;
    if(val>root->data){
        ans = search (root -> right, val);
    }
    else if(val<root->data){
        ans = search(root -> left, val);
    }
    else{
        ans = root;
    }
    return ans;
}

int main(){
    Node * root = new Node(8);
    root -> left = new Node(5);
    root -> left -> left= new Node(4);
    root -> left -> right= new Node(7);
    root -> left -> right -> left= new Node(6);
    root -> right = new Node(12);
    root -> right -> left= new Node(10);
    root -> right -> right = new Node(14);
    root -> right ->right -> left= new Node(13);

    Node * ans = search(root, 6);
    if(ans){
        cout<<ans->data;
    }
    else {
        cout<<"Not found";
    }

    
    return 0;
}