#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
	int n;
	cin>>n;
	map<int,int>a;
	map<int,int>b;
	char answer;
	vector<char>answers;
	for(int i=0;i<n;i++){
		answer='D';
		int k;
		cin>>k;
		int t;
		for(int j=0;j<k;j++){
			cin>>t;
			a[t]+=1;
		}
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>t;
			b[t]+=1;
		}
		
		for(int e=4;e>0;e--){
			if(a[e]>b[e]){
				answer='A';
				break;
			}else if(a[e]<b[e]){
				answer='B';
				break;
			}
		}
		answers.push_back(answer);
		for(int e=4;e>0;e--){
			a[e]=0;
			b[e]=0;
		}
	}
	for(auto i:answers){
		cout<<i<<"\n";
	}
	cout<<"\n";
	return 0;
}