#include <bits/stdc++.h>

using namespace std;
vector<string> temp;
int solution(string dirs) {
    int answer = 0;
    queue<pair<int,int>>q;
    q.push({5,5});
    //done[5][5]=true;
    int idx=0;
    while(idx<dirs.size()){
        int x= q.front().first;
        int y = q.front().second;
        int nx;
        int ny;
        q.pop();
        if(dirs[idx]=='R'){
            nx=x+1;
            ny=y;
        }else if(dirs[idx]=='L'){
            nx=x-1;
            ny=y;
        }else if(dirs[idx]=='D'){
            nx=x;
            ny=y-1;
        }else if(dirs[idx]=='U'){
            nx=x;
            ny=y+1;
        }
        if(ny>10||nx>10||ny<0||nx<0){
            q.push({x,y});
        }else{
            //if(done[y][x]==false||done[ny][nx]==false){
            string check=to_string(x)+to_string(y)+to_string(nx)+to_string(ny);
            string check2=to_string(nx)+to_string(ny)+to_string(x)+to_string(y);
            if(find(temp.begin(),temp.end(),check)==temp.end()&&find(temp.begin(),temp.end(),check2)==temp.end()){
                answer++;
                q.push({nx,ny});
                temp.push_back(check);
            }else{
                q.push({nx,ny});
            }
        }
        //done[y][x]=true;
        idx++;
    }
        
    return answer;
}