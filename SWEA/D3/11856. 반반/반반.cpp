#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string answer="Yes";
        unordered_set<char>set;
        unordered_map<char,int>map;
        string s;
        cin>>s;
        for(auto i:s){
            set.insert(i);
            map[i]++;
        }
        if(set.size()!=2)answer="No";
        for(auto i:map){
            if(i.second!=2)answer="No";
        }

        cout<<"#"<<test_case<<' '<<answer<<'\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}