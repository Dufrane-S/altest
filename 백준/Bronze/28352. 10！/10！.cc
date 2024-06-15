#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {


    int n;
    cin>>n;
    long long answer=1;

    for(int i=1;i<=n;i++){
        if(i==7||i==6||i==4)continue;
        answer*=i;
        if(i==10){
            answer/=60;
            answer/=60;
        }
    }
    cout<<answer;
    return 0;
}