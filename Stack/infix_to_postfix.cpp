#include <iostream>
#include <stack>

using namespace std;

int precedence(char c){
    switch (c)
    {   
    case '^':
        return 3;
    case '/':
        return 2;
    case '*':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    default:
        return -1;
    }
}

void infix_conversion(string input){
    stack<char> s;
    for (int i = 0; i<input.length(); i++){
        if(input[i] == '('){
            s.push(input[i]);
        }
        else if(input[i] == ')'){
            while(s.top() != '('){
                cout<<s.top();
                s.pop();
            }
            s.pop();
        }
        else if (input[i] == '+' || input[i] == '/' || input[i] == '*' || input[i] == '-'){
            while(!s.empty() && precedence(s.top())>precedence(input[i])){
                cout<<s.top();
                s.pop();
            }
            s.push(input[i]);
        }
        else
            cout<<input[i];
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
}

int main(){
    string input;
    cin>>input;
    infix_conversion(input);
    return 0;
}