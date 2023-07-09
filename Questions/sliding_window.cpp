#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n, k;
    cin>>n;
    cin>>k;
    int * a = new int[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    vector <int> ans;
    deque<int> q;
    for (int i = 0; i<k; i++){
        while(!q.empty() && a[q.back()] < a[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(a[q.front()]);
    for(int i = k; i<n; i++){
        if(q.front() < i-k){
            q.pop_front();
        }
        while(!q.empty() && a[q.back()] < a[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);   
    }

    for( int i: ans){
        cout<<i<<" ";
    }


    return 0;
}