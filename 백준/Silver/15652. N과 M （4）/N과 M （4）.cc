#include<iostream>
#include<vector>

using namespace std;


int n, m;
vector<int>box;

void dfs(int depth) {
	if (depth == m) { 
		for (int i = 0; i < m; i++) {
			cout << box[i] <<' ';
		}cout << '\n';
		return; 
	}
	for (int i = 1; i <= n; i++) {
		if (depth >= 1 && box[depth - 1] > i)continue;
		box.push_back(i);
		dfs(depth + 1);
		box.pop_back();
	}
}

int main()
{
	cin >> n >> m;
	
	dfs(0);
}