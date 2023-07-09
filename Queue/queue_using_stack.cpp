#include <iostream>
#include <stack>

using namespace std;

class Queue{
    stack<int> s1;
    stack<int> s2;
    public:

    void pop(){
        if(s1.empty() && s2.empty()){
            cout<<"empty queue";
            return;
        }
        s1.pop();
    }

    void push(int val){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.push(val);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
    }

    bool empty(){
        return (s1.empty() && s2.empty());
    }

    int peek(){
        if(s1.empty() && s2.empty()){
            cout<<"empty queue";
            return -1;
        }
        else{
            return s1.top();
        }
    }
};

//using just one stack
class Queue1{
    stack<int> s1;
    public:
    void push(int val){
        s1.push(val);
    }

    int pop(){
        if(s1.empty()){
            return -1;
        }
        int top = s1.top();
        s1.pop();
        if(s1.empty()){
            return top;
        }
        int item = pop();
        s.push(top);
        return item;
    }

    bool empty(){
        return s1.empty();
    }
};

int main(){
    Queue s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.peek()<<endl;
    s.pop();
    s.pop();
    cout<<s.peek()<<endl;
    
    return 0;
}