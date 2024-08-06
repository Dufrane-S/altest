#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int box[101][101];
int main() {

	int answer = 0;
	int a, b, c, d;
	for (int k = 0; k < 4; k++) {
		cin >> a >> b >> c >> d;
		for (int i = b; i < d; i++) {
			for (int j = a; j < c; j++) {
				box[i][j] = 1;
			}
		}

	}
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (box[i][j] == 1)answer++;
		}
	}

	cout << answer;
}
