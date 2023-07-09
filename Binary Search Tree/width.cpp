#include <iostream>
#include <queue>
#include "Node.cpp"

using namespace std;

int width(Node * root){
    if(root == NULL){
        return 0;
    }
    int ans = 0;
    queue<pair<Node *, int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        int size = q.size();
        int mini = q.front().second;
        int first, last;
        for(int i = 0; i < size; i++){
            Node * temp = q.front().first;
            int curr = q.front().second - mini;
            q.pop();
            if(i == 0) first = curr;
            if(i == size - 1) last = curr;
            if(temp -> left) {
                q.push(make_pair(temp->left, 2*curr+1));
                cout<<2*curr+1<<endl;
            }
            if(temp -> right) {
                q.push(make_pair(temp->right, 2*curr+2));
                cout<<2*curr+2<<endl;
            }
        }
        ans = max(ans, last-first+1);
    }
    return ans;
}

int main(){
    Node * root = new Node(7);
    root -> left = new Node(4);
    root -> left -> left = new Node(4);
    root -> left -> left -> left = new Node(4);
    root -> left -> left -> left -> left = new Node(4);
    root -> left -> left -> left -> left -> left = new Node(4);
    root -> left -> left -> left -> left -> left -> left  = new Node(4);
    root -> left -> left -> left -> left -> left ->left ->left= new Node(4);
    root -> right = new Node(3);
    root -> right -> left = new Node(4);
    root -> right -> left -> left = new Node(4);
    root -> right -> left -> left -> left = new Node(4);
    root -> right -> left -> left -> left -> left = new Node(4);
    root -> right -> left -> left -> left -> left -> left  = new Node(4);
    root -> right -> left -> left -> left -> left ->left ->left= new Node(4);
    cout<<width(root);
    
    return 0;
}