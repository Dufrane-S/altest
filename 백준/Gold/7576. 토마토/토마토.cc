#include <bits/stdc++.h>

using namespace std;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main(void){
    int x,y;
    cin>>x>>y;
    int box[y][x];
    int done[y][x];
    queue<pair<int,int>> q;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            int a;
            cin>>a;
            box[i][j]=1;
            if(a==1) {
                q.push({i, j});
                done[i][j]=1;
            }else if(a==-1) { done[i][j] = 1; }else{
                done[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(0 <= ni && ni < y && nj >= 0 && nj < x && done[ni][nj]==0){
                done[ni][nj]=1;
                box[ni][nj]+=box[i][j];
                q.push({ni,nj});
            }
        }
    }
    int answer=0;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
           if(box[i][j]>answer)answer=box[i][j];
           if(done[i][j]==0){
               cout<<-1;
               return 0;
           }
        }
    }
    cout<<answer-1;
}