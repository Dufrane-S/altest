#include <iostream>
using namespace std;
int main() {
	
	int n;
	cin>>n;
	int limit[n];
	int cal[n];
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		limit[i]=k;
	}
	
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		cal[i]=k;
	}
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cal[n-1]+=1;
		for(int j=n-1;j>=0;j--){
			if(cal[j]>limit[j]){
				if(j-1>-1)cal[j-1]+=1;
				cal[j]=0;
			}
		}
	}
	for(auto i:cal){
		cout<<i;
	}
	return 0;
}