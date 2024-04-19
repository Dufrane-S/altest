#include<iostream>
#include<vector>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int>classes;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        classes.push_back(a);
    }
    int b,c;
    cin>>b>>c;
    long long answer=n;
    for(int i=0;i<n;i++){
        classes[i]-=b;
        if(classes[i]>0){
            answer=answer+classes[i]/c;
            if(classes[i]%c>0)answer++;
        }
    }
    cout<<answer;
    return 0;
}