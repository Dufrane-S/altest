#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int n,m,k;
bool done[10001];
vector<int>bri[10001];
int main() {
	
	cin>>n>>m>>k;
	bool flag=true;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		bri[a].push_back(b);
	
	}
	done[k]=true;
	int answer=-1;
	queue<pair<int,int>>q;
	for(auto i:bri[k]){
		q.push({i,1});
		done[i]=1;
	}
	
	while(!q.empty()&&flag){
		
		int now = q.front().first;
		int deep = q.front().second;
		q.pop();
		for(auto i:bri[now]){
			if(i==k){
				flag=false;
				answer=deep+1;
				break;
			}
			done[i]=1;
			q.push({i,deep+1});
		}
	}
	cout<<answer;
	return 0;
}