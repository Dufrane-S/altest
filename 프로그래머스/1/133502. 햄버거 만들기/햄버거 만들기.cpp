#include <string>
#include <vector>
#include <iostream>
using namespace std;
int list[1000001];
int burger[4]={1,2,3,1};
int solution(vector<int> ingredient) {
    int answer=0;
    int idx=-1;
    for(auto i:ingredient){
        idx++;
        list[idx]=i;
        if(idx>=3){
            int k=1;
            for(int j=0;j<4;j++){
                if(burger[j]!=list[idx-3+j]){
                    k=0;
                    break;
                }
            }
            if(k){
                idx-=4;
                answer++;
            }
        }
    }
    return answer;
}