#include <iostream>

using namespace std;
int main(){
    /*Array size should be mentioned at compile time not at runtime i.e. you should not mention the size of the array as a variable.
    This is because if you mention the size as a constant the system will take the stack memory accordingly.
    Else the stack memory may be insufficient for the given array.
    Memory allocated in heap is called dynamic allocation, while that in stack is called static allocation */

    new int;//way to allocate memory on heap(heap memory can be accessed using the "new" keyword)
    // new int gives the address of the memory thus we can store the addess as

    int* p = new int; //this statement allocated 4bytes in heap and 8bytes in stack(pointer variable)

    *p = 10; //to access memory of heap
    //now we can use variable to specify size 
    int n;
    cin>>n;
    int* pa = new int[n];
    pa[0] = 10;
    cout<<pa[0]<<endl;
    //In dynamic allocation the variable does not destroys outside scope
    //To clear the dynamically allocated memory we need to use the "delete" keyword and mention the address of the allocated memory
    //This does not delete the memory of the pointer created in the stack
    delete p;
    
    //To delete and array write 
    delete [] pa; //to specify the memory is that of an array

    return 0;


}