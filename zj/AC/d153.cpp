#include<iostream>
#include<utility>
#include<bitset>
#include<cstring>
#include<algorithm>
#define X first
#define Y second
using namespace std;
int a[40005];
int main(){
	int ts;
	cin>>ts;
	while(ts--){
		int n;cin>>n;
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		cout<<a[(n-1)/2]<<endl;
	}
}
