#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey>0){
        int temp=storey%10;
        storey/=10;
        if(temp<5){
            answer+=temp;
        }else if(temp>5){
            temp=abs(temp-10);
            answer+=temp;
            storey++;
        }else if(temp==5){
            if(storey%10<5){
                answer+=temp;
            }else{
                answer+=temp;
                storey++;
            }
        }
    }
    return answer;
}