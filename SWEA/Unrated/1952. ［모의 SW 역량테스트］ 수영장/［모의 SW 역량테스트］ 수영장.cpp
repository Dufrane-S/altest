#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int answer;
int day, month, months, year;
vector<int>v;

void dfs(int idx, int sum) {
	if (idx >= 12) { 
		answer = min(answer, sum);
		return; 
	}
	dfs(idx + 1, sum + v[idx] * day);//1일권
	dfs(idx + 1, sum+month);//1달권
	dfs(idx + 3, sum + months);//3달권

}


int main() {
	int tcnum;
	cin >> tcnum;
	for (int tc = 1; tc <= tcnum; tc++) {
		v.clear();
		cin >> day >> month >> months >> year;
		for (int i = 0; i < 12; i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}

		answer = year;
		dfs(0, 0);

		cout << '#' << tc << ' ' << answer << '\n';
	}
}