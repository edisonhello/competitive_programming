#include<iostream>
#include<utility>
#include<bitset>
#include<cstring>
#include<algorithm>
#define X first
#define Y second
using namespace std;
int d[50005],sz[50005],cnt;
int F(int a){
	if(d[a]==a) return a;
	else return d[a]=F(d[a]);
}
void U(int a,int b){
	a=F(a);b=F(b);
	if(a==b)return ;
	cnt--;
	if(sz[b]>sz[a])swap(a,b);
	d[b]=a;
	sz[a]+=sz[b];
	return;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,m,cs=0;
	while(cin>>n>>m&&n){
		memset(d,0,sizeof(d));
		cnt=n;
		for(int i=0;i<=n+1;i++){
			d[i]=i;
			sz[i]=1;
		}
		while(m--){
			int a,b;cin>>a>>b;
			U(a,b);
		}
		cout<<"Case "<<(++cs)<<": "<<cnt<<endl;
	}
}
