#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {


    int n;
    cin>>n;
    vector<int>now;
    vector<int>target;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        now.push_back(a);
    }

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        target.push_back(a);
    }
    int answer=0;
    for(int i=0;i<n;i++){
        answer+=abs(target[i]-now[i]);
    }
    cout<<answer/2;
    return 0;
}