#include <bits/stdc++.h>
using namespace std;

int n,s;
int arr[30];
int cnt=0;

void func(int cur, int tot){
    if(cur==n){
        if(tot==s)cnt++;
        return;
    }
    func(cur+1,tot);
    func(cur+1,tot+arr[cur]);
}



int main(void){
    cin>>n>>s;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr[i]=a;
    }
    func(0,0);
    if(s==0)cnt--;
    cout<<cnt;
}