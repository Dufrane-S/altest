#include <bits/stdc++.h>

using namespace std;

int main(void){
    string s;
    cin>>s;
    string temp="";
    int i=0;
    int answer=0;
    while(s[i]!='-'&&i<s.size()){
        if(s[i]=='+') { answer += stoi(temp); temp=""; }
        temp+=s[i];
        i++;
    }
    answer += stoi(temp);
    i++;
    if(i>=s.size()) {
        cout<<answer;
        return 0;
    }
    temp="";
    while(i<s.size()){
        if(s[i]=='+'||s[i]=='-') { answer -= stoi(temp); temp=""; i++; }
        temp+=s[i];
        i++;
    }
    answer -= stoi(temp);
    cout<<answer;
}