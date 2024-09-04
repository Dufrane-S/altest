#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int ct;
	int ct_num;
	cin >> ct_num;
	for (ct = 1; ct <= ct_num; ct++) {
		int n;
		cin >> n;
		vector<pair<int, int>>v;

		for (int i = 0; i < n + 2; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}

		vector<int>checker;
		for (int i = 2; i < n + 2; i++) {
			checker.push_back(i);
		}
		sort(checker.begin(), checker.end());
		int answer = INT_MAX;
		do {
			int sum = 0;
			sum += abs(v[0].first - v[checker[0]].first) + abs(v[0].second - v[checker[0]].second);
			sum += abs(v[1].first - v[checker[checker.size() - 1]].first) + abs(v[1].second - v[checker[checker.size() - 1]].second);
			for (int i = 0; i < n - 1; i++) {
				sum += abs(v[checker[i]].first - v[checker[i + 1]].first) + abs(v[checker[i]].second - v[checker[i + 1]].second);
			}
			if (answer > sum)answer = sum;

			/*for (auto i : tmp) {
				cout << i.first << ' ' << i.second << ' ';
			}cout << '\n';
			cout << sum << '\n';*/
			/*for (auto i : checker) {
				cout << i << " ";
			}cout << '\n';*/
		} while (next_permutation(checker.begin(), checker.end()));

		cout << '#' << ct << ' ' << answer << '\n';


	}
}