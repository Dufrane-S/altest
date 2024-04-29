#include<iostream>
#include<cmath>
using namespace std;



int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        string answer = "yes";
        int n,m;
        cin>>n>>m;
        int box[n][m];
        int lista[n];
        int listb[m];
        for(int i=0;i<n;i++){
            string temp;
            cin>>temp;
            lista[i]=-1;
            for(int j=0;j<m;j++){
                box[i][j]=temp[j]-'0';
                listb[j]=-1;
            }
        }
        int i=0;
        int j=1;

        while(j<n&&answer!="no"){
            bool check=box[i][0]==box[j][0];
            for(int k=0;k<m;k++){
                if(check!=(box[i][k]==box[j][k])) {answer="no"; break; }
            }
            i++;
            j++;
        }
        i=0;
        j=1;
        while(answer!="no"&&j<m){
            bool check=box[0][i]==box[0][j];
            for(int k=0;k<n;k++){
                if(check!=(box[k][i]==box[k][j])) {answer="no"; break; }
            }
            i++;
            j++;
        }

        cout << '#' << test_case << ' ' << answer << '\n';
    }

    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}