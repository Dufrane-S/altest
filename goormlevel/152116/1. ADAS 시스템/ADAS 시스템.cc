#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int ddx[8]={-1,0,1,-1,1,-1,0,1};
int ddy[8]={1,1,1,0,0,-1,-1,-1};
struct dot{
	int x;
	int y;
	int c;
	
	dot(int a, int b, int d){
		this->x=a;
		this->y=b;
		this->c=d;
	}
};

struct cmp{
	bool operator()(dot a, dot b){
		if(a.c!=b.c)return a.c<b.c;
		
		if(a.y==b.y)return a.x>b.x;
		return a.y>b.y;
	}
};

int main() {
	int answer=0;
	int w,h;
	cin>>h>>w;
	char box[h][w];
	bool done[h][w];
	priority_queue<dot,vector<dot>,cmp>pq;
	for(int i=0;i<h;i++){
		
		string temp;
		cin>>temp;
		
		for(int j=0;j<w;j++){
			
			box[i][j]=temp[j];
			done[i][j]=false;
			
			if(temp[j]=='S'){
				
				pq.push(dot(j,i,0));
				done[i][j]=true;
				
			}
			
		}
		
	}
	
	
	while(!pq.empty()){
		
		dot now = pq.top();
		
		if(now.c==3)break;
		
		pq.pop();
		
		if(now.c==2)answer-=3;
		
		for(int i=0;i<8;i++){
			int ny=now.y+ddy[i];
			int nx=now.x+ddx[i];
			if(nx<0||ny<0||nx>=w||ny>=h)continue;
			if(now.c!=0&&box[ny][nx]=='P')answer++;
		}
		
		for(int i=0;i<4;i++){
			int nx=now.x+dx[i];
			int ny=now.y+dy[i];
			if(nx<0||ny<0||nx==w||ny==h)continue;
			if(done[ny][nx])continue;
			int priority;
			if(box[ny][nx]=='E'){
				
				priority=3;
				
			}else if(box[ny][nx]=='P'){
				
				priority=2;
				
				
			}else if(box[ny][nx]=='0'){
				
				priority=1;
				
			}
			pq.push(dot(nx,ny,priority));
			done[ny][nx]=true;
		}
	}
	
	if(answer<0)answer=0;
	
	cout<<answer;
	return 0;
}