#include<iostream>
#include<utility>
#include<bitset>
#define X first
#define Y second
using namespace std;
int main(){
	int n;
	int ds;
	while(cin>>n){
	for(int i=1;i<=n;i++){
		if(i-1)cout<<" ";
		cout<<i;
		cin>>ds;
	}
	cout<<endl;
}}
