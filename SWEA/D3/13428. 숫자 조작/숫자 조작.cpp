#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;


    for (test_case = 1; test_case <= T; ++test_case) {

        string temp;
        cin >> temp;
        int answer1 = stoi(temp);
        int answer2 = stoi(temp);
        for (int i = 0; i < temp.size(); i++) {
            for (int j = i; j < temp.size(); j++) {
                if (j == i)continue;
                string temp2 = temp;
                char temp3 = temp2[i];
                temp2[i] = temp2[j];
                temp2[j] = temp3;
                int temp4 = stoi(temp2);
                if (temp4 > answer1)answer1 = temp4;
                if (temp2[0] != '0' && temp4 < answer2) { answer2 = temp4; }

            }
        }
        cout << '#' << test_case << ' ' << answer2 << ' ' << answer1 << '\n';
    }

    return 0;
}