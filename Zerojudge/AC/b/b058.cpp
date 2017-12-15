// copy from TIOJ 1142
#include<cstdio>
#include<vector>
#include<bitset>
#include<cstring>
using namespace std;
int m,n,w[10005],t[10005],mt,cnt;
vector<int> G[10005],invG[10005];
bitset<10005> v;
void dfs(int now,int nt){
	nt+=w[now];
	if(nt<=t[now])return;
	t[now]=nt;
	mt=max(mt,nt);
	for(int i=0;i<(int)G[now].size();++i){
		dfs(G[now][i],nt);
	}
}
void invdfs(int now,int nt){
	if(nt!=t[now] || v[now])return;
	v[now]=1;++cnt;
	nt-=w[now];
	for(int i=0;i<(int)invG[now].size();++i){
		invdfs(invG[now][i],nt);
	}
}
int main(){
	while(scanf("%d%d",&n,&m)!=-1){
    mt=cnt=0; v.reset();
    for(int i=0;i<10005;++i)w[i]=t[i]=0,G[i].clear(),invG[i].clear();
	for(int i=1;i<=n;++i){
		scanf("%d",&w[i]);
	}
	while(m--){
		int s,e;
		scanf("%d%d",&s,&e);
		G[s].push_back(e);
		invG[e].push_back(s);
	}
	for(int i=1;i<=n;++i){
		dfs(i,0);
	}
	/*for(int i=1;i<=n;++i){
		cout<<t[i]<<" ";
	}cout<<endl;
	cout<<mt<<endl;*/
	for(int i=1;i<=n;++i){
		if(t[i]==mt){
			invdfs(i,t[i]);
		}
	}
	printf("%d\n",cnt);
}}
