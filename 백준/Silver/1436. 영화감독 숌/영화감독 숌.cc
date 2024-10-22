#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n;
	int answer = 666;
	int count = 1;
	while(true) {
		string s = to_string(answer);
		if (s.find("666")!=string::npos && n == count) {
			break;
		}
		else if (s.find("666") != string::npos) {
			count++;
		}
		answer++;
		
	}
	cout << answer;
}