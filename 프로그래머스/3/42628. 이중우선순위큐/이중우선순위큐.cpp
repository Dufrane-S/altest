#include<bits/stdc++.h>
using namespace std;
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int>temp;
    for(auto s:operations){
        if(s[0]=='I'){
            string i;
            for(int j=2;j<s.size();j++){
                i+=s[j];
            }
            temp.push_back(stoi(i));
        }else if(s[0]=='D'&&temp.size()!=0){
            if(s[2]!='-'){
                sort(temp.begin(),temp.end());
                temp.pop_back();
            }else{
                sort(temp.rbegin(),temp.rend());
                temp.pop_back();
            }
        }
    }
    if(temp.size()==0){
        return {0,0};
    }else if(temp.size()==1){
        return {temp[0],temp[0]};    
    }
    sort(temp.begin(),temp.end());
    return {temp[temp.size()-1],temp[0]};
}