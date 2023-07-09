#include <iostream>
#include "node.cpp"
#include "functions.cpp"


using namespace std;

void reverse(Node * &head){

    Node * nice;
    Node * current = head ;
    Node * prev = NULL;
    while(current != NULL){
        nice = current -> next;
        current -> next = prev;
        prev = current;
        current = nice;
    }
    head = prev;
}



int main(){
    Node *n = NULL;

    insert_at_tail(n, 5);
    insert_at_tail(n, 4);
    insert_at_tail(n, 3);
    insert_at_tail(n, 2);

    display(n);
    reverse(n);
    display(n);
    return 0;
}