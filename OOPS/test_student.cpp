#include <iostream>
#include "complex.cpp"
#include "student.cpp"

using namespace std;
int main(){
    Student s1; //First Constructor
    Student s2(10, 20); //Third Constructor
    Student s3(10); // Second Constructor

    Student s4(s1); // Copy constructor called
    s3 = s1; // = assignment operator called
    Student s5 = s1; // interpreted as Student s5(s1);
    
    Student * s6 = new Student(); 
    // If object created dynamically it has to removed manually by using delete keywork
    delete s6;

    //Destructor called 5 times for each of the 5 objects and 1 corresponding to delete keyword


}