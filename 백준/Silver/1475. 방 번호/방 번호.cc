#include <bits/stdc++.h>
using namespace std;

int box[10];
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a;
	cin >> a;
	while (a>0)
	{
		box[a % 10]++;
		a=a * 0.1;
	}
	int high = 1;
	for (int i = 0; i < 10; i++)
	{
		//cout << box[i]<<' ' ;
		if (high < box[i])
		{
			if (i == 6||i==9)
				continue;
			high = box[i];
		}
	}
	//cout << '\n';
	if (high>double(box[6]+box[9])/2)
	{
		cout << high;
	}
	else
	{
		cout << ceil(double(box[6] + box[9]) / 2);
	}
}