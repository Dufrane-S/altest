#include <bits/stdc++.h>
using namespace std;

int box[2000000];

int test[26];
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string a,b;
	cin >> a>>b;
	for (auto c:a)
	{
		test[c - 'a']++;
	}
	for (auto c:b)
	{
		test[c - 'a']--;
	}
	int sum = 0;
	for (int i : test)
	{
		sum += abs(i);
	}
	cout << sum;
}