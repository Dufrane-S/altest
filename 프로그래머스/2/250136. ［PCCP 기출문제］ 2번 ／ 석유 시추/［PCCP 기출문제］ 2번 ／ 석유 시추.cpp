#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int box[500][500];
int n,m;
unordered_map<int,int>bank;
unordered_map<int,int>done;
int counter=-1;
void fill(int y, int x){
    queue<pair<int,int>>q;
    queue<pair<int,int>>pack;
    q.push({y,x});
    pack.push({y,x});
    box[y][x]=-1;
    while(!q.empty()){
        int nowy=q.front().first;
        int nowx=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int ny=nowy+dy[k];
            int nx=nowx+dx[k];
            if(ny<0||nx<0||ny==n||nx==m)continue;
            if(box[ny][nx]==1){
                q.push({ny,nx});
                pack.push({ny,nx});
                box[ny][nx]=box[nowy][nowx]-1;
            }
            
        }
    }
    bank[counter]=pack.size();
    while(!pack.empty()){
        box[pack.front().first][pack.front().second]=counter;
        pack.pop();
    }
    counter--;
}


int solution(vector<vector<int>> land) {
    int answer = 0;
    n=land.size();
    m=land[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            box[i][j]=land[i][j];
        }
    }
    
    

    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if(box[i][j]==1){
                fill(i,j);
            }
        }
    }
    for(int j=0;j<m;j++){
        int tmp=0;
        for(int i=0;i<n;i++){
            if(box[i][j]!=0 && done[box[i][j]]!=1){
                done[box[i][j]]=1;
                tmp+=bank[box[i][j]];
            }
        }
        if(answer<tmp)answer=tmp;
        done.clear();
    }
    
    
  
    return answer;
}