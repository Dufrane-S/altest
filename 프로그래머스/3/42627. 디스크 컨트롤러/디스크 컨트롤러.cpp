#include<bits/stdc++.h>


using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(),jobs.end());
    
    priority_queue<pair<int,int>>pq;
    int time=0;
    //pq.push({-jobs[0][1],jobs[0][0]});
    int idx=0;
    while(!pq.empty()||idx<jobs.size()){
        
        while(idx<jobs.size()&&time>=jobs[idx][0]){
            pq.push({-jobs[idx][1],jobs[idx][0]});
            idx++;
        }
        
        if(!pq.empty()){
            time-=pq.top().first;
            answer+=time-pq.top().second;
            pq.pop();
        }else {//if(idx<jobs.size()&&time<jobs[idx][0]){
            time=jobs[idx][0];
        }
        
    }
    
    return answer/jobs.size();
}