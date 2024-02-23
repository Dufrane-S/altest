#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(void){
	int a;
	cin>>a;
	vector<pair<int,int>>cows;
	
	for(int i=0;i<a;i++){
		int x,y;
		cin>>x>>y;
		cows.push_back({x,y});
	}
	sort(cows.begin(),cows.end());
	priority_queue<int>pq;
	int time=0;
	int idx=0;
	while(!pq.empty()||idx<cows.size()){//first :arrive ; second : cost
		while(idx<cows.size()&&time>=cows[idx].first){
			pq.push(-cows[idx].second);
			idx++;
		}
		if(!pq.empty()){
			time-=pq.top();
			pq.pop();	
		}else{
			time=cows[idx].first;
		}
		
	}
	cout<<time;
}