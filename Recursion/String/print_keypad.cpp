#include <iostream>

using namespace std;

void subs(int input, string output, string * ref){
    if(input == 0){
        cout<<output<<endl;
        return;
    }
    int digit = input%10;
    for(int i = 0; i<ref[digit-2].size(); i++){
        subs(input/10, output+ref[digit-2][i], ref);
    }
}

int main(){
    int input;
    cin>>input;
    string arr[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string output = "";
    subs(input, output, arr);    

    return 0;
    return 0;
}