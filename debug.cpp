#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int main(){
	unsigned long long n,m,a;
	unsigned long long len,wid;
	while(cin>>n>>m>>a){
		if(n%a!=0){
			len=ceil(n/a);
			}
		else{
			len=n/a;
			}
		if(m%a!=0){
			wid=ceil(m/a);
			}
		else{
			wid=m/a;
			}
		printf("%d",len*wid);
		}
	return 0;
	}
