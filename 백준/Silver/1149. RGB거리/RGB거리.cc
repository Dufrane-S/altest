#include <bits/stdc++.h>
using namespace std;
int main(void){
   int x;
   cin>>x;
   vector<int> list[x];
   for(int i=0;i<x;i++){
       int a,b,c;
       cin>>a>>b>>c;
       list[i].push_back(a);
       list[i].push_back(b);
       list[i].push_back(c);
   }
    for(int i=1;i<x;i++){
        for(int j=0;j<3;j++){
            int mini=99999999999;
            for(int k=0;k<3;k++){
                if(k==j)continue;
                mini=min(mini,list[i][j]+list[i-1][k]);
            }
            list[i][j]=mini;
        }
    }
    cout<<min(min(list[x-1][0],list[x-1][1]),list[x-1][2]);
}