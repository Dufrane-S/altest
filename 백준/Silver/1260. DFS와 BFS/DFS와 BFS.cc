#include <bits/stdc++.h>

using namespace std;
int done[1001];
vector<int> con[1001];
void bfs(int z){
    done[z]=1;
    cout<<z<<' ';
    queue<int>q;
    for(auto i:con[z]){
        q.push(i);
        done[i]=1;
    }
    while(!q.empty()){
        int a = q.front();
        q.pop();
        cout<<a<<' ';
        for(auto i:con[a]){
            if(done[i]==0)q.push(i);
            done[i]=1;
        }
    }
    cout<<'\n';
}

void dfs(int z){
    if(done[z]==1)return;
    done[z]=1;
    cout<<z<<' ';
    for(auto i:con[z]){
        dfs(i);
    }

}

int main(void){
    int x,y,z;
    cin>>x>>y>>z;
    for(int i=0;i<y;i++){
        int a,b;
        cin>>a>>b;
        con[a].push_back(b);
        con[b].push_back(a);
    }
    for(int i=0;i<1001;i++){
        sort(con[i].begin(),con[i].end());
    }
    dfs(z);cout<<'\n';
    for(int i=0;i<1001;i++){done[i]=0;}
    bfs(z);
}