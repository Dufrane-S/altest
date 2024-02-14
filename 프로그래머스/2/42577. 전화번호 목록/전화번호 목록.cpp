#include<bits/stdc++.h>


using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(),phone_book.end());
    map<string,int>m;
    for(auto s:phone_book){
        string temp="";
        for(int i=0;i<s.size();i++){
            temp+=s[i];
            if(m.find(temp)!=m.end())return false;
        }
        m[temp]=1;
    }
    return true;
}