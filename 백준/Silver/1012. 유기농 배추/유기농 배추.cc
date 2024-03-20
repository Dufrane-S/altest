#include <bits/stdc++.h>
using namespace std;
int box[51][51];
int answer;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int thex,they,z;
void bfs(int x,int y){
    queue<pair<int,int>>q;
    answer++;
    q.push({x,y});
    box[y][x]=0;
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx<0||ny<0||nx>=thex||ny>=they)continue;
            if(box[ny][nx]==0)continue;
            q.push({nx,ny});
            box[ny][nx]=0;
        }
    }
}

int main(void){
    int k;
    cin>>k;
    for(int d=0;d<k;d++){
        answer=0;
        cin>>thex>>they>>z;
        for(int i=0;i<z;i++){
            int a,b;
            cin>>a>>b;
            box[b][a]=1;
        }
        for(int i=0;i<they;i++) {
            for (int j = 0; j < thex; j++) {
                if (box[i][j] == 1) {
                    bfs(j, i);

                }
            }
        }
        cout << answer << '\n';
    }

}