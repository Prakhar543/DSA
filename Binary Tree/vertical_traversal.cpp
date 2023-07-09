#include <iostream>
#include <queue>
#include "Node.cpp"
#include <map>
#include <multiset>

//The code in this is correct just some issue with the multiset data structure not working on the laptop

using namespace std;

vector<vector<int> > vertical(Node * root){
    vector<vector<int> > result;
    if(root == NULL){
        return result;
    }
    map<int, map<int, multiset<int> > > ans;
    Node * temp = root;
    queue<pair<Node *, pair<int, int> > > q;
    q.push(make_pair(temp, make_pair(0, 0)));
    while(q.size() != 0){
        auto temp = q.front();
        q.pop();
        int x = temp.second.first;
        int y = temp.second.second;
        ans[x][y].insert(temp.first->data);
        if(temp.first -> left){
            q.push(make_pair(temp.first -> left, make_pair(x-1, y+1)));
        }
        if(temp.first -> right != NULL){
            q.push(make_pair(temp.first -> right, make_pair(x+1, y+1)));
        }  
    }
    for(auto i: ans){
        vector<int> col;
        for(auto j: i.second){
            col.insert(col.end(), j.second.begin(), j.second.end());
        }
        result.push_back(col);
    }
    return result;
    
}   

int main(){
    Node * root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    vector<vector<int> > ans = vertical(root);
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}