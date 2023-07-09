#include <iostream>
#include "Node.cpp"

using namespace std;

int search(int val, int inorder[], int start, int end){
    int data;
    for(int i = start; i<end; i++){
        if(inorder[i] == val){
            data = i;
            break;
        }
    }
    return data;
}

Node * build_from_post(int postorder[], int inorder[], int start, int end, int &i){
    if(start>end){
        return NULL;
    }
    int curr = postorder[i--];
    Node * newNode = new Node(curr);
    if(start == end){
        return newNode;
    }
    int pos = search(curr, inorder, start, end);
    newNode -> right = build_from_post(postorder, inorder, pos+1, end, i);
    newNode -> left = build_from_post(postorder, inorder, start, pos-1, i);
    return newNode;
}

Node * build_from_pre(int preorder[], int inorder[], int start, int end){
    if(start > end){
        return NULL;
    }
    static int id = 0;
    int val = preorder[id++];
    Node * newNode = new Node(val);
    if(start == end){
        return newNode;
    }
    int pos = search(val, inorder, start, end);
    newNode -> left = build_from_pre(preorder, inorder, start, pos -1);
    newNode -> right = build_from_pre(preorder, inorder, pos+1, end);
    return newNode;
}

void inorder_trav(Node * root){
    if(root == NULL){
        return;
    }
    inorder_trav(root->left);
    cout<<root->data<<" ";
    inorder_trav(root->right);
}

int main(){
    int i = 6;
    int postorder[] = {4, 5, 2, 6, 7, 3, 1};
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};

    // Node * root = build_from_pre(preorder, inorder, 0, 6);
    // cout<<root->left->right->data<<endl;
    Node * root1 = build_from_post(postorder, inorder, 0, 6, i);
    inorder_trav(root1);
    
    return 0;
}