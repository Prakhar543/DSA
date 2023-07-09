#define n 100
using namespace std;

class Stack{
    int ptr;
    int * arr;
    public:
    Stack(){
        ptr = -1;
        arr = new int[n];
    }

    void push(int val){
        if(ptr == n-1){
            cout<<"No more space in stack";
            return;
        }
        ptr++;
        arr[ptr] = val;
    }

    void pop(){
        if(ptr == -1){
            cout<<"No element to pop";
            return;
        }
        ptr--;
    }

    int top(){
        if(ptr == -1){
            return -1;
        } 
        return arr[this -> ptr];
    }

    bool empty(){
        return ptr == -1;
    }
};