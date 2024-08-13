#include <iostream>
#include <vector>
#include <string>


using namespace std;

void midorder(vector<vector<int>> v, vector<char> v2, int n, int k) {
    if(v[k][1]!=0)midorder(v,v2,n,v[k][1]);
    cout<<v2[k];
    if(v[k][2]!=0)midorder(v,v2,n,v[k][2]);
}

int main() {

    for(int tc=1;tc<=10;tc++){
        cout<<'#'<<tc<<' ';
        int n;
        cin>>n;
        vector<vector<int>>v(n+1,vector<int>(3,0));
        vector<char>v2(n+1,'a');
        for(int i=0;i<=n;i++){
            string s;

            getline(cin, s);
            int count=0;
            string temp="";
            vector<string>chars;
            for(auto i:s){
                if(i==' ') {
                    count++;
                    chars.push_back(temp);
                    temp="";
                }else{
                    temp+=i;
                }
            }
            chars.push_back(temp);

            int a,b,c;
            char d;
            if(3==count){
                if(chars[0].length()==1){
                    a = chars[0][0]-'0';
                }else{
                    a = stoi(chars[0]);
                }
                if(chars[2].length()==1){
                    b = chars[2][0]-'0';
                }else{
                    b=stoi(chars[2]);
                }
                if(chars[3].length()==1){
                    c = chars[3][0]-'0';
                }else{
                    c = stoi(chars[3]);
                }
                d=chars[1][0];
                v[i][0]=a;
                v[i][1]=b;
                v[i][2]=c;
                v2[i]=d;
            }else if(2==count){
                if(chars[0].length()==1){
                    a = chars[0][0]-'0';
                }else{
                    a = stoi(chars[0]);
                }
                if(chars[2].length()==1){
                    b = chars[2][0]-'0';
                }else{
                    b=stoi(chars[2]);
                }
                d=chars[1][0];
                v[i][0]=a;
                v[i][1]=b;
                v2[i]=d;
            }else if(1==count){
                if(chars[0].length()==1){
                    a = chars[0][0]-'0';
                }else{
                    a = stoi(chars[0]);
                }
                d=chars[1][0];
                v[i][0]=a;
                v2[i]=d;
            }
        }
//        for(auto i: v){
//            for(auto j:i){
//                cout<<j<<' ';
//            }cout<<'\n';
//        }
//        for(auto i: v2){
//            cout<<i<<' ';
//        }
        midorder(v,v2,n,1);
        cout<<'\n';
    }
}

