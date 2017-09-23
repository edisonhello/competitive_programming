


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
int djs [100009],sz [100009],u[100009];
ll a[100009];
pii inf[100009];
int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}
void U(int x,int y){x=F(x),y=F(y);if(x==y)return;djs[x]=y,sz[y]+=sz[x];}
int gsz(int z){return sz[F(z)];}
int main(){int n;while(cin>>n){
for(int i =1;i<=n;++i){djs [i]=i,sz[i]=1;cin>>a[i];inf[i]={a[i],i};u[i]=0;}
for(int i =2;i<=n;++i)a[i]+=a[i-1];
sort(inf+1,inf+1+n);reverse(inf+1,inf+1+n); ll ans=0,l,r;
for(int id=1;id<=n;++id){auto i=inf[id];u[i.second]=1;
ll  lex=0; if(u[i.second-1])lex=gsz(i.second-1),U(i.second,i.second-1);
ll  rex =0; if(u[i.second+1])rex =gsz(i.second+1),U(i.second,i.second+1);;
ll nwv=(a[i.second+rex ]-a[i.second-lex-1])*i.first;
//cout<<i.first<<" "<<i.second<<" "<<lex<<" "<<rex<<endl;
if(nwv>ans)ans=nwv, l=i.second-lex,r=i.second+rex;
if(nwv==ans&& l>i.second-lex)l=i.second-lex,r=i.second+rex;
if(nwv==ans&& l==i.second-lex&&r>i.second+rex)r=i.second+rex; 
}cout<<ans<<endl<<l<<' '<<r<<endl;}}
