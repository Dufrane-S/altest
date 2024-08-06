#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int answer;
int box[16][16];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };

void bfs(int y, int x) {
	queue<pair<int, int>>q;

	q.push({ y,x });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny == 16 || nx == 16)continue;
			if (box[ny][nx]==1)continue;
			if (box[ny][nx] == 3) {
				answer = 1;
				return;
			}
			box[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
}


int main() {
	int tc;
	tc = 10;
	for (int tcc = 1; tcc <= tc; tcc++) {
		answer = 0;
		int x, y;
		int n;
		cin >> n;

		for (int i = 0; i < 16; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < 16; j++) {
				box[i][j] = s[j]-'0';
				if (s[j] == '2') {
					x = j;
					y = i;
				}
			}
			
			
		}

		bfs(y, x);

		

		cout << '#' << tcc << ' ' << answer<<'\n';
	}
}