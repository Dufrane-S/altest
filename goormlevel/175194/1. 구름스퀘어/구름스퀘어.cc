#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	vector<pair<int,int>>v;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		b++;
		v.push_back({b,a});
	}
	
	sort(v.begin(),v.end()); // 1 3; 3 4 ; 3 6 ; 5 7 ; 7 10 ; 5 11
	int answer=0;
	int beforeend=0;
	for(auto i:v){
		
		if(beforeend<=i.second){
			answer++;
			beforeend=i.first;
		}
	}
	cout<<answer;
	return 0;
}