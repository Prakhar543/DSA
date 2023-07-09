#include <iostream>
#include "node.cpp"

using namespace std;

void insert_at_tail(Node * &head, int val){
    Node * newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        head ->next = head;
        return;
    }
    Node * temp = head;
    while(temp -> next != head && temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode ->next = head;
    return;
}
void insert_at_head(Node * &head, int val){
    Node * newNode = new Node(val);
    if(head == NULL){
        insert_at_tail(head, val);
        return;
    }
    Node * temp = head;
    while(temp -> next != head && temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> next = head;
    head = newNode;
}

void display(Node * head){
    Node * temp = head;
    do{
        cout<<temp ->val<<"->";
        temp = temp -> next;
    }while (temp!=head);
    cout<<"NULL"<<endl;
    
}

void deletion(Node * &head, int val){
    Node * temp = head;
    if(val == 1){
        Node * toDelete = head;
        while(temp -> next != head){
            temp = temp -> next;
        }
        temp -> next = head -> next;
        head = head -> next;
        return;
    }
    val = val - 2;
    while(val--){
        temp = temp ->next;
    }
    Node * toDelete = temp -> next;
    if(temp ->next -> next == head){
        temp -> next = head;
    }
    else{
        temp -> next = temp -> next ->next;
    }
    delete toDelete;
}


int main(){
    Node * head = NULL;
    insert_at_head(head, 1);
    insert_at_head(head, 2);
    insert_at_head(head, 3);
    insert_at_head(head, 4);
    deletion(head, 2);
    display(head);
    // cout<<head ->next->val;

    
    return 0;
}