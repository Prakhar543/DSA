#include <iostream>
//the above #codes are put even before the compilation so we can define some constants here
#define PI 3.14
// What this above statement does is that it replaces 3.14 inplace of PI everywhere in the code, even before compilation
// So no extra memory is used and it can't be changed in the code

//Using global variables is not a good practice as its value can be changed by any function. So if you want the changes to get reflected in the actual variable pass by ref.

using namespace std;
int main(){
    cout<<PI;
    return 0;
}