#include <iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	string answer;
	for(int i=0;i<n;i++){
		int x,y,t;
		cin>>x>>y>>t;
		int temp=abs(x)+abs(y);
		temp=t-temp;
		if(temp%2==0){
			answer="YES";
		}else{
			answer="NO";
		}
		if(temp<0)answer="NO";
		cout<<answer<<'\n';
	}
	return 0;
}