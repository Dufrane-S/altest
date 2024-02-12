#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(),routes.end());
    int minval=-39999;
    int maxval=39999;
    for(auto i:routes){
        if(maxval>=i[0]){
            minval=i[0];
            maxval=min(maxval,i[1]);
        }else{
            answer++;
            minval=i[0];
            maxval=i[1];
        }
    }
    
    answer++;
    return answer;
}