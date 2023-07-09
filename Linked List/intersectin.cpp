#include <iostream>
#include "node.cpp"
#include "functions.cpp"

using namespace std;

int length(Node * head){
    int count == 0;
    while(head != NULL){
        count ++;
        head = head -> next;
    }
    return length;
}

int intersection(Node* head1, Node * head2){
    int l1 = length(head1);
    int l2 = length(head2);
    Node * ptr1;
    Node * ptr2;
    int d = 0;
    if (l1>l2){
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while(d){
        d--;
        if(ptr1 == NULL)
            return -1;
        ptr1 = ptr1 ->next;
    }
    while(ptr1 ->next != NULL){
        if(ptr1 == ptr2)
            return ptr1 -> val;
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
    return -1;
}

int main(){
    Node * head = NULL;
    
    return 0;
}