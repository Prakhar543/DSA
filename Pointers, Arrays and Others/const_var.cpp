#include <iostream>

using namespace std;
int main(){
    
    //const variables need to be initialized at declaration same as reference varibles
    //while making a varibale constant the path to reach the memory is constant instead of the memory itself

    int j = 10;
    const int& k = j;
    j++;
    // k++;
    // the above code will error to k++ and not j++

    const int a = 10;
    int& b = a; // this will generate an erro as the reference type is int while a is const int 

    int x = 5;
    int y = 10;

    //In case of pointers things are a bit different.
    int * const p1 = &j; // this is a constant pointer to an integer
    //The above code means p1 is a constant pointer of type int * i.e. it can alter j but won't change the memory address it is pointing to.
    (*p1)++; //but this one won't give an error
    p1 = &x; //this line would give an error

    int const * p2 = &x; // this is a pointer to a constant integer
    //The above code makes pointer p2 i.e. not constant but won't change the memory it is pointing to, so
    p2 = &y; //this line won't give an error
    (*p2)++; //but this line will give an error

    int const * const p = &a; //this says that the pointer as well as the intger it is pointing to is constant
    // so now we can do neithe of the above things

    return 0;
}