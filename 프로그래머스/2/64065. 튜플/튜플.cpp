#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> nums;
    vector<int> counts;
    map<int,int>m;
    string temp="";
    for(int i=2; i<s.size()-1; i++){
        if(s[i]==','||s[i]=='}'||s[i]=='{'){
            if(!temp.empty()){
                m[stoi(temp)]+=1;
                if(find(nums.begin(),nums.end(),stoi(temp))==nums.end())nums.push_back(stoi(temp));
            }
            temp="";
        }else{
            temp+=s[i];    
        }
    }
    for(auto i:nums){
        counts.push_back(m[i]);
        cout<<i<<" : "<<m[i]<<'\n';
    }
    sort(counts.rbegin(),counts.rend());
    for(auto i:counts){
        for(auto j:nums){
            if(m[j]==i){
                answer.push_back(j);
                break;    
            }
        }
    }
    return answer;
}