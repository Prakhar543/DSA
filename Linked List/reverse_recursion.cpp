#include <iostream>
#include "node.cpp"
#include "functions.cpp"

using namespace std;

Node* reverse_recursively(Node * head){
    if(head -> next == NULL){
        return head;
    }
    Node * smallerHead = reverse_recursively(head->next);
    head->next->next = head;
    head -> next = NULL;
    return smallerHead;
}

int main(){
    Node * n = NULL;
    insert_at_tail(n, 1);
    insert_at_tail(n, 2);
    insert_at_tail(n, 3);
    insert_at_tail(n, 4);
    insert_at_tail(n, 5);
    insert_at_tail(n, 6);
    insert_at_tail(n, 7);
    display(n);
    Node* newHead = reverse_recursively(n);
    display(newHead);



    return 0;
}