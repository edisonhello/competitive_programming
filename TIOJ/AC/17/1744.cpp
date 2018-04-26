#include<bits/stdc++.h>
using namespace std;

vector<int> G[500005],iG[500005],tp,cG[500005];
bitset<500005> v,ep;
int we[500005],bel[500005],bwe[500005],dp[500005],ans,deg[500005];

void dfs(int now){
    v[now]=1;
    for(int i:G[now])if(!v[i])dfs(i);
    tp.push_back(now);
}
void dfs(int now,int cn){
    v[now]=1;
    bel[now]=cn;
    for(int i:iG[now])if(!v[i])dfs(i,cn);
}
int sdf(int now,int dis){
    if(now==dis)return bwe[now];
    if(v[now])return dp[now];
    v[now]=1;
    for(int i:cG[now]){
        dp[now]=max(dp[now],sdf(i,dis));
    }
    dp[now]+=bwe[now];
    return dp[now];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp,0xb0,sizeof(dp));
    int n,m; cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        iG[v].push_back(u);
    }
    for(int i=1;i<=n;++i)cin>>we[i];
    for(int i=1;i<=n;++i)if(!v[i])dfs(i);
    v.reset(); int cc=0;
    for(int i=n-1;i>=0;--i)if(!v[tp[i]])dfs(tp[i],++cc);
    for(int i=1;i<=n;++i)bwe[bel[i]]+=we[i];
    for(int i=1;i<=n;++i){
        for(int j:iG[i]){
            if(bel[i]!=bel[j])cG[bel[i]].push_back(bel[j]);
        }
    }
    v.reset();
    int s,p; cin>>s>>p;
    while(p--){
        int t; cin>>t;
        ep[bel[t]]=1;
        ans=max(ans,sdf(bel[t],bel[s]));
    }

    cout<<ans<<endl;
}
