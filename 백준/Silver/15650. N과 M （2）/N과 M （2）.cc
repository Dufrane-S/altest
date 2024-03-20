#include <bits/stdc++.h>
using namespace std;

int x,y;
int done[10];
int arr[10];

void func(int n){
    if(n==y){
        for(int i=0;i<y;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=1;i<=x;i++){
        if(done[i]==1)continue;
        if(n>=1&&arr[n-1]>i)continue;
        arr[n]=i;
        done[i]=1;
        func(n+1);
        done[i]=0;
        arr[n+1]=0;
    }

}


int main(void){
    cin>>x>>y;
    func(0);
}