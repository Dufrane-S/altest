#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for(int i=1;i<land.size();i++){
        for(int j=0;j<land[0].size();j++){
            int large=-1;
            for(int k=0;k<land[0].size();k++){
                if(j==k)continue;
                if(large<land[i][j]+land[i-1][k])large=land[i][j]+land[i-1][k];
            }
            land[i][j]=large;
        }
    }
    
    sort(land[land.size()-1].rbegin(),land[land.size()-1].rend());
    return land[land.size()-1][0];
}