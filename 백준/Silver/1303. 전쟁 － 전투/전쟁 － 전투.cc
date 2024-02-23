#include <bits/stdc++.h>

int done [101][101];
char m[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

using namespace std;
int main(void){
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=M;i++){
        string s;
        cin>>s;
        for(int j=1;j<=N;j++){
            m[i][j]=s[j-1];
        }
    }
    int w=0;
    int b=0;
    queue<pair<int,int>>q;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            if(done[i][j]==1)continue;
            int temp=1;
            char col=m[i][j];
            q.push({j,i});


            done[i][j]=1;
            while(!q.empty()){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(done[ny][nx]==0&&m[ny][nx]==col) {
                        q.push({nx, ny});
                        done[ny][nx]=1;
                        temp++;
                    }
                }
            }
            if(col=='W'){
                w+=temp*temp;
            }else{
                b+=temp*temp;
            }
        }
    }
    cout<<w<<' '<<b;
}