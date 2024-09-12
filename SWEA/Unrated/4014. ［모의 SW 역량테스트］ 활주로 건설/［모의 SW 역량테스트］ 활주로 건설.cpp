/*#include <iostream>

using namespace std;

int box[21][21];

int n, m;

bool garo(int i) {
	cout << '\n';
	for (int j = 0; j < n-1; j++) {
		cout << box[i][j];
		if (box[i][j] > box[i][j+1]) {
			for (int k = j+1; k < m + j + 1; k++) {
				cout << box[i][j];
				if (k == n)return false;
				if (box[i][j + 1] != box[i][k])return false;
			}
			
			j += m - 1;
		}
		else if (box[i][j] < box[i][j + 1]) {
			for (int k = j; k > j - m; k--) {
				if (k == 0)return false;
				if (box[i][j] != box[i][k])return false;
			}
		}
	}
	return true;
}

bool sero(int j) {
	cout << '\n';
	for (int i = 0; i < n - 1; i++) {
		cout << box[i][j];
		if (box[i][j] > box[i+1][j]) {
			for (int k = i+1; k < m + i +1; k++) {
				cout << box[k][j];
				if (k == n)return false;
				if (box[i+1][j] != box[k][j])return false;
			}
			i += m - 1;
		}
		else if (box[i][j] < box[i+1][j]) {
			for (int k = i; k > i - m; k--) {
				if (k == 0)return false;
				if (box[i][j] != box[i][k])return false;
			}
		}
	}
	return true;
}


int main() {
	int ctn;
	cin >> ctn;
	for (int ct = 1; ct <= ctn; ct++) {
		int answer = 0;
		cin >> n >> m;
		int a;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a;
				box[i][j] = a;
			}
		}
		for (int i = 0; i < n; i++) {
			if (sero(i)) { answer++; cout <<'\n' << "세로" << i << '\n'; }
			if (garo(i)) {
				answer++; cout <<'\n' << "가로" << i << '\n';
			}
		}
		cout << '#' << ct << ' ' << answer << '\n';
	}
}*/
#include <iostream>
#include <vector>
using namespace std;

int box[21][21];

int n, m;

bool garo(int i) {
	vector<pair<int, int>>v;
	int now = box[i][0];
	pair<int, int>nowp = { now,0 };
	for (int j = 0; j < n; j++) {
		if (now != box[i][j]) {
			now = box[i][j];
			v.push_back(nowp);
			nowp = { now,1 };
		}
		else {
			nowp.second++;
		}
	}
	v.push_back(nowp);
	/*
	for (auto i : v) {
		cout << i.first << " : " << i.second << "   ";
	}cout << '\n';
	*/
	for (int i = 0; i < v.size() - 1; i++) {
		if (abs(v[i].first - v[i + 1].first) >= 2)return false;
		if (v[i].first > v[i + 1].first) {
			if (v[i + 1].second < m) { 
				return false; 
			}
			else {
				v[i + 1].second -= m;
			}

		}
		else if (v[i].first < v[i + 1].first) {
			if (v[i].second < m){return false;
			}
		}
	}
	//cout << "true\n";
	return true;
}

bool sero(int j) {
	vector<pair<int, int>>v;
	int now = box[0][j];
	pair<int, int>nowp = { now,0 };
	for (int i = 0; i < n; i++) {
		if (now != box[i][j]) {
			now = box[i][j];
			v.push_back(nowp);
			nowp = { now,1 };
		}
		else {
			nowp.second++;
		}
	}
	v.push_back(nowp);
	/*
	for (auto i : v) {
		cout << i.first << " : " << i.second << "   ";
	}cout << '\n';
	*/
	for (int i = 0; i < v.size() - 1; i++) {
		if (abs(v[i].first - v[i + 1].first) >= 2)return false;
		if (v[i].first > v[i + 1].first) {
			if (v[i + 1].second < m) {
				return false; 
			}
			else {
				v[i + 1].second -= m;
			}
		}
		else if (v[i].first < v[i + 1].first) {
			if (v[i].second < m){return false;
			}

		}
	}
	//cout << "true\n";
	return true;
}


int main() {
	int ctn;
	cin >> ctn;
	for (int ct = 1; ct <= ctn; ct++) {
		int answer = 0;
		cin >> n >> m;
		int a;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a;
				box[i][j] = a;
			}
		}

		for (int i = 0; i < n; i++) {
			if (sero(i))answer++;
			if (garo(i))answer++;
		}
		cout << '#' << ct << ' ' << answer << '\n';
	}
}
