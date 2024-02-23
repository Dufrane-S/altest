#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> con [101];
int done[101];
int answer=0;
void dfs(int n){
    if(done[n]==1)return;
    answer++;
    done[n]=1;
    for(auto i: con[n]){
        dfs(i);
    }

}

int main(void){
    int a,b;
    cin>>a>>b;
    for(int i=0;i<b;i++){
        int x,y;
        cin>>x>>y;

        con[x].push_back(y);
        con[y].push_back(x);
    }
    dfs(1);
    cout<<answer-1;
}