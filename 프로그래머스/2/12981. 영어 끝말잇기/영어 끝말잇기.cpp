#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    
    map<string,int>m;
    int idx=0;
    while(idx<words.size()-1){
        if(m[words[idx]]!=0){
            idx+=1;
            int c=idx%n;
            if(c==0)c=n;
            cout<<idx;
            double a=n;
            int b=ceil(idx/a);
            return {c,b};
        }
        if(words[idx+1][0]!=words[idx][words[idx].size()-1]){
            idx+=2;
            int c=idx%n;
            if(c==0)c=n;
            double a=n;
            int b=ceil(idx/a);
            return {c,b};
        }
        
        m[words[idx]]+=1;
        idx++;
    }
    
    if(m[words[idx]]!=0){
        idx+=1;
        int c=idx%n;
        if(c==0)c=n;
        cout<<idx;
        double a=n;
        int b=ceil(idx/a);
        return {c,b};
    }
    return {0,0};
}