#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    sort(nums.rbegin(), nums.rend());
    int large=0;
    for(int i=0;i<nums.size();i++){
        if((i+1)*nums[i]>large)large=(i+1)*nums[i];
    }
    cout<<large;
}