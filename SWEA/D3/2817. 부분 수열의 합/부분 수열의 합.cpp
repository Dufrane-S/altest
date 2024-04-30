#include<iostream>
using namespace std;

int box[21];
int answer = 0;
int sum=0;
int n,k;
void dfs(int s);

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {

        cin>>n>>k;

        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            box[i]=a;
        }

        dfs(0);

        cout << '#' << test_case << ' ' << answer << '\n';
        answer=0;
    }

    return 0;
}

void dfs(int s) {
    if(sum==k) { answer++; return; }
    if(sum>k)return;
    for(int i=s;i<n;i++){

        sum+=box[i];
        dfs(i+1);
        sum-=box[i];
    }
}