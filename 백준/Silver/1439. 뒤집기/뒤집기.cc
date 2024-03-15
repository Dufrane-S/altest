#include <bits/stdc++.h>
using namespace std;


int main(void){

    string s;
    cin>>s;
    char c=s[0];
    int a=0;
    int b=0;
    if(s[0]=='0'){
        a++;
    }else{
        b++;
    }
    for(int i=1;i<s.size();i++){
        if(c!=s[i]){
            if(s[i]=='0'){
                a++;
            }else{
                b++;
            }
            c=s[i];
        }
    }
    cout<<(a<b?a:b);
}