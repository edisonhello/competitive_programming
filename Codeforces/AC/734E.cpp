#include<bits/stdc++.h>
using namespace std;

int djs[200005];
vector<pair<int,int>> edg;
set<int> G[200005];
int c[200005];
int d[200005];

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}

void dfs(int now,int pa){
    for(int i:G[now]){
        if(i==pa)continue;
        d[i]=d[now]+1;
        dfs(i,now);
    }
}

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)djs[i]=i,cin>>c[i];
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        if(c[u]==c[v])djs[F(u)]=F(v);
        else edg.emplace_back(u,v);
    }
    for(auto i:edg){
        G[F(i.first)].insert(F(i.second));
        G[F(i.second)].insert(F(i.first));
    }
    dfs(F(1),F(1));
    int mx=0;
    for(int i=1;i<=n;++i)mx=max(mx,d[i]);
    int p;
    for(int i=1;i<=n;++i)if(mx==d[i])p=i;
    d[p]=0;
    dfs(p,p);
    mx=0;
    for(int i=1;i<=n;++i)mx=max(mx,d[i]);
    cout<<(mx+1)/2<<endl;
}
