#include <bits/stdc++.h>


using namespace std;
int main(void){
    int x;
    vector<int>nums;
    cin>>x;
    for(int i=0;i<x;i++){
        int s;
        cin>>s;
        nums.push_back(s);
    }
    int answer [11];
    answer[0]=0;
    answer[1]=1;
    answer[2]=2;
    answer[3]=4;
    for(int i=4;i<11;i++){
        answer[i]=answer[i-1]+answer[i-2]+answer[i-3];
    }
    for(auto i:nums){
        cout<<answer[i]<<'\n';
    }
}