#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        string answer = "ON";
        int n;
        long long m;
        cin >> n >> m;
        int i = 0;
        while (i < n ) {
            if(m%2==0){
                answer="OFF";
                break;
            }
            if(m==1) {
                if(i<n-1)answer="OFF";
                break;
            }

            m = m >> 1;

            i++;
        }


        cout << '#' << test_case << ' ' << answer << '\n';

    }


    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}