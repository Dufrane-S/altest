#include<iostream>
#include<vector>

using namespace std;


int n, m;
vector<int>box(10,0);
vector<int>done(10, 0);

void dfs(int depth) {
	if (depth == m) { 
		for (int i = 0; i < m; i++) {
			cout << box[i] <<' ';
		}cout << '\n';
		return; 
	}
	for (int i = 1; i <= n; i++) {
		if (done[i] == 0) {
			done[i] = 1;
			box[depth] = i;
			dfs(depth + 1);
			done[i] = 0;
		}
	}
}

int main()
{
	cin >> n >> m;
	
	dfs(0);
}