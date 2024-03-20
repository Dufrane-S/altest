#include <bits/stdc++.h>
using namespace std;

int x,y;
int arr[10];
int done[10];
int sum=0;
map<string ,int>m;
vector<int>nums;
void func(int n){
    if(n==y){
        string s;
        for(int i=0;i<y;i++){
            s+=to_string(arr[i]);
            s+='+';
        }
        if(m[s]==0){
            for(int i=0;i<y;i++){
                cout<<arr[i]<<' ';
            }
            cout<<'\n';
            m[s]++;
        }
        return;
    }
    for(int i=0;i<x;i++){
        if(done[i]==1)continue;
        if(arr[n-1]>nums[i])continue;
        done[i]=1;
        arr[n]=nums[i];
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