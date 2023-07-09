#include <iostream>
#include <stack>

using namespace std;

string reverse_string(string &input){
    int len = input.length() - 1;
    string ans = "";
    for (int i = len; i>=0; i--){
        if(input[i] == '(')
            ans.push_back(')');
        else if(input[i] == ')')
            ans.push_back('(');
        else
            ans.push_back(input[i]);
    }
    return ans;
}

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
    string res = "";
    for (int i = 0; i<input.length(); i++){
        if(input[i] == '('){
            s.push(input[i]);
        }
        else if(input[i] == ')'){
            while(!s.empty() && s.top() != '('){
                res += s.top();
                s.pop();
            }
            if(!s.empty())
                s.pop();
        }
        else if (input[i] == '+' || input[i] == '/' || input[i] == '*' || input[i] == '-'){
            while(!s.empty() && precedence(s.top())>precedence(input[i])){
                res += s.top();
                s.pop();
            }
            s.push(input[i]);
        }
        else
            res += input[i];
    }
    while(!s.empty()){
        res += s.top();
        s.pop();
    }
    string ans = reverse_string(res);
    cout<<ans;
}

void infix_conversion1(string input){
    stack<char> s;
    string res = "";
    for(int i = 0; i<input.length(); i++){
        if(input[i] == '('){
            s.push(input[i]);
        }
        else if(input[i] == ')'){
            while(!s.empty() && s.top()!='('){
                res+= s.top();
                s.pop();
            }
            if(!s.empty()){
                s.pop();
            }
        }
        else if(input[i] == '+' || input[i] == '/' || input[i] == '*' || input[i] == '-'){
            while(!s.empty() && precedence(s.top()) > precedence(input[i])){
                res+=s.top();
                s.pop();
            }
            s.push(input[i]);
        }
        else{
            res+=input[i];
        }
        while(!s.empty()){
            res += s.top();
            s.pop();
            }
        string ans = reverse_string(res);
        cout<<ans;
    }
}


int main(){
    string input;
    cin>>input;
    string rev = reverse_string(input);
    infix_conversion(rev);
    return 0;
}