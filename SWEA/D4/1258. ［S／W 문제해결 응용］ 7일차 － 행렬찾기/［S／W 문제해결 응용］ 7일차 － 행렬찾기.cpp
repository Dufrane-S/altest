#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int tcn;
	cin >> tcn;
	for (int tc = 1; tc <= tcn; tc++) {
		int n;
		cin >> n;
		vector<vector<int>>box = vector<vector<int>>(n, vector<int>(n, 0));
		vector<vector<int>>done = vector<vector<int>>(n, vector<int>(n, 0));
		int a;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a;
				box[i][j] = a;
			}
		}
		vector<pair<int, pair<int, int>>>v;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (box[i][j] != 0 && done[i][j] == 0) {
					int x = 1;
					int y = 1;
					done[i][j] = 1;
					for (int ni = i + 1; ni < n; ni++) {
						if (box[ni][j] != 0 && done[ni][j] == 0) {
							done[ni][j] = 1;
							y++;
						}
						else {
							break;
						}
					}
					for (int nj = j + 1; nj < n; nj++) {
						if (box[i][nj] != 0 && done[i][nj] == 0) {
							done[i][nj] = 1;
							x++;
						}
						else {
							break;
						}
					}
					v.push_back({ x*y,{y,x} });
					for (int k = i; k < i + y; k++) {
						for (int w = j; w < j + x; w++) {
							done[k][w] = 1;
						}
					}
				}
			}
		}
		sort(v.begin(), v.end());
		cout << '#' << tc << " "<<v.size()<<' ';
		for (auto i : v) {
			cout << i.second.first << ' ' << i.second.second << ' ';
		}cout << '\n';
		
	}
}