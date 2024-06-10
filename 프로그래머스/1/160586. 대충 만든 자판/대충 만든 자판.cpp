#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char,int>keynum;
    for(auto k:keymap){
        int idx=1;
        for(auto j:k){
            if(keynum[j]==0){
                keynum[j]=idx;
            }else if(keynum[j]>idx){
                keynum[j]=idx;
            }
            idx++;
        }
    }
    
    for(auto i:keynum){
        cout<<i.first<<' '<<i.second<<'\n';
    }
    
    for(auto i:targets){
        int temp=0;
        bool check=false;
        for(auto j:i){
            temp+=keynum[j];
            if(keynum[j]==0)check=true;
        }
        if(check)temp=-1;
        answer.push_back(temp);
    }
    
    
    return answer;
}