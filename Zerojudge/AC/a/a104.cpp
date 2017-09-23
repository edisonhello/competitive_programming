#include<iostream>
#include<algorithm>
#define X first
#define Y second
using namespace std;
int a[1000005];
int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(int i=0;i<n;i++){
			if(i)cout<<" ";
			cout<<a[i];
		}
		cout<<endl;
	}
}
