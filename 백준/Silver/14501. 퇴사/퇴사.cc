#include <iostream>
#include <vector>
using namespace std;
int box[200];
int main() {
    int x;
    cin>>x;
    vector<pair<int,int>>s;
    for(int i=0;i<x;i++){
        int a,b;
        cin>>a>>b;
        s.push_back({a,b});
    }
    box[s[0].first-1]=s[0].second;
    for(int i=1;i<x;i++){
        if(s[i].first+i-1<s.size()&&box[s[i].first+i-1]<box[i-1]+s[i].second)box[s[i].first+i-1]=box[i-1]+s[i].second;
        if(s[i].first!=1&&box[i-1]>box[i])box[i]=box[i-1];
    }
    cout<<box[x-1]<<' ';
}