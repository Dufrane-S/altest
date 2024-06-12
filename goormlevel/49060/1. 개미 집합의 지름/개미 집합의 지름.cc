#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	vector<int>ants;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		ants.push_back(a);
	}
	sort(ants.begin(),ants.end());
	
	int s=0;
	int e=0;
	int r=0;
	while(e<n&&s<n){
		if(ants[e]-ants[s]<=m){
			r=max(r,e-s+1);
			e++;
		}else{
			s++;
		}
	}
	cout<<n-r;
	return 0;
}