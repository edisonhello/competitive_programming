#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,w;
    edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
};
vector<edge> edg;
vector<int> G[1000006],iG[1000006],tp;
vector<pair<int,int>> cG[1000006];
bitset<1000006> v;
int bel[1000006];
long long bcw[1000006],dp[1000006];

void dfs1(int now){
    v[now]=1;
    for(int &eid:G[now])if(!v[edg[eid].v])dfs1(edg[eid].v);
    tp.push_back(now);
}
void dfs2(int now,int ccc){
    v[now]=1; bel[now]=ccc;
    for(int &eid:iG[now])if(!v[edg[eid].u])dfs2(edg[eid].u,ccc);
}
long long dfs3(int now){
    if(dp[now])return dp[now];
    for(auto i:cG[now]){
        dfs3(i.first);
        dp[now]=max(dp[now],i.second+dp[i.first]);
    } return dp[now]+=bcw[now];
}
long long meow(long long w){
    long long L=0,R=14444,M;
    while(R>L){
        M=(L+R+1)>>1;
        if((((M-1)*M)>>1)<=w)L=M;
        else R=M-1;
    }
    return w*L-((L-1)*L*(L+1))/6;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    while(m--){
        int u,v,w; cin>>u>>v>>w;
        G[u].push_back(edg.size());
        iG[v].push_back(edg.size());
        edg.emplace_back(u,v,w);
    }
    for(int i=1;i<=n;++i)if(!v[i])dfs1(i); v.reset();
    for(int i=n-1,cc=0;i>=0;--i)if(!v[tp[i]])dfs2(tp[i],cc++);
    for(auto &e:edg){
        if(bel[e.u]==bel[e.v])bcw[bel[e.u]]+=meow(e.w);
        else cG[bel[e.u]].emplace_back(bel[e.v],e.w);
    }
    int st; cin>>st; st=bel[st];
    cout<<dfs3(st)<<'\n';
}
