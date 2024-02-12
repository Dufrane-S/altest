#include<bits/stdc++.h>
using namespace std;


int bfs(vector<vector<int>>wire){
    vector<int> visited(wire.size()+1);
    queue<int>q;
  
    q.push(1);
    int nodes=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(visited[x]==1)continue;
        visited[x]=1;
        nodes++;
        for(auto i:wire[x]){
            q.push(i);
        }
    }
    int nodes2=wire.size()-1-nodes;
    return abs(nodes-nodes2);
    
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 102;
    
    for(int i=0;i<wires.size();i++){
        vector<vector<int>>w(n+1);
        for(int j=0;j<wires.size();j++){
            if(i==j)continue;
            w[wires[j][0]].push_back(wires[j][1]);     
            w[wires[j][1]].push_back(wires[j][0]);
        }
        answer=min(answer,bfs(w));
        w.clear();
    }
    return answer;
}