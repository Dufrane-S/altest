#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
	int tc;
	tc = 10;
	for (int tcc = 1; tcc <= tc; tcc++) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<char>v;
		for (auto i : s) {
			if (!v.empty()) {
				if (v[v.size() - 1] == i) { 
					v.pop_back();
				}
				else {
					v.push_back(i);
				}
			}
			else {
				v.push_back(i);
			}
		}
		string answer="";
		for (auto i : v) {
			answer += i;
		}
		cout << '#' << tcc << ' ' << answer<<'\n';
	}
}
