#include <iostream>

using namespace std;

int duplicate(int * input, int size){
    int ans = 0;
    for (int i = 0; i<size; i++){
        ans = ans^input[i];
        // cout<<ans<<" ";
    }
    if(ans == 0)
        return -1;
    else
        return ans;
}

int main(){
    int size;
    cin>>size;
    int * input = new int[size];
    for(int i = 0; i<size; i++){
        cin>>input[i];
    }

    int ans = duplicate(input, size);

    if(ans!=-1){
        cout<<ans;
    }

    return 0;
}