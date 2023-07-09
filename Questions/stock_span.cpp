#include <iostream>
#include <queue>
#include <stack>


using namespace std;

vector<int> stock(vector<int> v){
    vector<int> ans;
    stack<pair<int,int> > st;
    for(int i = 0; i<v.size(); i++){
        int a = 1;
        while(!st.empty() && st.top().first < v[i]){
            a+=st.top().second;
            st.pop();
        }   
        st.push(make_pair(v[i], a));
        ans.push_back(a);
    }
    return ans;
}

int main(){
    vector<int> a;
    a.push_back(100);
    a.push_back(80);
    a.push_back(60);
    a.push_back(70);
    a.push_back(60);
    a.push_back(75);
    a.push_back(85);
    vector<int> ans = stock(a);
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}