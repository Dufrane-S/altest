/*
#include<iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
//        int answer = 0;
        string answer = "Hello SSAFY";
        cout << '#' << test_case << ' ' << answer << '\n';


    }



    return 0;
}
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int answer = 0;
    int n;
    cin >> n;
    vector<int> v1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v1.push_back(a);
    }
    sort(v1.begin(), v1.end());

    do {
        int temp = 0;
        for (int i = 0; i < n - 1; i++) {
            temp += abs(v1[i] - v1[i + 1]);
        }
        if (temp > answer)answer = temp;
    } while (next_permutation(v1.begin(), v1.end()));

    cout << answer;
}