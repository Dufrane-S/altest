#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int>v;
	vector<int>vresult;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		int num = v[i-1];
		vresult.push_back(i);
		for (int j = 0; j < num; j++) {
			int temp = vresult[vresult.size() - j-2];
			vresult[vresult.size() - 2-j] = vresult[vresult.size() - 1-j];
			vresult[vresult.size() - 1 - j] = temp;
		}

	}
	for (auto i : vresult) {
		cout << i << ' ';
	}
}