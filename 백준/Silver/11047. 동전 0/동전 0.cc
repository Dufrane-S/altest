#include<bits/stdc++.h>

using namespace std;
int main(void){
	int n,target;
	cin>>n>>target;
	vector<int> coins;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		coins.push_back(x);
	}
	reverse(coins.begin(),coins.end());
	int answer=0;
	for(auto i:coins){
		int coin = target/i;
		target=target%i;
		answer+=coin;
	}
	cout<<answer;
}