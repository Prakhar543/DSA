#include <iostream>
#include "Node.cpp"
#include <stack>

using namespace std;

//Also an example of Morris traversal -> time complexity O(n) and space complexity O(1)
void flatten(Node * root, Node * &prev, stack<int> &ans){
    if(root == NULL){
        return;
    }
    flatten(root -> right, prev, ans);
    flatten(root -> left, prev, ans);
    root -> right = prev;
    ans.push(root->data);
    prev = root;
    root -> left = NULL;

}

int main(){
    Node * root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);
    stack<int> ans;
    Node * prev = NULL;
    flatten(root, prev, ans);
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    return 0;
}