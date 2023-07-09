#include <iostream>

using namespace std;

void subs(string input, string output){
    if(input.empty()){
        cout<<output<<endl;
        return;
    }

    subs(input.substr(1), output);
    output += input[0];
    subs(input.substr(1), output);
}

int main(){
    string input;
    cin>>input;
    string output = "";
    subs(input, output);    
    // for(int i = 0; i<size; i++){
    //     cout<<output[i]<<endl;
    // }
    return 0;
}