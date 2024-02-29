#include <bits/stdc++.h>

using namespace std;
int done[101];
vector<int> con[101];
int goal;
int dp=99999;
bool flag=true;
void dfs(int start, int answer){
    if(start==goal){
        if(dp>answer)dp=answer;
        flag=false;
        return;
    }else if(done[start]==1)return;
    done[start]=1;
    answer++;
    for(auto i:con[start])dfs(i,answer);
}

int main(void){
    int answer=0;
    int n;
    cin>>n;
    int x,y;
    cin>>x>>y;
    goal=y;
    int cons;
    cin>>cons;

    for(int i =0;i<cons;i++){
        int a,b;
        cin>>a>>b;
        con[a].push_back(b);
        con[b].push_back(a);
    }
    dfs(x,answer);
    if(flag){
        cout << -1;
    }else { cout << dp; }
}