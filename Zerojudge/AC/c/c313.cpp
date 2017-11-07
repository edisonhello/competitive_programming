#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> G[100005];
int d[100005],p[16][100005],mx[16][100005];


void dfs(int now,int pa,int dep){
    d[now]=dep;
    p[0][now]=pa;
    for(int i=1;(1<<i)<dep;++i){
        p[i][now]=p[i-1][p[i-1][now]];
        mx[i][now]=max(mx[i-1][now],mx[i-1][p[i-1][now]]);
    }
    for(auto i:G[now]){
        if(i.first==pa)continue;
        mx[0][i.first]=i.second;
        dfs(i.first,now,dep+1);
    }
}

int query(int u,int v){
    if(d[u]>d[v])swap(u,v);
    int rt=0;
    for(int i=0;i<16;++i)if((d[v]-d[u])&(1<<i)){
        rt=max(rt,mx[i][v]);
        v=p[i][v];
    }
    if(u==v)return rt;
    for(int i=15;i>=0;--i)if(p[i][u]!=p[i][v]){
        rt=max(rt,mx[i][v]);
        rt=max(rt,mx[i][u]);
        v=p[i][v];
        u=p[i][u];
    }
    return max(rt,max(mx[0][u],mx[0][v]));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0,u,v,k;i<n-1;++i){
        cin>>u>>v>>k;
        G[u].emplace_back(v,k);
        G[v].emplace_back(u,k);
    }
    dfs(1,0,1);
    int q; cin>>q; while(q--){
        int u,v; cin>>u>>v;
        cout<<query(u,v)<<endl;
    }
}
