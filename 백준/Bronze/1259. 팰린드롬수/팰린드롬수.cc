#include <iostream>
using namespace std;
int main(void){
    while(1) {
        string s;
        cin >> s;
        bool flag=true;
        if(s=="0")break;
        int i;
        for (i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[s.length() - 1 - i]) {
                flag=false;
                break;
            }
        }
        if(flag) {
            cout << "yes\n";
        }else{
            cout<<"no\n";
        }
    }
}