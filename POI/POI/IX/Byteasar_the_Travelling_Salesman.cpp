#include<bits/stdc++.h>
using namespace std;

vector<int> G[33333];
int p[16][33333],dep[33333];

int dfs(int now,int pa){
    p[0][now]=pa;
    dep[now]=dep[pa]+1;
    for(int i=1;i<16;++i){
        p[i][now]=p[i-1][p[i-1][now]];
    }
    for(int i:G[now]){
        if(i==pa)continue;
        dfs(i,now);
    }
}

int glca(int pa,int pb){
    if(dep[pa]>dep[pb])swap(pa,pb);
    for(int i=15;i>=0;--i)if((dep[pb]-dep[pa])&(1<<i)){
        pb=p[i][pb];
    }
    if(pa==pb)return pa;
    for(int i=15;i>=0;--i){
        if(p[i][pa]!=p[i][pb])pa=p[i][pa],pb=p[i][pb];
    }
    return p[0][pa];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int at=1,ans=0;
    dfs(1,0);
    int m; cin>>m; while(m--){
        int t; cin>>t;
        // ans+=dfs(at,at,t)-1;
        int lca=glca(at,t);
        ans+=dep[at]+dep[t]-2*dep[lca];
        at=t;
    }
    cout<<ans<<endl;
}
