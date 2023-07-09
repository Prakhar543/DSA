#include <iostream>
#define n 100

using namespace std;

class Queue{
    int front;
    int back;
    int * arr;

    public:
    Queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int val){
        if(back == n-1){
            cout<<"Queue overflow";
            return;
        }
        back++;
        this -> arr[back] = val;
        if(front == -1){
            front++;
        }
    }

    void pop(){
        if(front != -1 && front <=back){
            front ++;
        }
        else{
            cout<<"No elements in queue";
            return;
        }
    }

    int peek(){
        if(front != -1 && front <=back){
            return arr[front];
        }
        else{
            return -1;
        }
    }
    
    bool empty(){
        return(front == -1 || front > back);
    }
};

int main(){
    Queue q;
    q.push(5);    
    q.push(4);    
    q.push(3);    
    q.push(2);    
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek();
    cout<<q.empty();
    return 0;
}