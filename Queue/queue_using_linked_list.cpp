#include <iostream>

using namespace std;

class Node{
    public:
    Node * next;
    int val;
    Node(int val){
        this -> val = val;
        next = NULL;
    }
};

class Queue{
    Node * head;
    Node * tail;
    public:
    Queue(){
        head = NULL;
        tail = NULL;
    }

    void push(int val){
        Node* newNode = new Node(val);
        if(tail != NULL){
            tail->next = newNode;
            tail = tail->next;
        }
        else{
            tail = newNode;
        }
        if(head == NULL){
            head = newNode;
        }
    }

    void pop(){
        if(head == NULL){
            cout<<"Empty queue";
            return;
        }
        else{
            Node * toDelete = head;
            head = head -> next;
            delete toDelete;
        }
    }

    int  peek(){
        if(head == NULL){
            cout<<"Empty queue";
            return -1;
        }
        else{
            return head->val;
        }
    }
    int empty(){
        return head == NULL;
    }
};

int main(){
    Queue s;
    s.push(5);
    s.push(4);
    s.push(2);
    cout<<s.peek();
    s.pop();
    cout<<s.peek();

    return 0;
}