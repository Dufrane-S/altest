#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int tcn;
	cin >> tcn;
	for (int tc = 1; tc <= tcn; tc++) {
		cout << '#' << tc << '\n';
		string asdf;
		cin >> asdf;
		int n;
		cin >> n;
		string a;
		vector<int>nums;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (a == "ZRO") {
				nums.push_back(0);
			}
			else if (a == "ONE") {
				nums.push_back(1);
			}
			else if (a == "TWO") {
				nums.push_back(2);
			}
			else if (a == "THR") {
				nums.push_back(3);
			}
			else if (a == "FOR") {
				nums.push_back(4);
			}
			else if (a == "FIV") {
				nums.push_back(5);
			}
			else if (a == "SIX") {
				nums.push_back(6);
			}
			else if (a == "SVN") {
				nums.push_back(7);
			}
			else if (a == "EGT") {
				nums.push_back(8);
			}
			else if (a == "NIN") {
				nums.push_back(9);
			}
		}
		sort(nums.begin(), nums.end());
		for (auto i : nums) {
			if (i == 0) {
				cout << "ZRO ";
			}
			else if (i == 1)
			{
				cout << "ONE ";
			}
			else if (i == 2)
			{
				cout << "TWO ";
			}
			else if (i == 3)
			{
				cout << "THR ";
			}
			else if (i == 4)
			{
				cout << "FOR ";
			}
			else if (i == 5)
			{
				cout << "FIV ";
			}
			else if (i == 6)
			{
				cout << "SIX ";
			}
			else if (i == 7)
			{
				cout << "SVN ";
			}
			else if (i == 8)
			{
				cout << "EGT ";
			}
			else if (i == 9)
			{
				cout << "NIN ";
			}

		}cout << '\n';
	}
}