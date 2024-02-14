#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string,int>m;
    vector<string>kind;
    for(auto s:clothes){
        if(m[s[1]]==0)kind.push_back(s[1]);
        m[s[1]]+=1;
    }
    int answer=1;
    for(auto s:kind){
        answer=answer*(m[s]+1);
        cout<<m[s]<<' ';
    }
    return answer-1;
}