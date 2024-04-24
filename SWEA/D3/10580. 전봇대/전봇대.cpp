#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(int argc, char **argv) {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        int answer =0;

        int n;
        cin>>n;
        int box[n][2];
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            box[i][0]=a;
            box[i][1]=b;
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i==j)continue;
                if(box[i][0]>box[j][0]){
                    if(box[i][1]<box[j][1])answer++;
                }else{
                    if(box[i][1]>box[j][1])answer++;
                }
            }
        }

        cout << '#' << test_case << ' ' << answer << '\n';

    }


    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}