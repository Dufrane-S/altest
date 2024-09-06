#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    for (int zxcv = 0; zxcv < tc; zxcv++) {
        int n, m;
        cin >> n >> m;
        vector<int> done = vector<int>(10001, 0);
        queue<pair<int, string>> q;

        q.push({n, ""});
        done[n] = 1;


        while (!q.empty()) {
            int nownum = q.front().first;
            string nowstr = q.front().second;
            if (nownum == m) {
                cout << nowstr << '\n';
                break;
            }
            q.pop();
            if (nownum * 2 <= 9999 && done[nownum * 2] == 0) {
                string tmp = nowstr;
                q.push({nownum * 2, tmp.append("D")});
                done[nownum * 2] = 1;
            } else if (done[nownum * 2 % 10000] == 0) {
                string tmp = nowstr;
                q.push({nownum * 2 % 10000, tmp.append("D")});
                done[nownum * 2 % 10000] = 1;
            }
            if (nownum - 1 >= 0 && done[nownum - 1] == 0) {
                string tmp = nowstr;
                q.push({nownum - 1, tmp.append("S")});
                done[nownum - 1] = 1;
            } else if (nownum == 0) {
                string tmp = nowstr;
                q.push({9999, tmp.append("S")});
                done[9999] = 1;
            }
            string nownums = to_string(nownum);
            if (nownums.size() < 4) {
                string tmp = "";
                for (int i = 0; i < 4 - nownums.size(); i++) {
                    tmp += "0";
                }
                nownums = tmp + nownums;
            }
            if (nownums.length() == 1)continue;
            /*string nownumr="";
            nownumr.push_back(nownums[nownums.size() - 1]);
            for (int i = 0; i < nownums.size() - 1; i++) {
                nownumr.push_back(nownums[i]);
            }
            int nownumrr = stoi(nownumr);*/


            int front = (nownum / 1000);
            int nownumll = (nownum - (front * 1000)) * 10 + front;

            if (done[nownumll] == 0) {
                string tmp = nowstr;
                done[nownumll] = 1;
                q.push({nownumll, tmp.append("L")});
            }


            int nownumrr = (nownum % 10) * 1000 + nownum / 10;
            if (done[nownumrr] == 0) {
                string tmp = nowstr;
                done[nownumrr] = 1;
                q.push({nownumrr, tmp.append("R")});
            }
            /*string nownuml="";
            for (int i = 1; i < nownums.size(); i++) {
                nownuml.push_back(nownums[i]);
            }
            nownuml.push_back(nownums[0]);
            int nownumll = stoi(nownuml);*/

        }
    }
}