#include <bits/stdc++.h>
int dp[100001];
using namespace std;
int main(void){
    int x,y;
    cin>>x>>y;
    for(int i=1;i<=x;i++){
        int a;
        cin>>a;
        dp[i]=dp[i-1]+a;
    }
    vector<int>answer;
    for(int i=0;i<y;i++){
        int a,b;
        cin>>a>>b;

        answer.push_back(dp[b]-dp[a-1]);
    }
    for(auto i:answer) { cout << i<<'\n'; }
}