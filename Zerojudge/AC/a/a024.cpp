#include<iostream>
#include<utility>
#include<bitset>
#include<cstring>
#include<algorithm>
#define X first
#define Y second
using namespace std;
int main(){
	int a,b;
	while(cin>>a>>b){
	if(b>a)swap(a,b);
	while(b){
		a%=b;
		swap(a,b);
	}
	cout<<a<<endl;}
}
