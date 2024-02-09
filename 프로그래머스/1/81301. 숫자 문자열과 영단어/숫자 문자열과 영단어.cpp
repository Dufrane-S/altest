#include<bits/stdc++.h>

using namespace std;

int solution(string s) {
    cout<<'9'-48;//10보다 작으면 숫자
    string temp="";
    map<string,string>m;
    m["zero"]="0";
    m["one"]="1";
    m["two"]="2";
    m["three"]="3";
    m["four"]="4";
    m["five"]="5";
    m["six"]="6";
    m["seven"]="7";
    m["eight"]="8";
    m["nine"]="9";
    for(int i=0;i<s.size();i++){
        if(s[i]-48<10){
            temp+=s[i];
        }else{
            string word="";
            while(true){
                if(m.find(word)==m.end()){
                    word+=s[i];
                    i++;
                }else{
                    temp+=m[word];
                    i--;
                    break;
                }
            }
        }
    }
    int answer = stoi(temp);
    return answer;
}