#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int len=0;
    int f=1;
    char fword=s[0];
    int d=0;
    bool check;
    for(int i=1;i<s.length();i++){
        len++;
        if(s[i]==fword){
            f++;
        }else{
            d++;
        }
        if(f==d){
            f=1;
            d=0;
            fword=s[i+1];
            len++;
            i+=1;
            answer++;
        }
    }
    if(len<s.length())answer++;
    return answer;
}