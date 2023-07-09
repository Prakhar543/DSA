#include <iostream>
#include <stack>


using namespace std;

vector<int> prevSmaller(vector<int> n){
    stack<int> s;
    vector<int> smal;
    for (int i = 0; i< n.size(); i++){
        while(!s.empty() && n[s.top()]>=n[i]){
            s.pop();
        }
        if(s.empty()){
            smal.push_back(-1);
        }
        else{
            smal.push_back(s.top());
        }
        s.push(i);
    }

    return smal;
}

void revers(vector<int> &n){
    int ptr1 = 0;
    int ptr2 = n.size() - 1;
    int temp;
    while(ptr1<ptr2){
        temp = n[ptr1];
        n[ptr1] = n[ptr2];
        n[ptr2] = temp;
        ptr1++;
        ptr2--;
    }
}

vector<int> nextSmaller(vector<int> n){
    stack<int> s;
    vector<int> large;
    for (int i = n.size()-1; i>= 0; i--){
        while(!s.empty() && n[s.top()]>=n[i]){
            s.pop();
        }
        if(s.empty()){
            large.push_back(9);
        }
        else{
            large.push_back(s.top());
        }
        s.push(i);
    }
    revers(large);
    return large;
}

int main(){
    // vector<int> v = {4, 2, 1, 5, 6, 3, 2, 4, 2};
    vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    v.push_back(2);
    vector<int> ans = prevSmaller(v);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    vector<int> ans1 = nextSmaller(v);
    for(auto i: ans1){
        cout<<i<<" ";
    }
    
    return 0;
}