#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    vector<int>f;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int s;
        cin>>s;
        int answer=0;
        for(int a=0;a<s;a++) {
            int x, y;
            cin >> x >> y;
            int z=x*x+y*y;
            if(z<=400){
                answer+=10;
            }else if(z<=1600){
                answer+=9;
            }else if(z<=3600){
                answer+=8;
            }else if(z<=6400){
                answer+=7;
            }else if(z<=10000){
                answer+=6;
            }else if(z<=14400){
                answer+=5;
            }else if(z<=19600){
                answer+=4;
            }else if(z<=25600){
                answer+=3;
            }else if(z<=32400){
                answer+=2;
            }else if(z<=40000){
                answer+=1;
            }

        }
        f.push_back(answer);

    }
    for(int i=1;i<=test_case-1;i++){
        cout<<'#'<<i<<' '<<f[i-1]<<'\n';
    }

    return 0;
}