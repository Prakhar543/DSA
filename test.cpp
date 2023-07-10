#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node{
    
    public:
    int val;    
    Node * next;
    Node(int val){
        this -> val = val;
        next = NULL;
    }
};

void addFront(Node * &root, int start, int end){
    Node * temp = root;
    Node * startNode;
    Node * endNode;
    Node * startTail;
    Node * endTail;
    int i = 1;
    while(temp -> next!= NULL){
        if(i+1 == start){
            cout<<temp -> val<<endl;
            startTail = temp;
            temp = temp -> next;
            i++;
            cout<<temp -> val<<endl;
            startNode = temp;
            while(i!=end && temp -> next!= NULL){
                temp = temp -> next;
                i++;
            }
            endNode = temp;
            endTail = endNode -> next;
            endNode -> next = root;
            root = startNode;
            startTail->next = endTail;
            break;
        }
        temp = temp -> next;
        i++;
    }
}

void addBack(Node * &root, int start, int end){

    cout<<"hi";
    Node * temp = root;
    Node * startNode = NULL;
    Node * endNode = NULL;
    Node * startTail = NULL;
    Node * endTail = NULL;
    int i = 1;
    while(temp -> next!= NULL){
        if(start == 1 ){
            cout<<"hi";
            startNode = root;
            while(i!=end && temp -> next!= NULL){
                temp = temp -> next;
                i++;
            }
            endNode = temp;
            endTail = endNode -> next;
            root = endTail;
            
        }
        if(i+1 == start){
            startTail = temp;
            temp = temp -> next;
            i++;
            startNode = temp;
            while(i!=end && temp -> next!= NULL){
                temp = temp -> next;
                i++;
            }
            endNode = temp;
            endTail = endNode -> next;
        }
       
        temp = temp -> next;
        i++;
    }
    temp -> next = startNode;
    if(endNode)
    endNode -> next = NULL;
    if(startTail)
        startTail -> next = endTail;
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, t;
    // cin>>n;
    // cin>>t;
    n = 6;
    t = 1;
    Node * root = NULL;
    int a = 1;
    // cin>>a;
    root = new Node(a);
    Node * temp = root;
    for(int i = 2; i<n+1; i++){
        // int h;
        // cin>>h;
        Node * newNode = new Node(i);
        temp -> next = newNode;
        temp = temp -> next;
    }
    for(int i = 0; i<t; i++){
        int choice = 2, start = 1, end = 3;
        // cin>>choice; cin>>start; cin>>end;
        if(choice ==1){
            addFront(root, start, end);
        }
        else if(choice == 2){
            if(end == n){
               continue;
            }
            cout<<"hi";
            addBack(root, start, end);
        }
        
    }
    temp = root;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    cout<<abs(root -> val - temp -> val)<<endl;
    temp = root;
    while(temp -> next != NULL){
        cout<<temp -> val<<" ";
        temp = temp -> next;
    }
    cout<<temp -> val;
    return 0;
}
