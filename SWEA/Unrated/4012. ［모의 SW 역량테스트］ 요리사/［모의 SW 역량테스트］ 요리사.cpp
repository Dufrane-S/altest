#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int m[100001];
int main() {
	int ctn;
	cin >> ctn;
	for (int ct = 1; ct <= ctn; ct++) {
		int n;
		cin >> n;
		int box[17][17];
		int a;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a;
				box[i][j] = a;
			}
		}

		int answer = INT_MAX;
		vector<int>checker;
		for (int i = 0; i < n/2; i++) {
			checker.push_back(0);
		}
		for (int i = n / 2; i < n; i++) {
			checker.push_back(1);
		}

		sort(checker.begin(), checker.end());
		do {
			int checka = 0;
			int checkb = 0;
			vector<int>a;
			vector<int>b;
			for (int i = 0; i < n;i++) {
				if (checker[i]) {
					a.push_back(i);
					checka += pow(2, i);
				}
				else {
					b.push_back(i);
					checkb += pow(2, i);
				}
			}
			if (m[checka == 1])break;

			m[checka] = 1;
			m[checkb] = 1;

			int suma = 0;
			int sumb = 0;

			for (int i = 0; i < a.size(); i++) {
				for (int j = i + 1; j < a.size(); j++) {
					suma += (box[a[i]][a[j]] + box[a[j]][a[i]]);
					sumb += (box[b[i]][b[j]] + box[b[j]][b[i]]);
				}
			}
			if (answer > abs(suma - sumb))answer = abs(suma - sumb);

		} while (next_permutation(checker.begin(), checker.end()));


		cout << '#' << ct << ' ' << answer << '\n';
	}
}