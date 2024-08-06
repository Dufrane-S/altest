#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main() {
	int tc;
	tc = 10;
	for (int tcc = 1; tcc <= tc; tcc++) {
		int n;
		cin >> n;
		queue<int>q;
		for (int i = 0; i < 8; i++) {
			int a;
			cin >> a;
			q.push(a);
		}

		int i = 1;
		while (q.front() - i > 0) {
			q.push(q.front() - i);
			q.pop();
			i++;
			if (i == 6) {
				i = 1;
			}
		}
		q.push(0);
		q.pop();
		//cout << '#' << tcc << ' ' << answer<<'\n';
		cout << '#' << tcc << ' ';
		while (!q.empty()) {
			cout << q.front(); q.pop();
			cout << ' ';
		}
		cout << '\n';
	}
}
