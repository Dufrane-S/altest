#include <iostream>
#include <algorithm>

using namespace std;


int main() {


    int n;
    cin>>n;
    int box [n+1];
    int large=0;
    int answer=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(a>large) {
            large = a;
            answer++;
        }
        box[i]=a;
    }cout<<answer<<'\n';
    answer=0;
    large=0;
    for(int i=n-1;i>=0;i--){
        if(box[i]>large){
            large=box[i];
            answer++;
        }
    }cout<<answer;

    return 0;
}