#include <map>
#include <iostream>
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    map<string,string>m;
    for(int i=0;i<x;i++){
        string a,b;
        cin>>a>>b;
        m[a]=b;
    }
    for(int i=0;i<y;i++){
        string c;
        cin>>c;
        cout<<m[c]<<'\n';
    }
}