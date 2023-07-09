#include <iostream>
#include "node.cpp"
#include "functions.cpp"

bool detect_cycle(Node * head){
    Node * fastptr = head;
    Node * slowptr = head;

    while (fastptr!=NULL && fastptr ->next != NULL){
        slowptr = slowptr -> next;
        fastptr = fastptr -> next -> next;
        if(slowptr == fastptr){
            return true;
        }
    }
    return false;
}

void remove_cycle(Node * head){
    Node * fastptr = head;
    Node * slowptr = head;

    do {
        slowptr = slowptr -> next;
        fastptr = fastptr -> next -> next;
    }while(slowptr!=fastptr);
    slowptr = head;
    while(fastptr -> next != slowptr -> next){
        fastptr = fastptr->next;
        slowptr = slowptr->next;
    }
    fastptr -> next = NULL;
}

using namespace std;
int main(){
    Node * n = NULL;
    insert_at_tail(n, 1);
    insert_at_tail(n, 2);
    insert_at_tail(n, 3);
    insert_at_tail(n, 4);
    insert_at_tail(n, 5);
    insert_at_tail(n, 6);
    makeCycle(n, 3);
    cout<<detect_cycle(n)<<endl;
    remove_cycle(n);
    display(n);
    
    return 0;
}