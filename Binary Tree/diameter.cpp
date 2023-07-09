#include <iostream>
#include "Node.cpp"

using namespace std;

int diameter(Node * root, int &maxi){
    if(root == NULL){
        return 0;
    }

    int lh = diameter (root -> left, maxi);
    int rh = diameter (root -> right, maxi);
    maxi = max(maxi, lh + rh + 1);
    return 1 + max(lh, rh);

}

int main(){
    Node * root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node (4);
    root -> left -> right -> left= new Node (4);
    root -> left -> right -> right= new Node (4);
    root ->right = new Node(4);
    root ->right -> right = new Node(4);
    root ->right -> right -> right= new Node(4);
    root ->right -> right -> right -> left= new Node(4);
    root ->right -> right -> right -> left -> right= new Node(4);
    root ->right -> right -> right -> right= new Node(4);


    
    // root -> left -> left = new Node(4);
    // root -> left -> right = new Node(5);
    // root -> right -> left = new Node(6);
    // root -> right -> right = new Node(7);

    int maxi = 0;
    int a = diameter(root, maxi);
    cout << maxi;
    
    return 0;
}