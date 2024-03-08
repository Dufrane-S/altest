#include <bits/stdc++.h>
using namespace std;
int main(void){
   int x;
   cin>>x;
   vector<int> time;
   for(int i=0;i<x;i++){
       int a;
       cin>>a;
       time.push_back(a);
   }
   sort(time.begin(), time.end());
   int s=0;
   vector<int>a;
   for(int i=0;i<x;i++){
       s+=time[i];
       a.push_back(s);
   }
   int answer=0;
   for(auto i:a){
       answer+=i;
   }
   cout<<answer;
}