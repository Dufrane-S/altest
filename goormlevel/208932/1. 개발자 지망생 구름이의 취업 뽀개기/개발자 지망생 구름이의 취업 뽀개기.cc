#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	cin>>n;
	int lev[5];
	for(int i=0;i<5;i++){
		int a;
		cin>>a;
		lev[i]=a;
	}
	vector<int>a;
	vector<int>b;
	vector<int>c;
	vector<int>d;
	vector<int>e;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		if(x==1){
			a.push_back(y);
		}else if(x==2){
			b.push_back(y);
		}else if(x==3){
			c.push_back(y);
		}else if(x==4){
			d.push_back(y);
		}else if(x==5){
			e.push_back(y);
		}
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	sort(d.begin(),d.end());
	sort(e.begin(),e.end());
	
	int answer=0;
	for(int i=0;i<5;i++){
		int idx=0;
		int before=0;
		int now=0;
		while(lev[i]!=0){
			if(i==0){
				answer+=a[idx];
				now=a[idx];
			}else if(i==1){
				answer+=b[idx];
				now=b[idx];
			}else if(i==2){
				answer+=c[idx];
				now=c[idx];
			}else if(i==3){
				answer+=d[idx];
				now=d[idx];
			}else if(i==4){
				answer+=e[idx];
				now=e[idx];
			}
			if(before){answer+=(now-before);}
			before=now;
			idx++;
			lev[i]-=1;
		}	
		answer+=60;
	}
	answer-=60;
	cout<<answer;
	return 0;
}