#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

string solution(string X, string Y) {
    map<char,int>y;
    map<char,int>x;
    map<char,int>r;
    string answer = "";
    for(auto i:Y){
        y[i]+=1;    
    }
    for(auto i:X){
        x[i]+=1;
    }
    for(auto i:x){
        int small;
        if(y[i.first]==0)continue;
        if(y[i.first]<i.second){
            small=y[i.first];
        }else{
            small=i.second;
        }
        r[i.first]=small;
    }
    vector<int>nums;
    if(r.empty()){
        answer="-1";
    }else{
        for(auto i:r){
            for(int j=0;j<i.second;j++){
                nums.push_back(i.first);
            }
        }
    }
    sort(nums.rbegin(),nums.rend());
    for(auto i:nums){
        answer+=i;
    }
    if(answer[0]=='0')answer="0";
    return answer;
}