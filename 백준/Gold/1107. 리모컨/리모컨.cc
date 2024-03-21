#include <iostream>
using namespace std;

int arr[10];

bool ok(int i){
    string s= to_string(i);
    for(int j=0;j<s.size();j++){
        if(arr[s[j]-'0']==1)return false;
    }

    return true;
}

int main() {
    int target;
    cin>>target;
    int d;
    cin>>d;
    for(int i=0;i<d;i++){
        int a;
        cin>>a;
        arr[a]=1;
    }
    int answer=abs(target-100);
    for(int i=0;i<1000000;i++){
        if(ok(i)){
            int temp= abs(target-i)+to_string(i).size();
            answer=min(temp,answer);
        }
    }
    cout<<answer;
}