#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int answer = 0;
vector<pair<int, int>> v;
int n, m;
vector<vector<int>> box = vector<vector<int>>(8, vector<int>(8, 0));
vector<vector<int>> tmp = vector<vector<int>>(8, vector<int>(8, 0));;
vector<vector<int>> tmp2 = vector<vector<int>>(8, vector<int>(8, 0));;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};


void wall(int count) {
    if (count == 3) {

        for (int d = 0; d < n; d++) {
            for (int k = 0; k < m; k++) {
                tmp2[d][k] = tmp[d][k];
            }
        }

        queue<pair<int, int>> q;
        for (auto i: v) {
            q.push(i);
        }
        while (!q.empty()) {
            int nowx = q.front().second;
            int nowy = q.front().first;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int ny = nowy + dy[k];
                int nx = nowx + dx[k];
                if (ny < 0 || nx < 0 || ny == n || nx == m || tmp2[ny][nx] != 0)continue;
                tmp2[ny][nx] = 2;
                q.emplace(ny, nx);
            }
        }

        int safe=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tmp2[i][j] == 0)safe++;
            }
        }
        answer=max(answer,safe);
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tmp[i][j] == 0) {
                    tmp[i][j] = 1;
                    wall(count+1);
                    tmp[i][j] = 0;
                }
            }
        }
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            box[i][j] = a;
            if (a == 2) {
                v.emplace_back(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (box[i][j] == 0) {
                for (int d = 0; d < n; d++) {
                    for (int k = 0; k < m; k++) {
                        tmp[d][k] = box[d][k];
                    }
                }
                tmp[i][j] = 1;
                wall(1);
                tmp[i][j] = 0;
            }

        }
    }
    cout<<answer;
}