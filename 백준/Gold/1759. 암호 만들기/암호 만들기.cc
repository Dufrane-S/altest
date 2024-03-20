#include <bits/stdc++.h>
using namespace std;
vector<char>cha;
int x,y;
int mo=0;
int ja=0;
char arr[16];
int done[16];
void func(int n){
    if(n==x){
        if(mo>=1&&ja>=2){
            for(int i=0;i<x;i++){
                cout<<arr[i];
            }
            cout<<'\n';
        }
        return;
    }

    for(int i=0;i<y;i++){
        if(done[i])continue;
        if(n>=1&&cha[i]<arr[n-1])continue;
        done[i]=1;
        arr[n]=cha[i];
        if(cha[i]=='a'||cha[i]=='e'||cha[i]=='i'||cha[i]=='o'||cha[i]=='u') {
            mo++;
        }else{
            ja++;
        }
        func(n+1);
        done[i]=0;
        if(cha[i]=='a'||cha[i]=='e'||cha[i]=='i'||cha[i]=='o'||cha[i]=='u') {
            mo--;
        }else{
            ja--;
        }

    }

}

int main(void){
    cin>>x>>y;

    for(int i=0;i<y;i++){
        char a;
        cin>>a;
        cha.push_back(a);
    }
    sort(cha.begin(),cha.end());
    func(0);
}