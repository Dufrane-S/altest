#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        int answer = 0;
        int n;
        cin >> n;
        int answers[n];
        int j = 0;
        while (j < n) {
            string temp;
            cin >> temp;
            if (temp[0] >= 'A' && temp[0] <= 'Z') {
                for (int k = 1; k < temp.length(); k++) {
                    if (temp[k] < 'a' ||temp[k]>'z') {
                        if(k==temp.length()-1&&(temp[temp.length() - 1] == '!' || temp[temp.length() - 1] == '.' || temp[temp.length() - 1] == '?'))continue;
                        answer--;
                        break;
                    }
                }
                answer++;
            }
            if (temp[temp.length() - 1] == '!' || temp[temp.length() - 1] == '.' || temp[temp.length() - 1] == '?') {
                answers[j] = answer;
                j++;
                answer = 0;
            }
        }


          cout << '#' << test_case << ' ';
        for(auto i: answers){
            cout<<i<<' ';
        }
        cout<< '\n';
//        cout << '#' << test_case << ' ' << answer << '\n';

    }


    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}