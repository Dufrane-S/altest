#include <iostream>
#include <vector>
#include<algorithm>
#include<map>

using namespace std;


int main() {
	int n, target;
	int answer = 1;
	cin >> n >> target;
	map<int,int>gold;
	map<int,int>silver;
	map<int,int>bronze;
	for (int i = 0; i < n; i++) {
		int num, g, s, b;
		cin >> num >> g >> s >> b;
		gold[num] = g;
		silver[num] = s;
		bronze[num] = b;
	}
	int gtemp = gold[target];
	vector<int>gold_equal;
	for (auto i : gold) {
		if (i.second > gtemp)answer++;
		if (i.second == gtemp && i.first != target)gold_equal.push_back(i.first);
	}

	vector<int>silver_equal;
	if (!gold_equal.empty()) {
		for (auto i : gold_equal) {
			if (silver[i] > silver[target])answer++;
			if (silver[i] == silver[target])silver_equal.push_back(i);
		}
	}
	if (!silver_equal.empty()) {
		for (auto i : silver_equal) {
			if (bronze[i] > bronze[target])answer++;
		}
	}
	

	cout << answer;
}