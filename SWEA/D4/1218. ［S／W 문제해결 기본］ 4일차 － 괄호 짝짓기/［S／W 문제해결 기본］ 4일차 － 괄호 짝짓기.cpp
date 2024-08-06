#include <iostream>
#include <stack>
#include <string>
using namespace std;

int box[100][100];

int main(void) {
	int t;
//	cin >> t;
	t = 10;
	for (int t_case = 1; t_case <= t; t_case++) {
		
		int n;
		int answer = 1;
		cin >> n;
		string s;
		cin >> s;

		stack<char>stk;

		for (auto i : s) {
			if (i == '(' || i == '<' || i == '[' || i == '{') {
				stk.push(i);
			}
			else {
				if (stk.empty()) {
					answer = 0;
					break;
				}
				char a = stk.top();
				stk.pop();
				if (a == '('&&i == ')' || a == '{'&&i == '}' 
					|| a == '['&&i == ']' || a == '<'&&i == '>') {

				}
				else {
					answer = 0;
					break;
				}
			}
		}
		
		cout << '#' << t_case << " " << answer<<'\n';
	}
}