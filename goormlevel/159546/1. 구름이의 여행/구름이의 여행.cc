#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	string answer="NO";
	bool done[1001];
	vector<int>bridge[1001];
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		bridge[a].push_back(b);
		bridge[b].push_back(a);
	}
	queue<pair<int,int>>q;
	q.push({1,0});
	done[1]=true;
	while(!q.empty()){
		int now = q.front().first;
		int deep = q.front().second;
		q.pop();
		if(now==n){
			answer="YES";break;
		}
		if(deep==k)continue;
		
		for(int i=0;i<bridge[now].size();i++){
			int next=bridge[now][i];
			if(done[next])continue;
			q.push({next,deep+1});
			done[next]=true;
		}
	}
	cout<<answer;
	
	
	return 0;
}