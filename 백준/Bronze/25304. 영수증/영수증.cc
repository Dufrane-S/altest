#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int sum,n,goal;
    cin>>goal>>n;
    sum=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        sum+=(a*b);
    }
    if(sum==goal){
        cout<<"Yes";
    }else{
        cout<<"No";
    }

    return 0;
}