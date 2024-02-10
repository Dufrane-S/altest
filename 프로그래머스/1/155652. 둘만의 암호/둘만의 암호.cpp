#include<bits/stdc++.h>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(int i=0;i<s.size();i++){
        char k=s[i];
        for(int j=0;j<index;j++){
            if(skip.find(k)!=string::npos){
                while(skip.find(k)!=string::npos){
                    k++;
                    if(k>'z')k-=26;
                }
            }
            k++;
            if(k>'z')k-=26;
            if(skip.find(k)!=string::npos){
                while(skip.find(k)!=string::npos){
                    k++;
                    if(k>'z')k-=26;
                }
            }
        }
        answer+=k;
    }
    return answer;
}