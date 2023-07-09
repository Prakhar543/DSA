#include <iostream>

using namespace std;

int partition(int *a, int si, int ei){
    int target = a[si];
    int countSmall = 0;

    for(int i = si; i<=ei; i++){
        if(a[i]<target)
            countSmall++;
    }
    //assigning the pivot
    a[si] = a[si+countSmall];
    a[si+countSmall] = target;
    int j = ei;


    for(int i = si; i<countSmall+si && j>countSmall+si; ){
        if(a[i]<target){
            i++;
        }
        else if(a[j]>target)
            j--;
        else{
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j--;
            i++; 
        }
        }
        
    
    return si+countSmall;
}

void quickSort(int *a, int si, int ei){
    if(si>=ei){
        return;
    }
    int c = partition(a, si, ei);
    quickSort(a, si, c-1);
    quickSort(a, c+1, ei);
    return;
}

int main(){
    int a[100];
    int size;
    cin>>size;
    for(int i = 0; i<size; i++){
        cin>>a[i];
    }
    quickSort(a, 0, size-1);
    for(int i = 0; i<size; i++){
        cout<<a[i]<<' ';
    }
    return 0;
}