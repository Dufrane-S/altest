#include <bits/stdc++.h>

using namespace std;

int main(void){
    int x;
    cin>>x;
    vector<int>a;
    vector<int>b;
    for(int i=0;i<x;i++){
        int y;
        cin>>y;
        a.push_back(y);
    }
    for(int i=0;i<x;i++){
        int y;
        cin>>y;
        b.push_back(y);
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    int answer=0;
    for(int i=0;i<x;i++){
        answer+=a[i]*b[i];
    }
    cout<<answer;
}