#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int y, x;
	cin >> y >> x;
	int k;
	cin >> k;
	int box[21][21];
	int a;
	int dice[6] = { 0,0,0,0,0,0 };
	vector<int>input;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;
			box[i][j] = a;
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> a;
		input.push_back(a);
	}
	for (auto i : input) {//0 아래, 2 오른쪽, 3 왼쪽, 4 앞, 1 뒤 ,5 위
		if (i == 1) {//동
			if (x + 1 < m) {
				x++;
				int tmp = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[5];
				dice[5] = dice[3];
				dice[3] = tmp;
			}
			else {
				continue;
			}
		}
		else if (i == 2) {//서
			if (x - 1 >= 0) {
				x--;
				int tmp = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[2];
				dice[2] = tmp;
			}
			else {
				continue;
			}
		}
		else if (i == 4) {//남
			if (y + 1 < n) {
				y++;
				int tmp = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[5];
				dice[5] = dice[1];
				dice[1] = tmp;
			}
			else {
				continue;
			}
		}
		else if (i == 3) {//북
			if (y - 1 >= 0) {
				y--;
				int tmp = dice[0];
				dice[0] = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[4];
				dice[4] = tmp;
			}
			else {
				continue;
			}
		}

		if (box[y][x] == 0) {
			box[y][x] = dice[0];
		}
		else if (box[y][x] != 0) {
			dice[0] = box[y][x];
			box[y][x] = 0;
		}
		cout << dice[5] << '\n';
	}

}