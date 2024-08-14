#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool check[1000];
int answer = 0;
vector<vector<char>>v;
int n, m;
void dfs(pair<int, int>p, int k) {
	if (k > answer)answer = k;
	int y = p.first;
	int x = p.second;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i]+y;
		int nx = dx[i]+x;
		if (nx < 0 || ny < 0 || nx == m || ny == n)continue;
		if (check[v[ny][nx]-'A'] == true)continue;
		check[v[ny][nx] - 'A'] = true;
		dfs({ ny,nx }, k + 1);
		check[v[ny][nx] - 'A'] = false;
	}

}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vector<char>a;
		for (int j = 0; j < m; j++) {
			a.push_back(s[j]);
		}v.push_back(a);
	}
	check[v[0][0] - 'A'] = true;
	dfs({ 0,0 }, 1);
	cout << answer;
}