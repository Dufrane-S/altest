#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 100
int main(int argc, char** argv)
{
    int test_case;
    int T;
//    cin>>T;
    T=10;
    for(test_case = 1; test_case <= T; ++test_case)
    {
       int answer=0;
       int box[MAX][MAX];
        int a;
        cin>>a;
       for(int i=0;i<MAX;i++){
           for(int j=0;j<MAX;j++){
               int a;
               cin>>a;
               box[i][j]=a;
           }
       }

       for(int i=0;i<MAX;i++){
           vector<int>row;
           for(int j=0;j<MAX;j++){
               if(box[j][i]!=0)row.push_back(box[j][i]);
           }
           int goal=1;
           for(auto j:row){
               if(goal==2&&j==goal){
                    answer++;
                    goal=1;
               }else if(goal==1&&j==goal){
                   goal=2;
               }
           }
       }

        cout<<'#'<<test_case<<' '<<answer<<'\n';

    }


    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}