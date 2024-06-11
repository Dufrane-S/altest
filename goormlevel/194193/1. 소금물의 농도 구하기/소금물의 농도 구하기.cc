#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	float n,m;
	cin>>n>>m;
	float salt = n*7;
	float answer = salt/(n+m);
	answer = floor(answer*100)/100;
	printf("%.2f",answer);
	return 0;
}
