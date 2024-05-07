#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test_case;
    int T;
    cin >> T;


    for (test_case = 1; test_case <= T; ++test_case) {
        long long answer1, answer2, answer3;
        long long n;
        cin >> n;
        long long n2 = n * 2 - 1;
        long long n3 = n * 2;
        answer1 = (n * (n + 1)) / 2;
        if(n>=2) {
            if (n % 2 == 0) {
                answer2 = (n2 + 1) * (n2 + 1) / 4;
                answer3 = (n3 + 2) * (n / 2);
            } else {
                answer2 = (n2 + 1) * (n / 2) + n2 / 2 + 1;
                answer3 = (n3 + 2) * (n / 2) + (n3 + 2) / 2;
            }
        }else{
            answer1=1;
            answer2=1;
            answer3=2;
        }

        cout << '#' << test_case << ' ' << answer1 << ' ' << answer2 << ' ' << answer3 << '\n';
    }

    return 0;
}