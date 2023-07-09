#include <iostream>
#include "node.cpp"
#include "functions.cpp"

using namespace std;

Node * k_reverse(Node * &head, int k){

    Node * prevptr = NULL;
    Node * currentptr = head;
    Node * nextptr; 
    int count = 0;
    while(count < k && currentptr != NULL){
        nextptr = currentptr -> next;
        currentptr -> next = prevptr;
        prevptr = currentptr;
        currentptr = nextptr;
        count++;
    }
    if(nextptr != NULL){
        head->next = k_reverse(nextptr, k);
    }
    head = prevptr;

    return head;

}


int main(){
    Node * n = NULL;
    insert_at_tail(n, 1);
    insert_at_tail(n, 2);
    insert_at_tail(n, 3);
    insert_at_tail(n, 4);
    insert_at_tail(n, 5);
    insert_at_tail(n, 6);
    display(n);
    Node * newHead = k_reverse(n, 4);
    display(n);
    
    return 0;
}