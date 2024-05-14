#include<iostream>
#include<queue>

using namespace std;

int box[200][200];
int result[200][200];
int done[200][200];
int n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(int argc, char **argv) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
    int test_case;
    int T;
    cin >> T;


    for (test_case = 1; test_case <= T; ++test_case) {
        int answer;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string a;
            cin >> a;
            for (int j = 0; j < n; j++) {
                box[i][j] = a[j] - '0';
            }
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        done[0][0] = 1;
        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;

                if (done[ny][nx] == 0) {
                    result[ny][nx] = box[ny][nx] + result[y][x];
                    q.push({ny, nx});
                    done[ny][nx] = 1;
                    continue;
                }
                if (done[ny][nx] == 1 && result[ny][nx] > box[ny][nx] + result[y][x]) {
                    result[ny][nx] = box[ny][nx] + result[y][x];
                    q.push({ny, nx});
                }
            }
        }
        answer = result[n - 1][n - 1];
        cout << '#' << test_case << ' ' << answer << '\n';

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                box[i][j] = 0;
                result[i][j] = 0;
                done[i][j] = 0;
            }
        }
    }

    return 0;
}