#include <iostream>
#include "node.cpp"
#include "functions.cpp"

using namespace std;

Node * merge (Node * head1, Node * head2){
    Node * result = new Node(-1);
    Node * p3 = result;
    while(head1!= NULL && head2!= NULL){
        if(head1 -> val > head2 -> val){
            // insert_at_tail(result, head2->val);
            p3 ->next =  head2;
            head2 = head2 -> next;
        }
        else{
            // insert_at_tail(result, head1->val);
            p3 -> next = head1;
            head1 = head1 -> next;
        }
        p3 = p3 ->next;
    }
    while(head1!=NULL){
        // insert_at_tail(result, head1->val);
        p3 -> next = head1;
        p3 = p3 ->next;
        head1 = head1 ->next;
    }
    while(head2!=NULL){
        // insert_at_tail(result, head2->val);
        p3 -> next = head2;
        p3 = p3 ->next;
        head2 = head2 ->next;
    }
    return result->next;
}

Node * mergeRecursive(Node * head1, Node * head2){
    if(head1 == NULL){
        return head2;
    }
    else if(head2 == NULL){
        return head1;
    }

    Node * result;

    if(head1 -> val < head2 -> val){
        result = head1;
        result -> next = mergeRecursive(head1 -> next, head2);
    }
    else{
        result = head2;
        result -> next = mergeRecursive(head1, head2 -> next);
    }
    return result;
}

int main(){
    Node * head1 = NULL;
    Node * head2 = NULL;
    insert_at_tail(head1, 1);
    insert_at_tail(head1, 3);
    insert_at_tail(head1, 5);
    insert_at_tail(head1, 7);
    insert_at_tail(head2, 2);
    insert_at_tail(head2, 4);
    insert_at_tail(head2, 6);
    insert_at_tail(head2, 8);
    display(head1);
    display(head2);
    Node * ans = mergeRecursive(head1, head2);
    display(ans);

    return 0;
}