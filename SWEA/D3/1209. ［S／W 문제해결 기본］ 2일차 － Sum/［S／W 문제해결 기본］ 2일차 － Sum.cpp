#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(int argc, char **argv) {
    int test_case;
    int T;
//    cin>>T;
    T = 10;
    for (test_case = 1; test_case <= T; ++test_case) {
        int as;
        cin>>as;
        int answer = 0;
        int box[100][100];
        for(int i=0;i<100;i++){
            int temp=0;
            for(int j=0;j<100;j++){
                int a;
                cin>>a;
                temp+=a;
                box[i][j]=a;
            }
            if(temp>answer)answer=temp;
        }
        for(int i=0;i<100;i++){
            int temp=0;
            for(int j=0;j<100;j++){
                temp+=box[j][i];
            }
            if(answer<temp)answer=temp;
        }
        int temp=0;
        int temp2=0;
        for(int i=0;i<100;i++){
            temp+=box[i][i];
            temp2+=box[99-i][i];
        }
        if(answer<temp)answer=temp;
        if(answer<temp2)answer=temp2;


        cout << '#' << test_case << ' ' << answer << '\n';

    }


    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}