#include<iostream>
#include<utility>
#include<bitset>
#include<cstring>
#define X first
#define Y second
using namespace std;
int main(){
	int n;
	int ds;
	int a[200]={0};
	while(cin>>n,n){
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++){
		cin>>ds;
		a[ds]++;
	}
	for(int i=0;i<=100;i++){
		for(int j=0;j<a[i];j++){
			if(i||j)cout<<" ";
			cout<<i;
		}
	}
	cout<<endl;
}}
