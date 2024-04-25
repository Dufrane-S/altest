#include<iostream>

using namespace std;


int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        double answer=0;

        double a,b,c;
        cin>>a>>b>>c;
        double temp = b-a;
        double temp2 = c-b;
        answer=abs((temp2-temp)/2);
        cout << fixed;
        cout.precision(1);
        cout << '#' << test_case << ' ' << answer << '\n';
    }


    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}