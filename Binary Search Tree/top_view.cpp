#include <map>
#include <iostream>
#include <queue>
#include "Node.cpp"

using namespace std;

vector<int> top(Node * root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int, int> tempAns;
    queue<pair<Node *, int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        Node * node = temp.first;
        int vertical = temp.second;
        if(tempAns.find(vertical) == tempAns.end()){
            tempAns[vertical] = node->data;
        }
        if(node -> left){
            q.push(make_pair(node->left, vertical -1));
        }
        if(node -> right){
            q.push(make_pair(node->right, vertical +1));
        }
    }
    for(auto i: tempAns){
        ans.push_back(i.second);
    }
    return ans;
}

int main(){
    Node * root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left= new Node(4);
    root -> left -> right= new Node(5);
    root -> right = new Node(3);
    root -> right -> left= new Node(6);
    root -> right -> right= new Node(7);
    vector<int> ans = top(root);
    for(auto i: ans){
        cout<<i<<" ";
    }
    
    return 0;
}