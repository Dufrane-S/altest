/*

#include <iostream>
#include <map>
#include <string>
#include <math.h>
using namespace std;

int main(){
    string target;
    cin>>target;
    int x;
    cin>>x;
    map<int,int>m;
    for(int i=0;i<x;i++){
        int a;
        cin>>a;
        m[a]++;
    }
    string s="";
    for(int i=0;i<target.size();i++){
        int small=11;
        int snum;
        for(int j=0;j<10;j++){
            if(m[j]==0&&small>abs( (target[i] - '0') - j)){
                small=abs( (target[i] - '0') - j);
                snum=j;
            }
        }
        s+=to_string(snum);
    }
    if(target=="100") { cout << 0; return 0;}
    cout<<target<<' '<<s<<' '<<abs(stoi(target)-stoi(s))+target.size();
}*/

#include <iostream>
#include <map>
using namespace std;
int main() {
    int x;
    cin>>x;
    map<long long ,int>m;
    for(int i=0;i<x;i++){
        long long a;
        cin>>a;
        m[a]++;
    }
    int size=0;
    long long big=0;

    for(auto i:m){
        if(i.second>size){
            size=i.second;
            big=i.first;
        }else if(i.second==size&&big>i.first)big=i.first;
    }
    cout<<big;
}