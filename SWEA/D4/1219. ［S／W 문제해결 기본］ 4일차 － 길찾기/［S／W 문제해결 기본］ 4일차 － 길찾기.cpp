#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> v [100];
bool done[100];
int answer;

void bfs(int a) {
	queue<int>q;
	q.push(a);
	done[a] = 1;
	while (!q.empty()) {
		int k = q.front();
		done[k] = 1;
		q.pop();

		for (auto i : v[k]) {
			if (i == 99) {
				answer = 1;
				return;
			}
			if (!done[i]) {
				q.push(i);
				done[i] = 1;
			}
		}

	}
}



int main() {

	int tcc = 10;
	//cin>>tcc;

	for (int tc = 1; tc <= tcc; tc++) {
		int n, m;
		answer = 0;
		cin >> n >> m;

		for (int i = 0; i < 100; i++) { 
			done[i] = 0; 
			v[i].clear();
		}

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
		}

		bfs(0);

		cout << '#' << tc << ' ' << answer << '\n';
	}

	
}
	