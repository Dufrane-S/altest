#include<iostream>
#include<unordered_map>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int answer=0;
        unordered_map<char,int>m;
        string s;
        cin>>s;
        for(auto i:s){
            m[i]=!m[i];
        }
        for(auto i:m){
            if(i.second)answer++;
        }

        cout<<"#"<<test_case<<' '<<answer<<'\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}