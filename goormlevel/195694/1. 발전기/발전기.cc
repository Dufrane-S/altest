#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main() {
	int n;
	cin>>n;
	vector<vector<int>>box=vector<vector<int>>(n,vector<int>(n,0));
	vector<vector<int>>done=vector<vector<int>>(n,vector<int>(n,0));
	int answer=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int a;
			cin>>a;
			box[i][j]=a;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(box[i][j]==1 && done[i][j]==0){
				queue<pair<int,int>>q;
				q.push({i,j});
				done[i][j]=1;
				answer++;
				while(!q.empty()){
					int nowy=q.front().first;
					int nowx=q.front().second;
					q.pop();
					for(int k=0;k<4;k++){
						int ny=nowy+dy[k];
						int nx=nowx+dx[k];
						if(ny<0||nx<0||ny==n||nx==n||done[ny][nx]==1||box[ny][nx]==0)continue;
						q.push({ny,nx});
						done[ny][nx]=1;
					}
				}
			}
		}
	}
	cout<<answer;
	return 0;
}