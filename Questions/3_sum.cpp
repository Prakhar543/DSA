#include <iostream>

using namespace std;

bool check(vector<int> v, int target){
    sort(v.begin(), v.end());
    cout<<endl;
    for(int i = 0; i< v.size(); i++){
        int c = target - v[i];
        cout<<c<<endl;
        int start = i+1;
        int end = v.size()-1;
        while(start<end){
            cout<<v[end]+v[start]<<" ";
            if(v[start] + v[end] == c){
                return true;
            }
            else if(v[start] + v[end] < c){
                start++;
            }
            else{
                end--;
            }
        }
        cout<<endl;
    }
    return false;
}

int main(){
    vector<int> v;
    v.push_back(12);
    v.push_back(3);
    v.push_back(7);
    v.push_back(1);
    v.push_back(6);
    v.push_back(9);
    int target;
    cin>>target;
    cout<<check(v, target);
    return 0;
}