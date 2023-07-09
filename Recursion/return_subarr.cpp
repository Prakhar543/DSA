#include <iostream>

using namespace std;

int print(int * input, int ** output, int size){
    if(size == 0){
        output[0] = new int[1];
        output[0][0] = 0;
        return 1;
    }
    int len = print(input+1, output, size-1);
    for(int i = 0; i<len; i++){
        int new_size = output[i][0]+ 1;
        output[len+i] = new int[new_size];
        output[len+i][0] = new_size;
        output[len+i][1] = input[0];

        for(int j = 2; j<=new_size; j++){
            output[len+i][j] = output[i][j-1];
        }
    }
    return 2*len;

}

int main(){
    int size;
    cin>>size;
    int * input = new int[size];
    for (int i = 0; i<size; i++){
        cin>>input[i];
    }    
    int ** output = new int * [100];
    int len = print(input, output, size);
    for (int i = 0; i<len; i++){
        for(int j = 0; j < output[i][0]; j++){
            cout<<output[i][j+1]<<" ";
        }
        cout<<endl;
    }
    return 0;
}