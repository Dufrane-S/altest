#include <bits/stdc++.h>

using namespace std;
int main(void){
    string s;
    string p;
    cin>>s>>p;
    int answer=0;
    string temp="";
    for(int i=0;i<p.size();i++){
        temp+=p[i];
        if(s.find(temp)==string::npos){
            answer++;
            temp="";
            i--;
            continue;
        }
    }
    cout<<++answer;
}