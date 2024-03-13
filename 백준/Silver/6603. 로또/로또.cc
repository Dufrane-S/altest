#include <bits/stdc++.h>
using namespace std;

int x=1;
int nums[14];
int answer[14];
bool done[14];
void func(int n){
    if(n==6){
        for(int i=0;i<6;i++){
            cout<<answer[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<x;i++){
        if(!done[i]){
            if(answer[n-1]>nums[i])continue;
            answer[n]=nums[i];
            done[i]= true;
            func(n+1);
            done[i]=false;
        }
    }
}
int main(void){
    while(x!=0){
        cin>>x;
        for(int i=0;i<x;i++){
            int n;
            cin>>n;
            nums[i]=n;
        }
        func(0);
        cout<<'\n';
    }
}