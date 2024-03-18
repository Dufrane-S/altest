#include <bits/stdc++.h>
using namespace std;


int boxx,boxy,z;
int box[101][101];
vector<int>sums;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void bfs(int a, int b){

    queue<pair<int,int>> q;
    int sum=1;
    q.push({a, b});
    while(!q.empty()) {
        int x=q.front().second;
        int y=q.front().first;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||ny<0||nx>=boxx||ny>=boxy)continue;
            if(box[ny][nx]==1)continue;
            q.push({ny,nx});
            box[ny][nx]=1;
            sum++;
        }
    }
    sums.push_back(sum);
}

int main(void){
    cin >> boxy >> boxx >> z;
    for(int i=0;i<z;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        for(int j=b;j<d;j++){
            for(int k=a;k<c;k++){
                box[j][k]=1;
            }
        }
    }
    for(int i=0; i < boxy; i++){
        for(int j=0; j < boxx; j++){
            if(box[i][j]==1)continue;
            box[i][j]=1;
            bfs(i,j);
        }
    }
    sort(sums.begin(),sums.end());
    cout<<sums.size()<<'\n';
    for(auto i:sums){
        cout<<i<<' ';
    }
}