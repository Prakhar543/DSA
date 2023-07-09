#include <iostream>
#include <queue>
#include "Node.cpp"
#include<map>

using namespace std;

void bottom(Node * root){
    // vector<int> ans;
    if(root == NULL){
        return ;
    }
    queue<pair<Node *, int> > q;
    map<int, int> tempAns;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        auto i = q.front();
        q.pop();
        Node * temp = i.first;
        int vertical = i.second;
        tempAns[vertical] = temp -> data;
        if(temp ->left){
            q.push(make_pair(temp->left, vertical-1));
        }
        if(temp ->right){
            q.push(make_pair(temp->right, vertical+1));
        }
    }
    for(auto i: tempAns){
        cout<<i.second<<" ";
    }
    return ;

}

int main(){
    Node * root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> left -> right -> left = new Node(8);
    root -> left -> right -> right = new Node(9);
    
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    bottom(root);
    
    return 0;
}