#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	vector<int>height;
	vector<bool>check;
	check.push_back(false);
	height.push_back(0);
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		height.push_back(k);
		check.push_back(false);
	}
	for(int i=1;i<=m;i++){
		int s,e;
		cin>>s>>e;
		for(int j=s;j<=e;j++){
			height[j]+=1;
			check[j]=true;
		}
		if(i%3==0){
				for(int k=1;k<=n;k++){
					if(check[k]){
						check[k]=false;
						height[k]-=1;
					}
				}
			}
		}
	for(int i=1;i<=n;i++){
		cout<<height[i]<<' ';
	}
	return 0;
}