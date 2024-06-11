#include <iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int answer=0;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		if(a*b>answer)answer=a*b;
	}
	cout<<answer;
	return 0;
}