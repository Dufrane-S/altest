#include<bits/stdc++.h>

using namespace std;
int main(void){
	int n;
	cin>>n;
	vector<int>sorted;
	vector<int>nums;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		sorted.push_back(x);
		nums.push_back(x);
	}
	sort(sorted.begin(),sorted.end());
	
	map<int,int>m;
	
	int idx=0;
	int num=sorted[0];
	for(auto i:sorted){
		if(i==num){
			m[i]=idx;
		}else{
			idx++;
			num=i;
			m[i]=idx;
		}
	}
	for(auto i:nums){
		cout<<m[i]<<' ';
	}
}