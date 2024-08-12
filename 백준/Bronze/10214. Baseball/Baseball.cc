#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int y = 0;
		int k = 0;
		for (int j = 0; j < 9; j++) {
			int a, b;
			cin >> a >> b;
			y += a;
			k += b;
		}
		if (y > k) {
			cout << "Yonsei\n";
		}
		else if (y < k) {
			cout << "Korea\n";
		}
		else if (y == k) {
			cout << "Draw\n";
		}
	}
}