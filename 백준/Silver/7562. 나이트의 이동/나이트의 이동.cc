/*

#include <iostream>
#include <map>
#include <string>
#include <math.h>
using namespace std;

int main(){
    string target;
    cin>>target;
    int x;
    cin>>x;
    map<int,int>m;
    for(int i=0;i<x;i++){
        int a;
        cin>>a;
        m[a]++;
    }
    string s="";
    for(int i=0;i<target.size();i++){
        int small=11;
        int snum;
        for(int j=0;j<10;j++){
            if(m[j]==0&&small>abs( (target[i] - '0') - j)){
                small=abs( (target[i] - '0') - j);
                snum=j;
            }
        }
        s+=to_string(snum);
    }
    if(target=="100") { cout << 0; return 0;}
    cout<<target<<' '<<s<<' '<<abs(stoi(target)-stoi(s))+target.size();
} 리모콘*/

#include <iostream>
#include  <queue>
#include <vector>

using namespace std;
int targetx, targety;
int a;
int box[301][301];
int done[301][301];
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={2,1,-1,-2,2,1,-1,-2};

void bfs(int startx, int starty){
    done[starty][startx]=1;
    queue<pair<int,int>>q;
    q.push({startx,starty});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(ny<0||nx<0||ny>=a||nx>=a)continue;
            if(done[ny][nx])continue;
            done[ny][nx]=1;
            box[ny][nx]=box[y][x]+1;
            q.push({nx,ny});
            if(nx==targetx&&ny==targety){
                cout<<box[ny][nx]<<'\n';
                return;
            }
        }

    }
}

using namespace std;
int main() {
    int d;
    cin>>d;
    for(int i=0;i<d;i++) {
        cin >> a;
        for(int j=0;j<a;j++){
            for(int k=0;k<a;k++) {
                box[j][k]=0;
                done[j][k]=0;
            }
        }
        int startx, starty;

        cin >> starty >> startx;
        cin >> targety >> targetx;
        if (startx == targetx && starty == targety) {
            cout << 0<<'\n';
        }else {
            bfs(startx, starty);
        }
    }

}