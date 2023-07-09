#include <iostream>
#include "node.cpp"

using namespace std;

void insert_at_tail(DoubleNode * &head, int val){
    DoubleNode * newNode = new DoubleNode(val);
    if(head == NULL){
        head = newNode;
        return;
    }
    DoubleNode * temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> prev = temp;
    return;
}

void insert_at_head(DoubleNode * &head, int val){
    DoubleNode * newNode = new DoubleNode(val);
    if(head == NULL){
        head = newNode;
        return;
    }
    head -> prev = newNode;
    newNode -> next = head;
    head = newNode;
}

void deletion(DoubleNode * &head, int val){
    if(head == NULL){
        return;
    }
    else if (head -> val == val){
        head = head -> next;
        head -> prev = NULL;
    }
    DoubleNode * temp = head;
    while(temp != NULL){
        if(temp -> val == val){ 
            if(temp -> next != NULL){
                temp -> next -> prev = temp -> prev;
                temp -> prev -> next = temp -> next;
            }
            else{
                temp -> prev -> next = NULL;
            }
            
            delete temp;
            return;
        }
        temp = temp->next;
    }
    
}

void display(DoubleNode * head){
    while(head != NULL){
        cout<<head -> val<< " ";
        head = head -> next;
    }
    cout<<endl;
}   

int main(){
    DoubleNode * head = NULL;
    insert_at_tail(head, 5);
    insert_at_tail(head, 4);
    insert_at_tail(head, 3);
    insert_at_head(head, 2);
    insert_at_head(head, 1);
    insert_at_head(head, 4);
    display(head);
    deletion(head, 3);
    display(head);

    return 0;
}