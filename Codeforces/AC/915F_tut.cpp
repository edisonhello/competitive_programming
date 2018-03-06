#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> G[1000006];
ll a[1000006];
int id[1000006],pos[1000006],djs[1000006],sz[1000006];
int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}
void U(int x,int y){x=F(x); y=F(y); if(x==y)return; djs[x]=y; sz[y]+=sz[x];}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],id[i]=i,djs[i]=i,sz[i]=1;
    sort(id+1,id+1+n,[](const int &q,const int &b){return a[q]<a[b];});
    for(int i=1;i<=n;++i)pos[id[i]]=i;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ll ans=0;
    for(int i=1;i<=n;++i){
        for(int j:G[id[i]]){
            if(pos[j]<i){
                ans+=a[id[i]]*sz[F(id[i])]*sz[F(j)];
                U(id[i],j);
            }
        }
    }
    for(int i=1;i<=n;++i)djs[i]=i,sz[i]=1;
    for(int i=n;i>=1;--i){
        for(int j:G[id[i]]){
            if(pos[j]>i){
                ans-=a[id[i]]*sz[F(id[i])]*sz[F(j)];
                U(id[i],j);
            }
        }
    }
    cout<<ans<<endl;
}
