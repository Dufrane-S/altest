#include <iostream>
#include <string>
#include <queue>
using namespace std;

int box[101][101];
int done[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main()
{
    int y,x;
    cin>>y>>x;
    for(int i=1;i<=y;i++){
        string s;
        cin>>s;
        for(int j=1;j<=s.size();j++){
            box[i][j]=s[j-1]-'0';
        }
    }
  
    queue<pair<int,int>>q;
    q.push({1,1});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        done[y][x]=1;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            if(done[ny][nx]==0&&box[ny][nx]==1){
                q.push({nx,ny});
                box[ny][nx]+=box[y][x];
            }
        }

    }
    cout<<box[y][x];
    return 0;
}