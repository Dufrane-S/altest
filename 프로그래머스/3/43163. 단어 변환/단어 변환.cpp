#include<bits/stdc++.h>

using namespace std;
int answer=99999;
string goal;
bool checkdif(string a, string b){
    int dif=0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]) dif++;
    }
    if(dif==1)return true;
    return false;
}


void dfs(string begin,map<string,int>m,vector<string>words,int depth){
    m[begin]+=1;
    depth++;
    if(begin==goal&&answer>depth)answer=--depth;
    for(auto i:words){
        if(m[i]==0&&checkdif(begin,i)){
            dfs(i,m,words,depth);
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    map<string,int>m;
    goal = target;
    int depth=0;
    if(find(words.begin(),words.end(),target)==words.end())return 0;
    dfs(begin,m,words,depth);
    return answer;
}