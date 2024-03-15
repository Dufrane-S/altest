#include <bits/stdc++.h>
using namespace std;


int main(void){

    int x;
    cin>>x;
    vector<int>nums;
    for(int i=0;i<x;i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    int answer=0;
    for(int i = nums.size()-1; i>0;i--){
        if(nums[i]<=nums[i-1]){
            answer+=nums[i-1]-nums[i]+1;
            nums[i-1]=nums[i]-1;
        }
    }
    cout<<answer;
}