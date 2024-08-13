#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int main() {
    int asdf;
    cin >> asdf;
    for (int tc = 1; tc <= asdf; tc++) {
        int n;
        cin >> n;
        vector<int> v;

        for (int i = 0; i < 4; i++) {
            int a;
            cin >> a;
            v.push_back(a);
        }

        vector<int> v3;
        for (int i = 0; i < 4; i++) {
            if (i == 0) {
                for (int j = 0; j < v[i]; j++) {
                    v3.push_back(1);
                }
            } else if (i == 1) {
                for (int j = 0; j < v[i]; j++) {
                    v3.push_back(2);
                }
            } else if (i == 2) {
                for (int j = 0; j < v[i]; j++) {
                    v3.push_back(3);
                }
            } else if (i == 3) {
                for (int j = 0; j < v[i]; j++) {
                    v3.push_back(4);
                }
            }
        }

        vector<int> v2;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v2.push_back(a);
        }
        sort(v3.begin(), v3.end());
        int large = INT_MIN;
        int small = INT_MAX;


        do {
            int result = v2
                    [0];
            bool flag = false;
            for (int i = 0; i < n - 1; i++) {

                int b = v2[i + 1];
                if (v3[i] == 1) {
                    result += b;
                } else if (v3[i] == 2) {
                    result -= b;
                } else if (v3[i] == 3) {
                    result *= b;
                } else if (v3[i] == 4) {
                    if (b == 0) {
                        flag = true;
                        continue;
                    }
                    result /= b;
                }
            }
            if (flag)continue;
            if (large < result)large = result;
            if (small > result)small = result;
        } while (next_permutation(v3.begin(), v3.end()));
        cout << '#' << tc << ' ' << large - small << '\n';

    }
}

