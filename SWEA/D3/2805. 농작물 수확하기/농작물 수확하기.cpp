#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int answer=0;

        int fSize;
        cin>>fSize;
        int farm[fSize][fSize];
        for(int i=0;i<fSize;i++){
            string num;
            cin>>num;
            for(int j=0;j<fSize;j++){
                farm[i][j]=num[j]-'0';
            }
        }
        int mid=fSize/2;
        int dx=0;
        for(int i=0;i<fSize;i++){
            for(int j=mid-dx;j<mid+dx+1;j++){
                answer+=farm[i][j];
            }
            if(i<fSize/2){
                dx++;
            }else{
                dx--;
            }
        }


        cout<<'#'<<test_case<<' '<<answer<<'\n';
    }


    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}