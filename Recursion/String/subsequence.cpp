#include <iostream>

using namespace std;

int subs(string input, string* output){
    if(input.empty()){
        return 1;
        output[0] = '\0';
    }
    int size = subs(input.substr(1), output);
    for(int i = 0; i<size; i++){
        output[i+size] = input[0] + output[i]; 
    }
    return 2*size;
}

int main(){
    string input;
    cin>>input;
    string output[1000];
    int size = subs(input, output);    
    for(int i = 0; i<size; i++){
        cout<<output[i]<<endl;
    }
    return 0;
}