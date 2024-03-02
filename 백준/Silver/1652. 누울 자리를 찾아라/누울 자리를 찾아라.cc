#include <bits/stdc++.h>

using namespace std;


int main(void){
    int x;
    int ver=0;
    int hor=0;
    cin>>x;
    char b[x][x];
    char temp[x][x];
    for(int i=0;i<x;i++){
        string s;
        cin>>s;
        for(int j=0;j<x;j++){
            b[i][j]=s[j];
            temp[i][j]=s[j];
        }
    }
    for(int i=0;i<x;i++) {
        for (int j = 0; j < x; j++) {
            if (b[i][j] == '.') {
                queue<pair<int, int>> q;
                int hortemp = 0;
                q.push({i, j});
                b[i][j] = 'X';
                while (!q.empty()) {
                    int ni = q.front().first + 1;
                    int nj = q.front().second;
                    q.pop();
                    hortemp++;
                    if (ni<x&&b[ni][nj] == '.') {
                        q.push({ni, nj});
                        b[ni][nj] = 'X';
                    }
                }
                if (hortemp >= 2)hor++;
            }
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            if(temp[i][j]=='.'){
                queue<pair<int,int>>q;
                int vertemp=0;
                q.push({i,j});
                temp[i][j]='X';
                while(!q.empty()){
                    int ni = q.front().first;
                    int nj = q.front().second+1;
                    q.pop();
                    vertemp++;
                    if(nj<x&&temp[ni][nj]=='.'){
                        q.push({ni,nj});
                        temp[ni][nj]='X';
                    }
                }
                if(vertemp>=2)ver++;
            }
        }
    }
    cout<<ver<<' '<<hor;
}