#include<iostream>
#include<utility>
#include<bitset>
#define X first
#define Y second
using namespace std;
int main(){
	int n;
	int ds;
	int a[4]={0};
	while(cin>>n){
	for(int i=0;i<n;i++){
		cin>>ds;
		a[ds]++;
	}
	for(int i=0;i<a[1];i++){
		if(i)cout<<" ";
		cout<<"1";
	}
	for(int i=0;i<a[2];i++){
		cout<<" 2";
	}
	for(int i=0;i<a[3];i++){
		cout<<" 3";
	}
	cout<<endl;
}}
