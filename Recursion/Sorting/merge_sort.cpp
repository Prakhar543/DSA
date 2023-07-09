#include <iostream>

using namespace std;

void merge(int a[], int start, int end){
    int mid = (start+end)/2;
    int x = start;
    int y = mid+1;
    int temp[end-start+1];
    int i = 0;
    while(x<=mid && y<=end){
        if(a[x] > a[y]){
            temp[i] = a[y];
            y++;
        }
        else{
            temp[i] = a[x];
            x++;
        }
        i++;
    } 
    while(x<=mid){
        temp[i] = a[x];
        x++;
        i++;
    }
    while(y<=end){
        temp[i] = a[y];
        y++;
        i++;
    }
    i = 0;
    for(int j = start; j<=end; j++){
        a[j] = temp[i];
        i++;
    }
    return;
}

void sort(int *a, int start, int end){
    if(end<=start)
        return ;
    int mid = (start+end)/2;
    sort(a, start, mid);    
    sort(a, mid+1, end);
    merge(a, start, end);    
    return;
}

int main(){
    
    int a[10] = {1,2,3,4,2,2,2,1,2,4};
    sort(a, 0, 9);
    for (int i = 0; i<10; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}