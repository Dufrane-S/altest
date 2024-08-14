#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[8] = { 0,0, -1,-1,-1,1,1,1};
int dy[8] = { 1,-1, 1,0,-1,1,0,-1};


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int tcnum;
	cin >> tcnum;
	for (int tc = 1; tc <= tcnum; tc++) {
		vector<vector<char>>box;
		int n;
		cin >> n;
		int answer = 0;
		vector<vector<bool>>done(n, vector<bool>(n, false));
		vector<vector<bool>>check(n, vector<bool>(n, false));
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			vector<char>a;
			for (int j = 0; j < n; j++) {
				a.push_back(s[j]);
				if (s[j] == '*')done[i][j] = true;
			}
			box.push_back(a);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				bool flag = false;
				for (int k = 0; k < 8; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (ny < 0 || nx < 0 || nx == n || ny == n)continue;
					if (box[ny][nx] == '*')flag = true;
				}
				check[i][j] = flag;
			}
		}
		
		

		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (box[i][j] == '.'&&done[i][j]==false&&check[i][j]==false) {
					answer++;
					queue<pair<int, int>>q;
					q.push({ i,j });
					done[i][j]=true;
					while (!q.empty()) {
						int y = q.front().first;
						int x = q.front().second;

						q.pop();
						bool flag = true;
						if (check[y][x]==false) {
							for (int k = 0; k < 8; k++) {
								int ny = y + dy[k];
								int nx = x + dx[k];
								if (ny < 0 || nx < 0 || nx == n || ny == n)continue;
								if (box[ny][nx] == '*')continue;
								if (done[ny][nx] == true)continue;
								q.push({ ny,nx });
								done[ny][nx] = true;
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (done[i][j] == false)answer++;
			}
		}
		cout << '#' << tc << ' ' << answer << '\n';
	}

}