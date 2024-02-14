#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<pair<int,int>>q;
    for(int i=0;i<speeds.size();i++){
        q.push({progresses[i],speeds[i]});
    }
    int i=0;
    while(!q.empty()){
        int temp=0;
        q.front().first=q.front().first+i*q.front().second;
        while(q.front().first<100){
            q.front().first+=q.front().second;
            i++;
        }
        q.pop();temp++;
        if(q.empty()){answer.push_back(temp); break;}
        while(!q.empty()&&q.front().first+i*q.front().second>=100){
            q.pop();temp++;
        }
        answer.push_back(temp);
        
    }
    q.front().first+=1;
    return answer;
}