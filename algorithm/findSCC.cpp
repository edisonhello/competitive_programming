// TIOJ 1683
vint G[10009],topu,iG[10009],scc[10009],sccG[10009];
int belong[10009];
bool v[10009];

int dfs1(int now){
    v[now]=1;
    for(int i:G[now])if(!v[i])dfs1(i);
    topu.pb(now);
}
int dfs2(int now,int sccn){
    v[now]=1;
    scc[sccn].pb(now);
    belong[now]=sccn;
    for(int i:iG[now])if(!v[i])dfs2(i,sccn);
}
int dp[10009];
int dfs3(int now){
    if(v[now])return dp[now];
    v[now]=1; int meow=0;
    for(int i:sccG[now])meow=max(meow,dfs3(i));
    return dp[now]=meow+scc[now].size();
}

int main(){
    int ts,n,m;rit(ts);while(ts--){
        topu.clear();
        rit(n,m);
        for(int i=0;i<=n;++i)dp[i]=0,G[i].clear(),iG[i].clear(),scc[i].clear(),sccG[i].clear();
        {int u,v;while(m--){
            rit(u,v);
            G[u].pb(v), iG[v].pb(u);
        }}

        for(int i=0;i<=n;++i)v[i]=0;
        for(int i=1;i<=n;++i)if(!v[i])dfs1(i);
        for(int i=0;i<=n;++i)v[i]=0; int sccs=0;
        for(int i=n-1;i>=0;--i)if(!v[topu[i]])dfs2(topu[i],sccs++);
        for(int i=1;i<=n;++i){
            for(int ii:G[i]){
                sccG[belong[i]].pb(belong[ii]);
            }
        }
        for(int i=0;i<sccs;++i)sccG[i].resize(unique(sccG[i].begin(),sccG[i].end())-sccG[i].begin());

        for(int i=0;i<sccs;++i)v[i]=0; int mx=0;
        for(int i=0;i<sccs;++i)mx=max(mx,dfs3(i));
        pit(mx),el;
    }
}
