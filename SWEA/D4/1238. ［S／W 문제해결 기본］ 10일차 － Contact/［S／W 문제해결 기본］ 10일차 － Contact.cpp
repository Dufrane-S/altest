#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool done[101];
vector<int> box[101];

int main() {
	
	for (int tc = 1; tc <= 10; tc++) {
		int ldepth = 0;
		int answer;
		
		for (int i = 0; i < 101; i++) {
			done[i] = false;
			box[i].clear();
		}

		int n, s;
		cin >> n >> s;
		for (int i = 0; i < n/2; i++) {
			int a, b;
			cin >> a >> b;
			box[a].push_back(b);
		}
		queue<pair<int, int>>q;
		q.push({s,0}); // start, depth
		done[s] = 1;
		while (!q.empty()) {
			int depth = q.front().second;
			int num = q.front().first;
			q.pop();
			if (depth > ldepth) {
				ldepth = depth;
				answer = num;
			}
			else if (depth == ldepth && answer < num) {
				answer = num;
			}
			for (auto i : box[num]) {
				if (!done[i]) {
					q.push({ i, depth + 1 });
					done[i] = 1;
				}
			}
		}
		

		cout << '#' << tc << ' ' << answer<<'\n';
	}
}