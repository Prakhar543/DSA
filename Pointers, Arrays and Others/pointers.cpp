#include <iostream>

using namespace std;
int main(){
char str[] = "abcde"; 
/* The above will make a temporary memory and make a copy of it with a memory assigned to it.
In case of character while printing str, we do not get the address of the variable while get all the characters till we encounter a null character.
So if we make a character variable and make its pointer while dereferencing it we will get the character and then some garbage values until a null character is there.
This is due to the way cout is implemented.*/
char *pstr = "abcde";
/*The above will make a temporary memory and the pointer will point to the same memory. This is never preferable.*/

char a = 'a';
char *p = &a;
cout<<p;

/*Arrays when passed in a function gets passed as a pointer. 
This can be confirmed by sizeof, in the main function the sizeof(a) gives 40(actual size of array)
but sizeof when called in the function where the array is passed gives 8 i.e. the size of the pointer. eg. in array_functions.cpp*/
    return 0;
}