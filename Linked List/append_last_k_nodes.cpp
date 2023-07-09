#include <iostream>
#include "node.cpp"
#include "functions.cpp"

using namespace std;

int length(Node * head){
    int l = 0;
    while(head != NULL){
        l++;
        head = head -> next;
    }
    return l;
}

// the function gives segmentation fault for both k == 1 %% k == length
void append(Node * &head, int k){
    int l = length(head);
    k = k%l;
    int count = 1;
    Node * temp = head;
    Node * newTail;
    Node * tail;
    Node * newHead;
    while(temp->next != NULL){
        if(count == l-k){
            newTail = temp;
        }
        else if(count == l-k+1){
            newHead = temp;
        }
        temp = temp -> next;
        count++;
    }
    tail = temp;
    tail -> next = head;
    head = newHead;
    newTail -> next = NULL;
}

int main(){
    Node * head = NULL;
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);
    insert_at_tail(head, 6);
    display(head);
    append(head, 5);
    display(head);
    return 0;
}