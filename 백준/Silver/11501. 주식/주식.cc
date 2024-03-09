#include <bits/stdc++.h>
using namespace std;


int main(void){


    int x,y;
    cin>>y;
    vector<long>answers;
    for(int s=0;s<y;s++){

        cin>>x;
        vector<int>market;

        for(int i=0;i<x;i++){
            int a;
            cin>>a;
            market.push_back(a);
        }
        int idx=0;
        vector<pair<int,int>>large;
        while(idx<x){

            int big=0;
            for(int i=idx;i<x;i++){
                if(big<=market[i]) {
                    big = market[i];
                    idx = i + 1;
                }
            }
            large.push_back({big,idx-1});
        }
        idx=0;
        long answer=0;
        for(auto i:large){
            for(int j=idx;j<i.second;j++){
                answer+=i.first-market[j];
            }
            idx=i.second+1;
        }
        answers.push_back(answer);
    }
    for(auto i:answers){
        cout<<i<<'\n';
    }
}