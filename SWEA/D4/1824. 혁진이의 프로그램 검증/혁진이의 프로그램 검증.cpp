#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char box[21][21];
int done[21][21][16][4];// 0 왼쪽 < ; 1 오른쪽 > ; 2 위쪽 ^ ; 3 아래쪽 v
int main() {

	int ctn;
	cin >> ctn;
	for (int ct = 1; ct <= ctn; ct++) {


		int n, m;
	
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < 16; k++) {
					for (int l = 0; l < 4; l++) {
						done[i][j][k][l] = 0;
					}
				}
			}
		}

		char a;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a;
				box[i][j] = a;
			}
		}
		bool check = false;
		queue<pair<pair<int, int>, pair<int, int>>>q;
		q.push({ {0,0},{0,1} });
		done[0][0][0][1] = 1;
		while (!q.empty()) {
			int nowy = q.front().first.first;
			int nowx = q.front().first.second;
			int data = q.front().second.first;
			int dir = q.front().second.second;
			q.pop();
			if (box[nowy][nowx] == '@') {
				check = true;
				break;
			}
			if (box[nowy][nowx] == '<') {
				dir = 0;
			}
			else if (box[nowy][nowx] == '^') {
				dir = 2;
			}
			else if (box[nowy][nowx] == '>') {
				dir = 1;
			}
			else if (box[nowy][nowx] == 'v') {
				dir = 3;
			}
			else if (box[nowy][nowx] == '_') {
				if (data == 0) {
					dir = 1;
				}
				else {
					dir = 0;
				}
			}
			else if (box[nowy][nowx] == '|') {
				if (data == 0) {
					dir = 3;
				}
				else {
					dir = 2;
				}
			}
			else if (box[nowy][nowx] == '?') {
				dir = 4;
			}
			else if (box[nowy][nowx] == '.') {

			}
			else if (box[nowy][nowx] <='9' && box[nowy][nowx]>='0') {
				data = box[nowy][nowx] - '0';
			}
			else if (box[nowy][nowx] == '+') {
				data += 1;
				if (data == 16)data = 0;
			}
			else if (box[nowy][nowx] == '-') {
				data -= 1;
				if (data == -1)data = 15;
			}

			if (dir == 4) {
				int ny = nowy - 1;
				if (ny < 0)ny = n - 1;
				if (done[ny][nowx][data][2] == 0) {
					q.push({ { ny,nowx }, { data,2 } });
					done[ny][nowx][data][2] = 1;
				}
				// 0 왼쪽 < ; 1 오른쪽 > ; 2 위쪽 ^ ; 3 아래쪽 v
				ny = nowy + 1;
				if (ny == n)ny = 0;
				if (done[ny][nowx][data][3] == 0) {
					q.push({ { ny,nowx }, { data,3 } });
					done[ny][nowx][data][3] = 1;
				}

				int nx = nowx + 1;
				if (nx == m)nx = 0;
				if (done[nowy][nx][data][1] == 0) {
					q.push({ {nowy,nx},{data,1} });
					done[nowy][nx][data][1] = 1;
				}

				nx = nowx - 1;
				if (nx < 0)nx = m - 1;
				if (done[nowy][nx][data][0]==0) {
					q.push({ {nowy,nx},{data,0} });
					done[nowy][nx][data][0] = 1;
				}
			}
			else if (dir == 2) {
				int ny = nowy - 1;
				if (ny < 0)ny = n - 1;
				if (done[ny][nowx][data][dir]==0) {
					q.push({ { ny,nowx }, { data,dir } });
					done[ny][nowx][data][dir] = 1;
				}
			}
			else if (dir == 3) {
				int ny = nowy + 1;
				if (ny == n)ny = 0;
				if (done[ny][nowx][data][dir]==0) {
					q.push({ { ny,nowx }, { data,dir } });
					done[ny][nowx][data][dir] = 1;
				}
			}
			else if (dir == 1) {
				int nx = nowx + 1;
				if (nx == m)nx = 0;
				if (done[nowy][nx][data][dir]==0) {
					q.push({ {nowy,nx},{data,dir} });
					done[nowy][nx][data][dir] = 1;
				}
			}
			else if (dir == 0) {
				int nx = nowx - 1;
				if (nx < 0)nx = m-1;
				if (done[nowy][nx][data][dir]==0) {
					q.push({ {nowy,nx},{data,dir} });
					done[nowy][nx][data][dir] = 1;
				}
			}

		}
		cout << '#' << ct << ' ';
		if (check) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

	}

}