#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
char box[20][20];
int n;
string answer;

void checkRight(int i, int j) {
    int rock = 0;
    while (j < n) {
        if (box[i][j] != 'o') {
            return;
        }
        rock++;
        j++;
        if (rock == 5) {
            answer = "YES";
            return;
        }
    }
    return;
}

void checkDown(int i, int j) {
    int rock = 0;
    while (i < n) {
        if (box[i][j] != 'o') {
            return;
        }
        rock++;
        i++;
        if (rock == 5) {
            answer = "YES";
            return;
        }
    }
    return;
}

void checkCross(int i, int j) {
    int rock = 0;
    while (i < n && j < n) {
        if (box[i][j] != 'o') {
            return;
        }
        rock++;
        i++;
        j++;
        if (rock == 5) {
            answer = "YES";
            return;
        }
    }
    return;
}

void checkCross2(int i, int j) {
    int rock = 0;
    while (i < n && j >= 0) {
        if (box[i][j] != 'o') {
            return;
        }
        rock++;
        i++;
        j--;
        if (rock == 5) {
            answer = "YES";
            return;
        }
    }
    return;
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test_case;
    int T;
    cin >> T;


    for (test_case = 1; test_case <= T; ++test_case) {
        answer = "NO";

        cin >> n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char a;
                cin >> a;
                box[i][j] = a;
            }
        }
        for (int i = 0; i < n; i++) {
            if (answer == "YES")break;
            for (int j = 0; j < n; j++) {
                if (box[i][j] == 'o') {
                    checkRight(i, j);
                    checkDown(i, j);
                    checkCross(i, j);
                    checkCross2(i, j);
                }
            }
        }

        cout << '#' << test_case << ' ' << answer << '\n';
    }

    return 0;
}