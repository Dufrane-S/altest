#include <bits/stdc++.h>

using namespace std;
long long dp[1000001];
int main(void){
    int x;
    cin>>x;
    vector<int>nums;
    for (int i=0;i<x;i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    for(int i=1;i<1000001;i++){
        int a=1;
        while(i*a<=1000000){
            dp[i*a]+=i;
            a+=1;
        }
    }
    for(int i=1;i<1000001;i++){
        dp[i]+=dp[i-1];
    }


    for(auto i: nums){
        cout<<dp[i]<<'\n';
    }
}