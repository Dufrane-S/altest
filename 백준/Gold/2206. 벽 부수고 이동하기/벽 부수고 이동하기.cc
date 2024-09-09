#include <iostream>
#include <string>
#include <queue>
using namespace std;
int box[1001][1001];
int done[1001][1001][2];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int main() {
	int n, m;
	cin >> n >> m;
	
	
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			box[i][j] = s[j]-'0';
		}
	}
	queue<pair<pair<int, int>, int>>q;
	q.push({ { 0,0 }, 0 });
	done[0][0][0] = 1;
	while (!q.empty()) {
		int nowy = q.front().first.first;
		int nowx = q.front().first.second;
		int buscount = q.front().second;
		q.pop();
		if (buscount == 1) {
			for (int k = 0; k < 4; k++) {
				int ny = nowy + dy[k];
				int nx = nowx + dx[k];
				if (ny < 0 || nx < 0 || ny == n || nx == m||box[ny][nx]==1 || done[ny][nx][buscount]==1)continue;
			
				if (done[ny][nx][buscount] == 0) {
					done[ny][nx][buscount] = done[nowy][nowx][buscount] + 1;
					q.push({ {ny,nx}, buscount });
				}
			}
		}
		else if (buscount == 0) {
			for (int k = 0; k < 4; k++) {
				int ny = nowy + dy[k];
				int nx = nowx + dx[k];
				if (ny < 0 || nx < 0 || ny == n || nx == m)continue;
				
				if (box[ny][nx] == 1) {
					if (done[ny][nx][1] != 0)continue;
					q.push({ {ny,nx}, buscount + 1 });
					done[ny][nx][buscount+1] = done[nowy][nowx][buscount] + 1;
				}
				else if (box[ny][nx] == 0) {
					if (done[ny][nx][0] != 0)continue;
					q.push({ {ny,nx}, buscount });
					done[ny][nx][buscount] = done[nowy][nowx][buscount] + 1;
				}
			}
		}
	}
	if (done[n - 1][m - 1][0] == 0 && done[n-1][m-1][1]==0) {
		cout << -1;
	}
	else {
		int a = done[n - 1][m - 1][0];
		int b = done[n - 1][m - 1][1];
		if (a == 0) {
			cout << b;
		}
		else if (b == 0) {
			cout << a;
		}
		else {
			cout << min(a, b);
		}
	}
}