#include <iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int answer=3;
	for(int i=1;i<n;i++){
		answer*=2;
		answer=answer%100000007;
	}
	cout<<answer;
	return 0;
}