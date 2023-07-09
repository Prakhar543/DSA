#include <iostream>
#include "stack.cpp"

using namespace std;
int main(){
    Stack s1;
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    cout<<s1.top()<<endl;
    s1.pop();
    s1.pop();
    s1.pop();
    cout<<s1.top()<<endl;
    cout<<s1.empty();
    s1.pop();
    
    return 0;
}