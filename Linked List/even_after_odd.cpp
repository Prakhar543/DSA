#include <iostream>
#include "node.cpp"
#include "functions.cpp"

using namespace std;

void even_after_odd(Node * &head){
    Node * oddptr = head;
    Node * evenptr = head -> next;
    Node * evenStart = evenptr;
    while(oddptr -> next != NULL && evenptr -> next != NULL){
        oddptr ->next = evenptr ->next;
        oddptr = oddptr -> next;
        evenptr -> next = oddptr -> next;
        evenptr = evenptr -> next;
    }
    oddptr -> next = evenStart;
    
    return;

}


int main(){
    Node * head = NULL;
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);
    insert_at_tail(head, 6);
    insert_at_tail(head, 7);
    even_after_odd(head);
    display(head);
    return 0;
}