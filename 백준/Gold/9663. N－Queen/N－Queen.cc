#include <bits/stdc++.h>
using namespace std;

int counter=0;
int n;
bool isused1[40];
bool isused2[40];
bool isused3[40];

void func(int cur){
    if(cur == n){
        counter++;
        return;
    }

    for(int i=0; i < n; i++){
        if(isused1[i] || isused2[i+cur] || isused3[cur-i+n-1])continue;
        isused1[i]=true;
        isused2[i + cur]=true;
        isused3[cur - i + n - 1]=true;
        func(cur+1);
        isused1[i]=false;
        isused2[i + cur]=false;
        isused3[cur - i + n - 1]=false;
    }

}

int main(void){


    cin >> n;
    func(0);
    cout<<counter;
}