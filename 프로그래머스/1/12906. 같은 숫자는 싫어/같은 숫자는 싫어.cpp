#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    for(auto i:arr){
        if(answer.empty()){
            answer.push_back(i);
            continue;
        }
        if(answer.back()!=i){
            answer.push_back(i);
        }
    }
    
 
    return answer;
}