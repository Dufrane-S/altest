#include<iostream>
#include<vector>
#include<cmath>
#include<map>
#include<cstdio>

using namespace std;
int nums[10000000];
int main(int argc, char** argv)
{
    int test_case;
    int T;

    scanf("%d", &T);
    vector<int>sosu;
    for(int i=2;i<sqrt(10000000);i++){
        if(nums[i])continue;
        sosu.push_back(i);
        int a=1;
        while(i*a<sqrt(10000000)){
            nums[i*a]=1;
            a++;
        }
    }
    for(test_case = 1; test_case <= T; ++test_case)
    {

        map<int,int>m;
        int x;
        scanf("%d", &x);
        int s=0;
        while(x!=1&&s<sosu.size()){
            if(x%sosu[s]==0) {
                x /= sosu[s];
                m[sosu[s]]++;
            }else{
                ++s;
            }

        }

        int answer=x;
        for(auto i:m){
            if(i.second%2==1){
                answer*=i.first;
            }
        }

        cout<<"#"<<test_case<<" "<<answer<<'\n';
    }


    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}