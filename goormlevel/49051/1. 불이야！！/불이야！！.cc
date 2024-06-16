#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main() {// . = 빈 칸  # 벽 @ 불 & 구름이
	int n,m; // n 세로, m 가로
	cin>>n>>m;
	int room[n][m]; // .은 0으로 초기화
	int done[n][m]; // 방문 여부
	int x,y;
	queue<pair<int,int>>q; // first = j 세로 // second = i 가로
	for(int i=0;i<n;i++){
		string temp;
		cin>>temp;
		for(int j=0;j<m;j++){
			room[i][j]=temp[j];
			if(temp[j]=='#'){ //벽이면 방문 상태
				done[i][j]=true;
			}else{ // 아니면 방문 X
				done[i][j]=false;
			}
			if(temp[j]=='@'){
				x=j;
				y=i;
				done[i][j]=true; //불도 방문 상태
				room[i][j]=0; // 시작 포인트이므로 0
				q.push({j,i}); // 미리 q에 넣어두기
			}
		}
	}
	
	int answer=INT_MAX;
	bool check=true; // 구름이 도착 확인용
	
	while(!q.empty()&&check){
		//현재 좌표 x,y
	  x =	q.front().first; 
		y = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){// dx dy로 상하좌우 좌표 생성
			int nx=dx[i]+x;
			int ny=dy[i]+y;
			if(done[ny][nx]||ny<0||nx<0||ny==n||nx==m)continue; //생성 좌표 방문했다면 / 범위 밖이라면 다음 생성
			if(room[ny][nx]=='&'){ // 다음 좌표가 구름이라면 중단 후 현재의 값을 답으로
				check=false; // check를 통해 불필요한 탐색없이 while문 탈출
				answer=min(room[y][x],answer);
				break;
			}
			done[ny][nx]=true;
			room[ny][nx]=room[y][x]+1;
			q.push({nx,ny});
		}
		
		
	}
	
	if(check){ // 구름이에게 도착 못했을 경우
		answer=-1;
	}
	cout<<answer;
	return 0;
}