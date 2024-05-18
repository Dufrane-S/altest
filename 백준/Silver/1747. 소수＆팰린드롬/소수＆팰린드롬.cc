#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    cin>>n;

    if(n==1)n++;
    while(true){
        string temp = to_string(n);
        bool check=true;
        for(int i=0;i<temp.size()/2;i++){
            if(temp[i]!=temp[temp.size()-i-1]){
                check=false;
                break;
            }
        }
        if(check){
            for(int i=2;i<=sqrt(n);i++){
                if(n%i==0){
                    check=false;
                    break;
                }
            }
        }


        if(check){
            break;
        }

        n++;
    }

    cout<<n;
    return 0;
}