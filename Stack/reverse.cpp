#include <iostream>
#include <stack>

using namespace std;

void display(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void insert_at_bottom(stack<int> &st, int val){
    if(st.empty()){
        st.push(val);
        return;
    }
    int topelement = st.top();
    st.pop();
    insert_at_bottom(st, val);
    st.push(topelement);
}

void reverse_recursively(stack<int> &s){
    if(s.empty()){
        return;
    }
    int top = s.top();
    s.pop();
    reverse_recursively(s);
    insert_at_bottom(s, top);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    display(s);
    reverse_recursively(s);
    display(s);
    
    return 0;
}