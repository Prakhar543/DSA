#include <iostream>

using namespace std;

int sum(int p[], int size){
    cout<<sizeof(p)<<endl;
    int sum = 0;
    for (int i = 0; i<size; i++){
        sum+= p[i];
    }
    cout<<sum;
    return 0;
}

int main(){
    int a[10];
    cout<<sizeof(a)<<endl;
    sum(a, 10);

    return 0;
}

//Important
/*We can even pass a part of the array using a+i instead of a when calling a function and entering the size accordingly.*/

