#include <iostream>
#include "node.cpp"

using namespace std;


void insert_at_head(Node* &head, int val){
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

bool search(Node* head, int target){
    Node * temp = head;
    while(temp -> next != NULL){
        if(temp -> val == target){
            return true;
        }
        temp = temp -> next;
    }
    return false;
}

void insert_at_tail(Node* &head, int val){

    Node *n = new Node(val);
    if(head == NULL){
        head = n;
        return;
    }
    Node * temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp-> next = n;

}


void reverse(Node * &head){

    Node * nice;
    Node * current = head;
    Node * prev = NULL;
    while(current!= NULL){
        nice = current -> next;
        current -> next = prev;
        prev = current;
        current = nice;
    }
    head = prev;
}


void deletion(Node* &head, int target){
    if(head == NULL){
        cout<<"Empty Linked List"<<endl;
        return;
    }
    else if(head -> val == target ){
        Node* toDelete = head;
        head = head -> next;
        delete toDelete;
        return;
    }

    Node* temp = head;
    while(temp->next->val != target){
        temp = temp->next;
    }
    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    
    delete toDelete;

}

void display(Node* head){
    while(head != NULL){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<"NULL";
    cout<<endl;
}


int main(){
    Node *n = NULL;
    insert_at_head(n, 1);
    insert_at_head(n, 2);
    insert_at_head(n, 3);
    insert_at_head(n, 4);
    insert_at_tail(n, 5);
    insert_at_tail(n, 5);
    insert_at_tail(n, 7);
    insert_at_head(n, 6);
    display(n);
    deletion(n, 7);
    display(n);

    return 0;
}