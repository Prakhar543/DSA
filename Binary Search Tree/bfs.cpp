#include <iostream>
#include "Node.cpp"
#include <queue>

using namespace std;

vector<vector<int> > bfs(Node* root){
    vector<vector<int> > ans;
    if(root == NULL){
        return ans;
    }
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int s = q.size();
        vector<int> level;
        for(int i = 0; i<s; i++){
            Node * temp = q.front();
            q.pop();
            if(temp->left != NULL){
                q.push(temp->left);
            }   
            if(temp -> right != NULL){
                q.push(temp->right);
            }
            level.push_back(temp -> data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main(){
    Node * root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);
    vector<vector<int> > ans = bfs(root);
    for(int i = 0; i<ans.size(); i++){
        for (int j = 0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}