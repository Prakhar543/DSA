#include <iostream>

using namespace std;

inline int max(int a, int b){
    return (a>b)?a:b;
}
/*The use of inline function is similar to #define as it copies that part of the code
wherever its called in the main function thus not hindering the flow of the code and also 
making the code more readable.*/

/*All the functions cannot be made inline and depends on the compiler
1 line functions can mostly be declared as inline, 
2-3 line may sometimes work but not always, 
>3 line funcitons are not made inline by the compiler*/

/*If a function takes in 3 arguments we can make some of the arguments as optional by giving a default value to one of the arguments*/
void nice(int a, int b, int c= 0){
    return a+b+c;
}
//In the above function the variable c is optional to be passed while calling the function
//The default value needs to be given to all the variables starting from right. We cannot do something like giving default value to second and not to third.


int main(){
    
    int a=10;
    int b=12;
    int c = max(a,b);

    int x=20;
    int y=12;
    int z = max(x,y);

    cout<< c<< " " << z;

    return 0;
}