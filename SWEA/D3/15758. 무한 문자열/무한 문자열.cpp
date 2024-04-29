#include<iostream>
#include<cmath>
using namespace std;



int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        string answer = "yes";
        string  s,t;
        cin>>s>>t;
        string temps="";
        string tempt="";
        for(int i=0;i<t.size();i++){
            temps+=s;
        }
        for(int i=0;i<s.size();i++){
            tempt+=t;
        }
        if(tempt!=temps)answer="no";
        cout << '#' << test_case << ' ' << answer << '\n';
    }

    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}