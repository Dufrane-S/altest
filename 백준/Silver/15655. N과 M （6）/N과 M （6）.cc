#include <bits/stdc++.h>
using namespace std;

int x,y;
int arr[10];
int done[10];
vector<int>nums;
void func(int n){
    if(n==y){
        for(int i=0;i<y;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<x;i++){
        if(done[i])continue;
        if(arr[n-1]>nums[i])continue;
        arr[n]=nums[i];
        done[i]=1;
        func(n+1);
        done[i]=0;
    }

}


int main(void){
    cin>>x>>y;
    for(int i=0;i<x;i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    sort(nums.begin(),nums.end());
    func(0);
}