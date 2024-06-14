#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int n;
    cin>>n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({b,a});
    }
    sort(v.begin(), v.end());
    int beforeend=0;
    int answer=0;
    for(pair i:v){
        if(beforeend<=i.second){
            answer++;
            beforeend=i.first;
        }
    }
    cout<<answer;

    return 0;
}