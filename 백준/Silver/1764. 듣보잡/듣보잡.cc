#include <bits/stdc++.h>
using namespace std;


int main(void){
    int x,y;
    cin>>x>>y;
    map<string,int>m;
    vector<string>answer;
    for(int i=0;i<x+y;i++){
        string s;
        cin>>s;
        if(m[s]==0){
            m[s]+=1;
        }else{
            answer.push_back(s);
        }
    }
    sort(answer.begin(),answer.end());
    cout<<answer.size()<<'\n';
    for(auto i:answer){
        cout<<i<<'\n';
    }
}