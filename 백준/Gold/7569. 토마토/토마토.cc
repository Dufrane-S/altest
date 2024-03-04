#include <bits/stdc++.h>

using namespace std;
int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};
int box[101][101][101];
int done[101][101][101];
int main(void){
    int x,y,z;
    cin>>x>>y>>z;
    queue<vector<int>>q;
    for (int i=0;i<z;i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < x; k++) {
                int a;
                cin >> a;
                if (a == -1) {
                    done[i][j][k] = 1;
                    box[i][j][k] = -1;
                } else if (a == 1) {
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    temp.push_back(k);
                    q.push(temp);
                    done[i][j][k] = 1;
                    box[i][j][k] = 1;
                } else {
                    box[i][j][k] = 1;
                }
            }
        }

    }

    while(!q.empty()){
        int oz = q.front()[0];
        int oy = q.front()[1];
        int ox = q.front()[2];
        q.pop();
        for(int a=0;a<6;a++){
            int nz= oz + dz[a];
            int ny= oy + dy[a];
            int nx= ox + dx[a];
            if(nz<0||nx<0||ny<0||nx==x||ny==y||nz==z)continue;
            if(done[nz][ny][nx]==0){
                done[nz][ny][nx] = 1;
                vector<int>temp;
                temp.push_back(nz);
                temp.push_back(ny);
                temp.push_back(nx);
                q.push(temp);
                box[nz][ny][nx]+=box[oz][oy][ox];
            }
        }
    }
    int large=0;

    for (int i=0;i<z;i++) {
        for(int j=0;j<y;j++){
            for(int k=0;k<x;k++){
                if(box[i][j][k]>large)large=box[i][j][k];
                if(done[i][j][k]==0) { cout<<-1; return 0; }
            }
        }
    }
    cout<<large-1;
}