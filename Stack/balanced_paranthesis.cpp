#include <iostream>
#include <stack>

using namespace std;

bool check_top(char s1, char s2){
    return((s2 == '(' && s1 == ')') || (s2 == '{' && s1 == '}') || (s2 == '[' && s1 == ']'));
}

bool check(string s){
    stack<char> st;
    for (int i = 0; i<s.length(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        else{
            if(!st.empty() && check_top(s[i], st.top()))
                st.pop();
            else
                return false;
        }
    }
    return st.empty();
}

int main(){
    string input;
    cin>>input;
    cout<<check(input);    
    return 0;
}