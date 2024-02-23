#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int box [26][26];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector<int> danji;

void bfs(int x,int y){
    if(box[y][x]==0)return;
    queue<pair<int,int>>q;
    int family=1;
    q.push({x,y});
    box[y][x]=0;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if (box[ny][nx]==1){
                family++;
                q.push({nx,ny});
                box[ny][nx]=0;
            }
        }
    }
    danji.push_back(family);
}

int main(){

    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=s.size();j++){
            box[i][j]=s[j-1]-'0';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            bfs(j,i);
        }
    }
    cout<<danji.size()<<'\n';
    sort(danji.begin(), danji.end());
    for(auto i:danji){
        cout<<i<<'\n';
    }
}