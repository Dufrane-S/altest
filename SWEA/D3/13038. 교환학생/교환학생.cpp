#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test_case;
    int T;
    cin >> T;


    for (test_case = 1; test_case <= T; ++test_case) {
        int answer = INT_MAX;
        int target;
        cin >> target;
        vector<int> v;
        int day = 0;
        for (int i = 0; i < 7; i++) {
            int a;
            cin >> a;
            if (a)day++;
            v.push_back(a);
        }

        if (target >= day) {
            if (target % day == 0) {
                for (int i = 0; i < 7; i++) {
                    int temp;
                    temp = target / day;
                    temp *= 7;
                    temp -= 7;
                    int count = 0;
                    int idx = i;
                    while (true) {
                        if (v[idx % 7])count++;
                        temp++;
                        idx++;;
                        if (count == day)break;
                    }
                    if (answer > temp)answer = temp;
                }
            } else {
                for (int i = 0; i < 7; i++) {
                    int temp;
                    temp = target / day;
                    temp *= 7;
                    int count = 0;
                    int idx = i;
                    while (count < target % day) {
                        if (v[idx % 7])count++;
                        temp++;
                        idx++;
                    }
                    if (answer > temp)answer = temp;
                }
            }
        } else {
            for (int i = 0; i < 7; i++) {
                int temp;
                temp = 0;
                int count = 0;
                int idx = i;
                while (count < target) {
                    if (v[idx % 7])count++;
                    temp++;
                    idx++;
                }
                if (answer > temp)answer = temp;
            }
        }
        if (day == 1) {
            answer = 7 * target / day - 6;
        }
        if (target == 1 & day == 1)answer = 1;
        cout << '#' << test_case << ' ' << answer << '\n';

    }

    return 0;
}