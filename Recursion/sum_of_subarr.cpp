#include <iostream>

using namespace std;

void print(int * input, int size){
    for (int i = 0; i<size; i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
}

void calc(int * input, int size, int target, int * output, int out_size){
    if(target == 0){
        print(output, out_size);
        return;
    }
    if(size == 0 || target<0){
        output[out_size] = 0;
        out_size = 0;
        return ;
    }
    
    // cout<<target<<endl;
    calc(input+1, size-1, target, output, out_size);
    output[out_size] = input[0];
    calc(input+1, size-1, target-input[0], output, out_size+1);
    
}

int main(){
    int size, target;
    cin>>target;
    cin>>size;
    int * input = new int[size];
    for(int i = 0; i<size; i++){
        cin>>input[i];
    }
    int * output = new int[100];
    calc(input, size, target, output, 0);

    return 0;
}