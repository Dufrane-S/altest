#include<iostream>

using namespace std;

int main(int argc, char **argv) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
    int test_case;
    int T;
    cin >> T;


    for (test_case = 1; test_case <= T; ++test_case) {

        int answer = 0;

        int n, size;
        cin >> n >> size;
        int weights[n];
        int values[n];
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            weights[i] = b;
            values[i] = a;
        }
        int list[n + 1][size + 1];
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < size + 1; j++) {
                list[i][j] = 0;
            }
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < size + 1; j++) {
                if (j - weights[i - 1] < 0) {
                    list[i][j] = list[i - 1][j];
                } else {
                    list[i][j] = max(list[i - 1][j], list[i - 1][j - weights[i - 1]] + values[i - 1]);
                }
            }
        }
        answer = list[n][size];
        cout << '#' << test_case << ' ' << answer << '\n';

    }

    return 0;
}