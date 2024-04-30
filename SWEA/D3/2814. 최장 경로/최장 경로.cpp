#include<iostream>
#include <vector>

using namespace std;

int answer;
vector<int> list[11];
bool done[11];
int sum;
int n,m;
void dfs(int i);

int main(int argc, char **argv) {

    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        cin>>n>>m;
        answer=0;
        sum=0;
        for(int i=0;i<=n;i++){
            list[i].clear();
        }
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            list[a].push_back(b);
            list[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            done[i]=true;
            dfs(i);
            done[i]=false;
        }
        answer++;
        cout << '#' << test_case << ' ' << answer << '\n';
    }

    return 0;
}

void dfs(int i) {
    if(n>m){
        if(answer==n)return;
    }else{
        if(answer==m)return;
    }

    if(answer<sum)answer=sum;
    for(int j : list[i]){
        if(done[j])continue;
        done[j]=true;
        sum++;
        dfs(j);
        sum--;
        done[j]=false;
    }
}
