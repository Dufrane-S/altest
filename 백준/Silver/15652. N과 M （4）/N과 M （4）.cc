#include <bits/stdc++.h>
using namespace std;

int x,y;
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
        if(arr[n-1]>i)continue;
        arr[n]=i;
        func(n+1);
    }

}


int main(void){
    cin>>x>>y;
    func(0);
}