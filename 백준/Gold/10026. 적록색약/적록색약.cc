#include <bits/stdc++.h>
using namespace std;

char box[101][101];
int done[101][101];

char rbox[101][101];
int rdone[101][101];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int thex;

int answer=0;
int ranswer=0;
void bfs(int j,int i){
    char c=box[i][j];
    queue<pair<int,int>>q;
    answer++;
    q.push({j, i});
    done[i][j]=1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            if(nx<0||ny<0||nx>=thex||ny>=thex)continue;
            if(done[ny][nx])continue;
            if(c!=box[ny][nx])continue;
            q.push({nx,ny});
            done[ny][nx]=1;
        }
    }
}
void rbfs(int j,int i){
    char c=rbox[i][j];
    queue<pair<int,int>>q;
    ranswer++;
    q.push({j, i});
    rdone[i][j]=1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            if(nx<0||ny<0||nx>=thex||ny>=thex)continue;
            if(rdone[ny][nx])continue;
            char nc = rbox[ny][nx];
            if(c=='B'){
                if(c!=nc)continue;
            }else{
                if(nc=='B')continue;
            }
            q.push({nx,ny});
            rdone[ny][nx]=1;
        }
    }
}



int main(void){
    cin>>thex;
    for(int i=0;i<thex;i++){
        string s;
        cin>>s;
        for(int j=0;j<thex;j++){
            box[i][j]=s[j];
            rbox[i][j]=s[j];
        }
    }

    for(int i=0;i<thex;i++){
        for(int j=0;j<thex;j++){
            if(done[i][j])continue;
            bfs(j,i);
        }
    }
    for(int i=0;i<thex;i++){
        for(int j=0;j<thex;j++){
            if(rdone[i][j])continue;
            rbfs(j,i);
        }
    }

    cout<<answer<<' '<<ranswer;
}