#include <bits/stdc++.h>
using namespace std;


int main(void){

    int x;
    cin>>x;
    vector<int>nums;
    vector<int>minus;
    int zeros=0;
    for(int i=0;i<x;i++){
        int a;
        cin>>a;
        if(a>0){
            nums.push_back(a);
        }else if(a==0){
            zeros++;
        }else{
            minus.push_back(-a);
        }


    }
    int answer=0;
    sort(nums.begin(), nums.end());
    sort(minus.begin(), minus.end());
    while(nums.size()>1){
        int j = nums[nums.size()-1];
        nums.pop_back();
        int k = nums[nums.size()-1];
        nums.pop_back();
        if(j==1||k==1){
            answer+=j;
            answer+=k;
        }else{
            answer+=j*k;
        }
        
    }
    if(!nums.empty()){
        answer+=nums[0];
    }
    while(minus.size()>1){
        int j = minus[minus.size()-1];
        minus.pop_back();
        int k = minus[minus.size()-1];
        minus.pop_back();
        answer+=j*k;

    }
    while(zeros>0&&minus.size()>0){
        zeros--;
        minus.pop_back();
    }
    if(!minus.empty()){
        answer-=minus[0];
    }

    cout<<answer;
}