#include <bits/stdc++.h>


int answer[1000001];
using namespace std;
int main(void){
    answer[1]=0;
    int x;
    cin>>x;
    for(int i=2;i<=x;i++) {
        if(i%3==0&&i%2==0){
            answer[i]=min(min(1+answer[i/3],1+answer[i/2]),1+answer[i-1]);
        }else if(i%3==0){
            answer[i]=min(1+answer[i/3],1+answer[i-1]);
        }else if(i%2==0){
            answer[i]=min(1+answer[i/2],1+answer[i-1]);
        }else{
            answer[i]=answer[i-1]+1;
        }
    }
    cout<<answer[x];
}