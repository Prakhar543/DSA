#include <iostream>
#include <stack>

using namespace std;

void reverse_sentence(string s){
    stack <string> s1;
    for(int i = 0; i<s.length(); i++){
        string word = "";
        while(s[i] != ' ' && i<s.length()){
            word.push_back(s[i]);
            i++;
        }
        s1.push(word);
    }
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
}

int main(){
    string input = "You are good at it.";
    reverse_sentence(input);
    
    return 0;
}