#include<bits/stdc++.h>
using namespace std;

int djs[200005],cnt[200005],sz[200005];
vector<int> mem[200005];

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}

vector<pair<int,int>> edg;
vector<int> G[200005];
int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)djs[i]=i;
    for(int i=1;i<=m;++i){
        int u,v; cin>>u>>v;
        edg.emplace_back(u,v);
        G[u].push_back(v);
        G[v].push_back(u);
        djs[F(u)]=F(v);
    }
    for(auto e:edg){
        ++cnt[F(e.first)];
    }
    for(int i=1;i<=n;++i)++sz[F(i)],mem[F(i)].push_back(i);
    int ans=0;
    for(int i=1;i<=n;++i){
        if(cnt[i]==sz[i] && sz[i]){
            bool ok=1;
            for(int j:mem[i])if(G[j].size()!=2u)ok=0;
            ans+=ok;
        }
    }
    cout<<ans<<endl;
}
