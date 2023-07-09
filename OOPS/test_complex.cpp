#include <iostream>
#include "complex.cpp"

using namespace std;
int main(){
    
    int real1, real2, imaginary1, imaginary2;
    cin>>real1>>imaginary1;
    cin>>real2>>imaginary2;

    Complex c1(real1, imaginary1);
    Complex c2(real2, imaginary2);

    int choice;
    cin>>choice;

    if(choice == 1){
        c1.add(c2);
        c1.print();
    }
    else if(choice == 2){
        c1.multiply(c2);
        c1.print();
    }


    return 0;
}