#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;

int solution(int n)
{
    
    int ans=0;
    if(n==0)return 0;
    
    while(n!=1){
        if(n%2==0){
            n=n/2;
        }else{
            n-=1;
            ans++;
        }
    }
    ans++;
    return ans;
    /*int arr[n+1];
    arr[1]=1;
    for(int i=2;i<=n;i++){
        if(i%2==0){
            arr[i]=min(arr[i-1]+1,arr[i/2]);
        }else{
            arr[i]=arr[i-1]+1;
        }
    }
    
    return arr[n];*/
}