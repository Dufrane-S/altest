#include <bits/stdc++.h>

using namespace std;
int main(void){

    vector<int>nums;
    int x;
    cin>>x;
    for(int i=0;i<x;i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    sort(nums.begin(),nums.end());

    int y;
    cin>>y;
    vector<int>search;
    for(int i=0;i<y;i++){
        int b;
        cin>>b;
        search.push_back(b);
    }

    for(auto i:search){
        int start=0;
        int end=x-1;
        bool flag=true;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==i){
                cout<<1<<'\n';
                flag=false;
                break;
            }else if(nums[mid]>i){
                end=mid-1;
            }else if(nums[mid]<i){
                start=mid+1;
            }
        }
        if(flag)cout<<0<<'\n';
    }

}