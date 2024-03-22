#include<bits/stdc++.h>
using namespace std;

string arr[10001];
vector<vector<string>> t;
int done[10001];
bool flag=false;
int sizea;
void func(int n){
    if(n==sizea){
        flag=true;
        return;
    }
    for(int i=0;i<t.size();i++){
        if(t[i][0]==arr[n]&&done[i]==0){
            arr[n+1]=t[i][1];
            done[i]=1;
            func(n+1);
            if(flag)return;
            done[i]=0;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    
    sort(tickets.begin(),tickets.end());
    t=tickets;
    sizea=tickets.size();
    arr[0]="ICN";
    func(0);
    vector<string> answer;
   
    for(int i=0;i<sizea+1;i++){
        answer.push_back(arr[i]);
        cout<<arr[i]<<' ';
    }
    
    return answer;
}