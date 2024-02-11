#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers) {
    sort(numbers.begin(),numbers.end());
    int answer = 0;
    int idx=0;
    for(int i=0;i<10;i++){
        if(numbers[idx]!=i){
            answer+=i;
        }else{
            idx++;
        }
    }
    return answer;
}