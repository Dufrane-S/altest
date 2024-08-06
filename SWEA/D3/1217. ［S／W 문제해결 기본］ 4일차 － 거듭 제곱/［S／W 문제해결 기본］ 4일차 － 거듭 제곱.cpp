#include <iostream>

using namespace std;

int answer=1;
void calc(int n, int m, int k) {
	if (k == m)return;
	calc(n, m, k + 1);
	answer *= n;
}

int main() {
	int tc;
	tc = 10;
	for (int tcc = 1; tcc <= tc; tcc++) {
		int asdf;
		cin >> asdf;
		int n, m;
		cin >> n >> m;
		answer = 1;
		calc(n, m, 0);

		cout << '#' << tcc << ' ' << answer<<'\n';
	}
}
