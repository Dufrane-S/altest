#include <bits/stdc++.h>
using namespace std;


int main(void){

    long long x,y,w,s;
    cin >> x >> y >> w >> s;
    if(x<y){
        long long temp=y;
        y=x;
        x=temp;
    }
    long long a = (x+y) * w;
    long long b,c;

    if((x-y)%2==0){
        b = x*s;
    }else{
        b = (x-1)*s+w;//y*s+(x-y-1)*s+w;
    }
    c= y*s + (x-y)*w;
    cout<<min(min(a,b),c);

}