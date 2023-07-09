#include <iostream>
#include <queue>

using namespace std;

//making push costly
class Stack{
    queue<int> q1;
    queue<int> q2;
    public:
    void push(int val){
        q2.push(val);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop(){
        if(!q1.empty()){
            q1.pop();
        }
        else{
            return;
        }
    }

    int top(){
        if(q1.empty()){
            cout<<"Empty stack";
            return -1;
        }
        else{
            return q1.front();
        }
    }

    bool empty(){
        return q1.empty();
    }
};

class Stack1{
    queue<int> q1;
    queue<int> q2;
    public:
    void push(int val){
        q1.push(val);
    }

    void pop(){
        if(q1.empty()){
            cout<<"Empty stack";
            return;
        }
        else{
            while(q1.size() != 1){
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
            swap(q1, q2);
        }
    }

    int top(){
        if(q1.empty()){
            cout<<"Empty stack";
            return -1;
        }
        else{
            return q1.back();
        }
    }

    bool empty(){
        return q1.empty();
    }
};

int main(){
    Stack1 s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    cout<<s.top()<<endl;
    s.pop();
    s.pop();
    s.pop();
    cout<<s.top()<<endl;
    
    return 0;
}