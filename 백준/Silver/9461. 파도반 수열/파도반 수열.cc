#include <iostream>
using namespace std;
long long dp[101];
int main() {
    int x;
    cin>>x;
    for(int j=0;j<x;j++) {
        int a;
        cin>>a;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        dp[5] = 2;
        dp[6] = 3;
        for (int i = 6; i < 101; i++) {
            dp[i] = dp[i - 1] + dp[i - 5];
        }
        cout << dp[a]<<'\n';
    }
}