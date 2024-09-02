#include <iostream>
#include <vector>

using namespace std;

int main() {

	int h, w, n, m;
	cin >> h >> w >> n >> m;
	int count = 0;
	for (int i = 0; i < h; i += n + 1) {
		count++;
	}
	int count2 = 0;
	for (int i = 0; i < w; i += m + 1) {
		count2++;
	}
	cout << count * count2;
}