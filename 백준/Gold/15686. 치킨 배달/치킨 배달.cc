#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int answer = INT_MAX;
int n, m;
vector<pair<int, int>>house;
vector<pair<int, int>>chouse;
vector<int>checker;

int main() {
	cin >> n >> m;

	int a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			if (a == 1) {
				house.push_back({ i,j });
			}
			else if (a == 2) {
				chouse.push_back({ i,j });
				checker.push_back(0);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		checker[i] = 1;
	}
	sort(checker.begin(), checker.end());
	do {
		int sum = 0;
		for (auto i : house) {
			int small = INT_MAX;
			for (int j = 0; j < checker.size(); j++) {
				if (checker[j] == 1) {
					int tmp= abs(chouse[j].first - i.first) + abs(chouse[j].second - i.second);
					if (tmp < small)small = tmp;
				}
			}
			sum += small;
		}
		if (sum < answer)answer = sum;
	} while (next_permutation(checker.begin(), checker.end()));
	

	cout << answer;
}