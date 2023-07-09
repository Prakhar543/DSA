#include <iostream>

using namespace std;
int main(){
    int** p = new int*[2]; //no. of rows are specified here
    for (int i =0; i<2; i++){
        p[i] = new int[3];
        for (int j = 0; j<3; j++){
            cin>>p[i][j];
        }
    }
    cout<<p[1][1];
    return 0;
}