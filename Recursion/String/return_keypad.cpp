#include <iostream>

using namespace std;

int subs(int input, string* output, string* ref){
    if(input == 0){
        output[0] = "";
        return 1;
    }
    int size = subs(input/10, output, ref);
    int digit = input%10;
    string copy[size];
    for(int i = 0; i<size; i++){
        copy[i] = output[i];
    }
    int count = 0;
    for(int i = 0; i<ref[digit-2].size(); i++){
        for(int j = 0; j<size; j++){
            output[count] = copy[j] + ref[digit-2][i];
            count++;
        }
    }
    return count;
}

int main(){
    int input;
    cin>>input;
    string arr[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string output[1000];
    int size = subs(input, output, arr);    
    for (int i = 0; i<size; i++){
        cout<<output[i]<<endl;
    }
    return 0;
}