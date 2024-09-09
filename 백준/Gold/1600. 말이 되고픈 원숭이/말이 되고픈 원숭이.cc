#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int hopx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int hopy[8] = { 2,1,-1,-2,-2,-1,1,2 };

int box[201][201];
int done[201][201][31];
int main() {
	int k;
	cin >> k;
	int n, m;
	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << 0;
		return 0;
	}
	int a;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			box[i][j] = a;
		}
	}
	queue<pair<pair<int, int>, int>>q;
	q.push({ {0, 0,}, 0 });
	while (!q.empty()) {
		int nowy = q.front().first.first;
		int nowx = q.front().first.second;
		int hop = q.front().second;
		q.pop();
		if (hop < k) {
			for (int k = 0; k < 4; k++) {
				int ny = nowy + dy[k];
				int nx = nowx + dx[k];
				if (ny < 0 || nx < 0 || nx == n || ny == m || done[ny][nx][hop] != 0 || box[ny][nx]==1)continue;

				if (done[ny][nx][hop] == 0 || done[ny][nx][hop] > done[nowy][nowx][hop] + 1) {
					q.push({ {ny,nx},hop });
					done[ny][nx][hop] = done[nowy][nowx][hop] + 1;
				}

			}

			for (int k = 0; k < 8; k++) {
				int ny = nowy + hopy[k];
				int nx = nowx + hopx[k];
				if (ny < 0 || nx < 0 || nx >= n || ny >= m || done[ny][nx][hop + 1] != 0 || box[ny][nx] == 1)continue;
				if (done[ny][nx][hop + 1] == 0 || done[nowy][nowx][hop] + 1 < done[ny][nx][hop + 1]) {
					q.push({ {ny,nx},hop + 1 });
					done[ny][nx][hop + 1] = done[nowy][nowx][hop] + 1;
				}

			}

		}
		else {
			for (int k = 0; k < 4; k++) {
				int ny = nowy + dy[k];
				int nx = nowx + dx[k];
				if (ny < 0 || nx < 0 || nx == n || ny == m || done[ny][nx][hop] != 0 || box[ny][nx] == 1)continue;
				if (done[ny][nx][hop] == 0 || done[ny][nx][hop] > done[nowy][nowx][hop] + 1) {
					q.push({ {ny,nx},hop });
					done[ny][nx][hop] = done[nowy][nowx][hop] + 1;
				}
			}
		}
	}
	int small = INT_MAX;
	for (int i = 0; i <= k; i++) {
		//cout << done[m - 1][n - 1][i] << ' ';
		if (done[m - 1][n - 1][i] == 0)continue;
		if (small > done[m - 1][n - 1][i])small = done[m - 1][n - 1][i];
	}
	/*cout << '\n';
	for (int a = 0; a < k; a++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << done[i][j][a] << " ";
			}cout << '\n';
		}cout << '\n';
	}*/


	if (small == INT_MAX) {
		cout << -1;
	}
	else {
		cout << small;
	}
	
}