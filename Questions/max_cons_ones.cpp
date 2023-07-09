#include <iostream>

using namespace std;

int max_ones(vector<int> v, int k){
    int i = 0, zerocnt = 0;
    int ans = 0;
    for(int j = 0; j<v.size(); j++){
        if(v[j] == 0){
            zerocnt++;
        }
        while(zerocnt>k){
            if(v[i] == 0){
            zerocnt--;
            }
            i++;
        }   
        ans = ans>(j-i)?ans:(j-i+1);
    } 
    return ans;
}

int main(){
    vector<int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);

    cout<<max_ones(v, 3);
    
    return 0;
}