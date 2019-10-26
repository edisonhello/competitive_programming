#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> G[100005];
int pa[21][100005],dep[100005],tpa[100005],ge[100005],le[100005];

void dfs(int now,int p,int d){
    pa[0][now]=p;
    dep[now]=d;
    for(int i=1;i<21;++i)pa[i][now]=pa[i-1][pa[i-1][now]];
    for(auto &e:G[now])if(e.first!=p){
        tpa[e.first]=e.second;
        if(now!=1 && e.second==tpa[now]){
            ge[e.first]=ge[now]+1;
            le[e.first]=le[now]+1;
        }
        else if(now!=1 && e.second>tpa[now]){
            ge[e.first]=ge[now]+1;
        }
        else if(now!=1){
            le[e.first]=le[now]+1;
        }
        dfs(e.first,now,d+1);
    }
}

bool query(int u,int v){
    if(dep[u]>dep[v])swap(u,v);
    int uu=u,vv=v;
    for(int i=20;i>=0;--i)if((dep[vv]-dep[uu])&(1<<i)){
        vv=pa[i][vv];
    }
    if(uu==vv){
        int diff=dep[v]-dep[u];
        // cout<<"diff: "<<diff<<" , max(le[v],ge[v]): "<<max(le[v],ge[v])<<endl;
        if(max(le[v],ge[v])>=diff-1)return 1;
        return 0;
    }
    else{
        // cout<<"query "<<u<<" "<<v<<endl;
        for(int i=20;i>=0;--i)if(pa[i][uu]!=pa[i][vv]){
            uu=pa[i][uu];
            vv=pa[i][vv];
        }
        int lca=pa[0][uu];
        if(le[v]>=dep[v]-dep[lca]-1 && ge[u]>=dep[u]-dep[lca]-1 && tpa[uu]>=tpa[vv])return 1;
        if(ge[v]>=dep[v]-dep[lca]-1 && le[u]>=dep[u]-dep[lca]-1 && tpa[uu]<=tpa[vv])return 1;
        return 0;
    }
}

int main(){
    int n,q; cin>>n>>q;
    for(int i=1;i<n;++i){
        int u,v,w; cin>>u>>v>>w;
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
    }
    dfs(1,0,1);
    while(q--){
        int u,v; cin>>u>>v;
        cout<<(query(u,v)?"YES":"NO")<<'\n';
    }
}
