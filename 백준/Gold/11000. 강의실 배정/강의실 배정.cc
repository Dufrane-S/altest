#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int x;
    cin>>x;
    vector<pair<int,int>>v;
    for(int i=0;i<x;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a, b});
    }
    sort(v.begin(),v.end());
    priority_queue<int>pq;
    pq.push(-v[0].second);
    for(int i=1;i<x;i++){
        if(v[i].first<-pq.top()){
            pq.push(-v[i].second);
        }else{
            pq.pop();
            pq.push(-v[i].second);
        }
    }
    cout<<pq.size();
}