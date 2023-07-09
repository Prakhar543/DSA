#include <iostream>

using namespace std;

void print2(int * input, int size){
    for (int i = 0; i<size; i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
}


void print(int * input, int * output, int inp_size, int out_size){
    if(inp_size == 0){
        output[out_size] = 0;
        print2(output, out_size);
        return;
    }
    print(input+1, output, inp_size-1, out_size);
    output[out_size] = input[0];
    print(input+1, output, inp_size-1, out_size+1);

}

int main(){
    int size;
    cin>>size;
    int * input = new int[size];
    for(int i = 0; i<size; i++){
        cin>>input[i];
    }
    int * output = new int[size];
    print(input, output, size, 0);


    return 0;
}