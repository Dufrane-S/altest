#include <iostream>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main() {
	
	int n;
	int big=0;	
	int answer=0;
	cin>>n;
	int tree[n][n];
  int	surrounds[n][n];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int k;
			cin>>k;
			tree[i][j]=k;
			surrounds[i][j]=0;
			if(big<k)big=k;
		}
	}

	
	
	
	while(big){
		answer++;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(tree[i][j]==0)continue;
				int surround=0;
				for(int k=0;k<4;k++){
					int ni=dx[k]+i;
					int nj=dy[k]+j;
					if(ni<0||nj<0||ni==n||nj==n)continue;
					if(tree[ni][nj]==0){
						surround++;
					}
				}
				surrounds[i][j]=surround;
				
			}
		}
		big=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(tree[i][j]!=0){
					tree[i][j]-=surrounds[i][j];
					surrounds[i][j]=0;
					if(tree[i][j]<0)tree[i][j]=0;
				}
				if(tree[i][j]>big)big=tree[i][j];
			}
		}
		
	}
	
	cout<<answer;
	return 0;
}