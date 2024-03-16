#include <bits/stdc++.h>
using namespace std;


int main(void){

  long long x,y;
  cin>>x>>y;
  vector<long long>nums;
  for(int i=0;i<x;i++){
      long long a;
      cin>>a;
      nums.push_back(a);
  }
  sort(nums.begin(), nums.end());
  for(int i=0;i<y;i++){
      nums[0]=nums[0]+nums[1];
      nums[1]=nums[0];
      sort(nums.begin(), nums.end());
  }
  long long answer=0;
  for(auto i:nums){
      answer+=i;
  }
  cout<<answer;
}