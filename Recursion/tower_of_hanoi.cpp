#include <iostream>

using namespace std;

//Beauty of recursion

void hanoi(int n, char s, char a, char d){
    if(n == 0){
        return;
    }
    hanoi(n-1, s, d, a);
    cout<<s<<" -> "<<d<<endl;
    hanoi(n-1, a, s, d);
    return;
}   

int main(){
    int n;
    cin>>n;
    char s = 's';
    char d = 'd';
    char a = 'a';
    hanoi(n, s, a, d);
    return 0;
}