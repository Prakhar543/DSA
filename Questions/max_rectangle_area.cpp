#include <iostream>
#include <stack>



using namespace std;

//alt approach

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
            large.push_back(n.size());
        }
        else{
            large.push_back(s.top());
        }
        s.push(i);
    }
    revers(large);
    return large;
}

int max_area1(vector<int> v){
    vector<int> next = nextSmaller(v);
    vector<int> prev = prevSmaller(v);
    int ans = 0;
    for(int i = 0; i<v.size(); i++){
        int len = next[i]-prev[i]-1;
        int area = len*v[i];
        ans = ans>area?ans:area;
    }
    return ans;
}

int max_area(vector<int> v){
    int ans = 0;
    stack<int> s;
    v.push_back(0);
    for(int i = 0; i<v.size(); i++){
        while(!s.empty() && v[s.top()] > v[i]){
            int len;
            int height = v[s.top()];
            s.pop();
            if(s.empty()){
                len = i;
            }
            else{
                len = i - s.top() - 1;
            }
            ans = ans>len*height?ans:len*height;
        }
        s.push(i);
    }
    return ans;
}

int main(){ 
    vector<int> v;
    v.push_back(4);
    // v.push_back(2);
    // v.push_back(1);
    // v.push_back(5);
    // v.push_back(6);
    // v.push_back(3);
    // v.push_back(2);
    // v.push_back(4);
    // v.push_back(2);
    cout<<max_area1(v);


    return 0;
}