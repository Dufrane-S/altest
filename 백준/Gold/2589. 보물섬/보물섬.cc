#include <iostream>
#include <queue>


using namespace std;


int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    int n, m;
    cin >> n >> m;
    char box[n][m];
    bool done[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char a;
            cin >> a;
            box[i][j] = a;
            if (a == 'W') {
                done[i][j] = true;
            } else {
                done[i][j] = false;
            }
        }
    }
    int answer=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!done[i][j]) {
                int newdone[n][m];
                int score[n][m];

                for (int a = 0; a < n; a++) {
                    for (int b = 0; b < m; b++) {
                        newdone[a][b] = done[a][b];
                        score[a][b] = 0;
                    }
                }
                queue<pair<int, int>> q;
                q.push({i, j});
                newdone[i][j] = 1;
                int x,y;
                while (!q.empty()) {
                    y = q.front().first;
                    x = q.front().second;
                    
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];

                        if (ny < 0 || nx < 0 || ny == n || nx == m || newdone[ny][nx])continue;
                        q.push({ny, nx});
                        newdone[ny][nx]=1;

                        score[ny][nx]=(score[y][x]+1);
                    }
                }
                answer=max(answer,score[y][x]);
            }
        }
    }
    cout<<answer;
}


