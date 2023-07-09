#include <stack>
#include <iostream>

using namespace std;

bool check(string input){
    stack<char> s;
    for(int i = 0; i<input.length(); i++){
        if(input[i] == '(' || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
            s.push(input[i]);
        }
        else if(input[i] == ')'){
            if(s.empty() || s.top() == '('){
                return true;
            }
            else{
                while(s.top() != '('){
                    s.pop();
                }
                s.pop();
            }
        }
    }
    return false;
}

int main(){
    string input;
    cin>>input;
    cout<<check(input);
    
    return 0;
}