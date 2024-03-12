#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string big="-99999";
    string small="999999";
    string temp="";
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            if(stoi(temp)>stoi(big))big=temp;
            if(stoi(temp)<stoi(small))small=temp;
        
            temp="";
        }else{
            temp+=s[i];
        }
    }
    if(stoi(temp)>stoi(big))big=temp;
    if(stoi(temp)<stoi(small))small=temp;
    string answer=small+" "+big;
    return answer;
}