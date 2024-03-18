#include <bits/stdc++.h>
using namespace std;


int main(void){

    int x;
    cin>>x;
    vector<string>names;
    map<string,int>m;
    for(int i=0;i<x;i++){
        string  a,b;
        cin>>a>>b;
        names.push_back(a);
    }
    sort(names.rbegin(),names.rend());
    for(int i=0;i<names.size();i++){
        if(names[i]!=names[i+1]){
            cout<<names[i]<<'\n';
        }else{
            i++;
        }
    }
}