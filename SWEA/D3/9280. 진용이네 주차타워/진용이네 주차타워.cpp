#include<iostream>
#include <vector>
#include <queue>

using namespace std;


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        int answer = 0;

        int n, m;
        cin >> n >> m;
        vector<int> fee;
        vector<int> weight;
        vector<int> input;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            fee.push_back(a);
        }
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            weight.push_back(a);
        }
        for (int i = 0; i < m * 2; i++) {
            int a;
            cin >> a;
            input.push_back(a);
        }
        queue<int> q;
        int parking[n];
        for (int i = 0; i < n; i++)parking[i] = 0;
        for (auto i: input) {
            if (i > 0) {
                q.push(i);
                int temp = q.front();
                for (int j = 0; j < n; j++) {
                    if (!parking[j]) {
                        parking[j] = temp;
                        answer += fee[j] * weight[temp - 1];
                        q.pop();
                        break;
                    }
                }
            } else if (i < 0) {
                for (int j = 0; j < n; j++) {
                    if (parking[j] == abs(i)) {
                        parking[j] = 0;
                    }

                }
                if(!q.empty()) {
                    int temp = q.front();
                    for (int j = 0; j < n; j++) {
                        if (!parking[j]) {
                            parking[j] = temp;
                            answer += fee[j] * weight[temp - 1];
                            q.pop();
                            break;
                        }
                    }
                }
            }
        }


        cout << '#' << test_case << ' ' << answer << '\n';


    }


    return 0;
}