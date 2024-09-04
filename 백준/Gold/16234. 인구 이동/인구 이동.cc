#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int answer = 0;
int n, l, r;
vector<vector<int>>box = vector<vector<int>>(51, vector<int>(51, 0));
vector<queue<pair<int, int>>>opens;
vector<int>results;
vector<vector<int>>bfsdone = vector<vector<int>>(51, vector<int>(51, 0));
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

bool bfs(int y, int x) {
	//vector<vector<int>>done = vector<vector<int>>(51, vector<int>(51, 0));
	bool check = false;
	queue<pair<int, int>>q;
	queue<pair<int, int>>open;
	q.push({ y,x });
	open.push({ y,x });
	bfsdone[y][x] = answer;
	int sum = 0;
	sum += box[y][x];
	while (!q.empty()) {
		int nowy = q.front().first;
		int nowx = q.front().second;

		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = nowy + dy[k];
			int nx = nowx + dx[k];
			if (ny < 0 || nx < 0 || ny == n || nx == n || bfsdone[ny][nx] == answer)continue;
			int before = box[nowy][nowx];
			int next = box[ny][nx];
			if (abs(box[nowy][nowx] - box[ny][nx]) <= r && abs(box[nowy][nowx] - box[ny][nx]) >= l) {
				q.push({ ny,nx });
				open.push({ ny,nx });
				check = true;
				//done[ny][nx] = 1;
				bfsdone[ny][nx] = answer;
				sum += box[ny][nx];
			}

		}
	}

	int result = sum / open.size();
	while (!open.empty()) {
		box[open.front().first][open.front().second] = result;
		open.pop();
	}

	/*if (check) {
		int result = sum / open.size();
		results.push_back(result);
		opens.push_back(open);
	}*/
	return check;
}

void move() {
	for(int i=0;i<results.size();i++) {
		int result = results[i];
		queue<pair<int, int>>open = opens[i];
		while (!open.empty()) {
			box[open.front().first][open.front().second] = result;
			open.pop();
		}
		
	}
}

int main() {
	cin >> n >> l >> r;
	int a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			box[i][j]=a;
		}
	}
	bool opened = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bfsdone[i][j] = -1;
		}
	}
	do{
		
		opened = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (bfsdone[i][j] != answer) {
					bfsdone[i][j] = answer;
					if (bfs(i, j)) {
						opened = true;
					}
				}
			}
		}
		if(opened){ 
			answer++;
			//move();
			//opens.clear();
			//results.clear();
		}
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << box[i][j]<< ' ';
			}cout << '\n';
		}cout<<'\n';*/
	} while (opened);
	cout << answer;
}