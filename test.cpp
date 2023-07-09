#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void merge(vector<int> &n, int start, int end){
        int mid = (start+end)/2;
        int ptr1 = start;
        int ptr2 = mid+1;
        vector<int> temp;
        while(ptr1 <= mid && ptr2<=end){
            if(n[ptr1]>n[ptr2]){
                temp.push_back(n[ptr2]);
                ptr2++;
            }
            else{
                temp.push_back(n[ptr1]);
                ptr1++;
            }
        }
        while(ptr1 <= mid){
            temp.push_back(n[ptr1++]);
        }
        while(ptr2 <= end){
            temp.push_back(n[ptr2++]);
        }
        int j = 0;
        for(int i = start; i<=end; i++){
            n[i] = temp[j++];
        }
    }

    void mergeSort(vector<int> &n, int start, int end){
        if(start>=end){
            return;
        }
        int cen = (start + end)/2;
        // cout<<"hello"<<endl;
        mergeSort(n, start, cen);
        mergeSort(n, cen+1, end);
        merge(n, start, end);
    }

    void sortColors(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
    }
};

int main(){
    Solution s;
    vector<int> c;
    c.push_back(2);
    c.push_back(1);
    c.push_back(0);
    c.push_back(1);
    c.push_back(2);
    s.sortColors(c);
    for(auto i: c){
        cout<<i<< " ";
    }
    return 0;
}