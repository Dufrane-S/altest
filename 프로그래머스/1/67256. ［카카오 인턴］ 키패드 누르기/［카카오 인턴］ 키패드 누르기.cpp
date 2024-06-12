#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    unordered_map<int,char>m;
    m[1]='L';
    m[4]='L';
    m[7]='L';
    m[3]='R';
    m[6]='R';
    m[9]='R';
    unordered_map<char,int>son;
    unordered_map<int,pair<int,int>>wich; //처음이 x 다음이 y
    for(int i=1;i<=9;i++){
        wich[i]={(i-1)%3,(i-1)/3};
    }
    wich[-1]={1,3};
    for(auto i:numbers){
        if(i==0)i=-1;
        if(m[i]!=NULL){
            answer+=m[i];
            son[m[i]]=i;
            cout<<m[i]<<'\n';
        }else{
            // pair<int,int>lwich=wich[son['L']];
            // pair<int,int>rwich=wich[son['R']];
            pair<int,int>lwich;
            if(son['L']!=NULL){
                lwich=wich[son['L']];
            }else{
                lwich={0,3};
            }
            pair<int,int>rwich;
            if(son['R']!=NULL){
                rwich=wich[son['R']];
            }else{
                rwich={2,3};
            }
            int x = wich[i].first;
            int y = wich[i].second;
            int lcha=abs(lwich.first-x)+abs(lwich.second-y);
            int rcha=abs(rwich.first-x)+abs(rwich.second-y);
            cout<<lcha<<' '<<rcha<<'\n';
            cout<<"lcha = "<<lwich.first<<'-'<<x<<'+'<<lwich.second<<'-'<<y<<'\n';
            cout<<"rcha = "<<rwich.first<<'-'<<x<<'+'<<rwich.second<<'-'<<y<<'\n'<<'\n';
            if(lcha<rcha){
                son['L']=i;
                answer+='L';
            }else if(lcha>rcha){
                son['R']=i;
                answer+='R';
                cout<<son['R']<<"ㄴㅁㅁ\n";
            }else if(lcha==rcha){
                if(hand=="right"){
                    son['R']=i;
                    answer+='R';
                }else{
                    son['L']=i;
                    answer+='L';
                }
            }
            
        } 
    }
    return answer;
}