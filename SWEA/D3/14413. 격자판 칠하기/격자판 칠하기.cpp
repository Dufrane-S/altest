#include<iostream>
#include<set>
using namespace std;


char box[50][50];
int n,m;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};


bool check(int a,int b){
    set<char> s;
    for(int i=0;i<4;i++){
        int na=a+dx[i];
        int nb=b+dy[i];
        if(na>=n||na<0||nb<0||nb>=m)continue;
        if(box[na][nb]=='?'){
            continue;
        }else{
            s.insert(box[na][nb]);
        }
    }
    if(s.size()==1) {
        if(s.find('#')!=s.end()){
            if(box[a][b]=='#')return false;
            box[a][b]='.';
        }else{
            if(box[a][b]=='.')return false;
            box[a][b]='#';
        }
        return true;
    }else if(s.empty())return true;
    return false;
}

int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {

        string answer = "possible";

        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char temp;
                cin>>temp;
                box[i][j]=temp;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!check(i,j)){
                    i=n;
                    j=m;
                    answer="impossible";
                }
            }
        }
        cout << '#' << test_case << ' ' << answer << '\n';
    }

    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}