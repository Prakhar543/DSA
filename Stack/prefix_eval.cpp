#include <iostream>
#include <math.h>
#include <stack>

using namespace std;

//for postfix just reverse the for loop from i = 0 to i<input.length()

int eval(string input){
    int oper1;
    int oper2;
    stack <int> s;
    for (int i = input.length()-1; i>=0; i--){
        if(input[i] == '+' || input[i] == '/' || input[i] == '*' || input[i] == '-' || input[i] == '^'){
            oper1 = s.top();
            s.pop();
            oper2 = s.top();
            s.pop();
            switch (input[i])
            {
            case '+':
                s.push(oper1 + oper2);
                break;
            
            case '-':
                s.push(oper1 - oper2);
                break;

            case '*':
                s.push(oper1 * oper2);
                break;

            case '/':
                s.push(oper1 / oper2);
                break;
            
            case '^':
                s.push(pow(oper1, oper2));
                break;
            }
        }
        else{
            s.push(int(input[i] - '0') );
        }
    }
    return s.top();
}

int main(){
    string input;
    cin>>input;
    cout<<eval(input);

    return 0;
}