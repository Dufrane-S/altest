#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


int n, m;
vector<int>nums;
vector<int>box;
vector<int>done;
void dfs(int depth) {
	if (depth == m) { 
		for (int i = 0; i < m; i++) {
			cout << box[i] <<' ';
		}cout << '\n';
		return; 
	}
	for (int i = 0; i < n; i++) {
		if (done[i] == 0) {
			done[i] = 1;
			box.push_back(nums[i]);
			dfs(depth + 1);
			box.pop_back();
			done[i] = 0;
		}
	}
}

int main()
{
	cin >> n >> m;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		nums.push_back(a);
		done.push_back(0);
	}
	sort(nums.begin(), nums.end());
	dfs(0);
}