#include <iostream>
#include "Node.cpp"

using namespace std;

void k_small(Node * root, vector<int> &v){
    if(root == NULL){
        return;
    }
    k_small(root->left, v);
    v.push_back(root->data);
    k_small(root ->right, v);
}

int main(){
    vector<int> ans;
    Node * root = new Node(5);
    root -> left = new Node (3);
    root -> right = new Node (7);
    root -> right -> left = new Node (6);
    root -> right -> right = new Node (8);
    root -> left -> left= new Node (1);
    root -> left -> left -> right= new Node (2);
    root -> left -> right= new Node (4);
    int a = 6;
    k_small(root,ans);
    cout<<ans[a-1];
    
    return 0;
}