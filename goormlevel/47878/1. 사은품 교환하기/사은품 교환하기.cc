#include <iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++){ //a 시즌 한정 최소 5 b 일반
		long long a,b;
		cin>>a>>b;
		long long aa;
		long long bb;
		aa=a/5;
		bb=b/7;
		long long answer=0;
		if(aa<=bb){
			answer+=aa;
		}else if(aa>bb){
			answer+=bb;
			aa=a-(bb*5);
			bb=b-(bb*7);
			
			if(aa-12+bb>=0){
			aa-=(12-bb);
			answer+=1;
			answer+=(aa/12);
			}
		}
		cout<<answer<<'\n';
	}
	
	return 0;
}