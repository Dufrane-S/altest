#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    vector<int> sorted=priorities;
    sort(sorted.rbegin(),sorted.rend());
    queue<pair<int,int>>q;
    for(int i=0;i<priorities.size();i++){
        q.push({priorities[i],i});
    }
    for(auto i: sorted){
        while(i!=q.front().first){
            q.push({q.front().first,q.front().second});
            q.pop();
        }
        if(q.front().second==location)return answer;
        q.pop();answer++;
    }
    return answer;
}