/*
#include<iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
//        int answer = 0;
        string answer = "Hello SSAFY";
        cout << '#' << test_case << ' ' << answer << '\n';


    }



    return 0;
}
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    vector<string>v;
    int kbs1;
    int kbs2;
    for(int i=0;i<n;i++) {
        string temp;
        cin>>temp;
        if(temp=="KBS1"){
            kbs1=i;
        }else if(temp=="KBS2"){
            kbs2=i;
        }
        v.push_back(temp);
    }
    string answer;

    if(kbs1<kbs2){
        string temp="";
        for(int i=0;i<kbs1;i++){
            answer+="1";
            temp+="4";
        }
        answer+=temp;
        temp.clear();
        for(int i=0;i<kbs2;i++){
            answer+="1";
            temp+="4";
        }
        answer+=temp;
        answer.pop_back();
    }else{
        string temp="";
        for(int i=0;i<kbs2;i++){
            answer+="1";
            temp+="4";
        }
        answer+=temp;
        temp.clear();
        for(int i=0;i<kbs1;i++){
            answer+="1";
            temp+="4";
        }
        answer+=temp;
    }

    cout<<answer;
}