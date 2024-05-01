#include<iostream>
#include<vector>
using namespace std;

vector<int>box;

void dfs(int start, int end);

int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;


    for (test_case = 1; test_case <= T; ++test_case) {
        int answer=0;

        int n,d;
        cin>>n>>d;

        int count=0;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            count++;
            if(a==1)count=0;
            if(count==d) { answer++; count=0; }

        }


        cout << '#' << test_case << ' ' << answer << '\n';
    }

    return 0;
}