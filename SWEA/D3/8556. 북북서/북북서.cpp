#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {

    int test_case;
    int T;
    cin >> T;


    for (test_case = 1; test_case <= T; ++test_case) {
        int answer=0;

        string temp;
        cin>>temp;
        vector<char>nw;
        int idx=0;
        while(idx<temp.size()){
            if(temp[idx]=='w'){
                idx+=4;
                nw.push_back('w');
            }else{
                idx+=5;
                nw.push_back('n');
            }
        }
        reverse(nw.begin(), nw.end());
        int count=0;

        if(nw[0]=='n'){
            answer+=0;
        }else{
            answer+=90*pow(2,nw.size()-1);
        }

        for(int i=1;i<nw.size();i++){
            count++;
            if(nw[i]=='n'){
                answer-=(90*pow(2,nw.size()-1-count));
            }else if(nw[i]=='w'){
                answer+=(90*pow(2,nw.size()-1-count));
            }
        }

        while(count>0){
            if(answer%2==0){
                answer /= 2;
                count--;
            }else{
                break;
            }
        }
        if(count==0) {
            cout << '#' << test_case << ' ' << answer << '\n';
        }else{
            cout << '#' << test_case << ' ' << answer<< '/'<< pow(2,count) << '\n';
        }
    }

    return 0;
}