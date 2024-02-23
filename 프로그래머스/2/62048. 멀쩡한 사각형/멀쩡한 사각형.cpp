#include <cmath>
#include <iostream>

using namespace std;


long long solution(int w,int h) {
   
    long long answer=0;
    
    double a=w;
    double b=h;
    for(int i=1;i<w;i++){
        int x;
        x=floor(i*b/a);
        answer+=x;
    }
    
    return answer*2;
}