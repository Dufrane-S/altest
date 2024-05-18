#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    int answer=0;
    int target=n;

    do{
        n=(n%10)*10+(n%10+n/10)%10;
        answer++;
    }while(target!=n);
    cout<<answer;
}