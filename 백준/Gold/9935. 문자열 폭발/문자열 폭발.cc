#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int main() {
	string target;
	cin >> target;
	string boom, rboom;
	cin >> boom;
	rboom = boom;
	reverse(rboom.begin(), rboom.end());
	stack<char>s;
	for (auto i : target) {
		s.push(i);
		if (boom[boom.size() - 1] == i && s.size()>=boom.size()) {
			string tmp = "";
			for (int j = 0; j < boom.size(); j++) {
				tmp+=s.top();
				s.pop();
			}

			if (tmp != rboom) {
				reverse(tmp.begin(), tmp.end());
				for (auto j : tmp) {
					s.push(j);
				}
			}
		}
	}
	if (s.empty()) {
		cout << "FRULA";
	}
	else {
		string tmp="";
		while (!s.empty()) {
			tmp += s.top();
			s.pop();
		}
		reverse(tmp.begin(), tmp.end());
		cout << tmp;
	}
}