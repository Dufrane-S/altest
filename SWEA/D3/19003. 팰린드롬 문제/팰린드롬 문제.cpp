/*
#include<iostream>

using namespace std;


int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        int answer = 0;
        int n, m;
        cin >> n >> m;
          string words[n];
        for (int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            words[i] = temp;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i == j)continue;
                int a = 1;
                for (int k = 0; k <= m / 2; k++) {
                    if (words[i][k] != words[j][m - k - 1]) {
                        a = 0;
                        break;
                    }
                }
                if (a) {
                    answer++;
                }
            }
        }
        answer*=2;
        for (int i = 0; i < n; i++) {
            int a = 0, b = m - 1;
            for (; a < b; a++, b--) {
                if (words[i][a] != words[i][b])break;
            }
            if (a >= b) {
                answer++;
                break;
            }
        }

        cout << '#' << test_case << ' ' << answer * m << '\n';
    }


    return 0;
}*/

#include<iostream>
#include <vector>

using namespace std;

bool isPal(string temp){
    for(int i=0,j=temp.length()-1;i<j;i++,j--){
        if(temp[i]!=temp[j])return false;
    }
    return true;
}

int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        int answer = 0;
        int n, m;
        cin >> n >> m;
        vector<string>words;
        for (int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            if(isPal(temp)){
                answer=1;
            }else{
                words.push_back(temp);
            }
        }
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                if(i==j)continue;
                for(int k=0;k<m;k++){
                    if(words[i][k]!=words[j][m-k-1])break;
                    if(k==m-1)answer++;
                }
            }
        }

        cout << '#' << test_case << ' ' << answer * m << '\n';
    }


    return 0;
}