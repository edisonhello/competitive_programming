#include<iostream>
#include<cstring>
using namespace std;
int a[100005];
int main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	while(cin>>n>>m){
		for(int i=1;i<=n;++i){
			cin>>a[i];
			a[i]+=a[i-1];
		}
		for(int i=0;i<m;++i){
			int l,r;cin>>l>>r;
			cout<<a[r]-a[l-1]<<'\n';
		}
	}
}
