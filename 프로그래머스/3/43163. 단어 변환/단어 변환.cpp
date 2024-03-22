#include <string>
#include <vector>
#include <iostream>
using namespace std;
string target;
string arr[51];
vector<string>words;
int done[51];
int answer=0;
int ranswer=99999999;
bool isOk(string a,string b){
    int c=0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i])c++;
    }
    if(c==1)return true;
    return false;
}
void func(int n){
    if(arr[n]==target){
        for(int i=0;i<answer;i++){
            cout<<arr[i]<<' ';
        }
        if(ranswer>answer)ranswer = answer;
        
    }
    
    for(int i=0;i<words.size();i++){
        if(done[i]==0&&isOk(words[i],arr[n])){
            arr[n+1]=words[i];
            done[i]=1;
            answer++;
            func(n+1);
            answer--;
            done[i]=0;
        }
    }
    
}
int solution(string begin, string a, vector<string> w) {
    words=w;
    arr[0]=begin;
    target=a;
    func(0);
    if(ranswer==99999999)return 0;
    return ranswer;
}