#include<bits/stdc++.h>
using namespace std;

vector<int> G[5005],iG[5005],tp;
set<int> cG[5005];
int bel[5005],ind[5005];
bitset<5005> v;

void dfs1(int now){
    v[now]=1;
    for(int i:G[now]){
        if(!v[i])dfs1(i);
    }
    tp.push_back(now);
}
void dfs2(int now,int ccc){
    v[now]=1;
    bel[now]=ccc;
    for(int i:iG[now]){
        if(!v[i])dfs2(i,ccc);
    }
}
void dfs3(int now){
    v[now]=1;
    for(int i:cG[now]){
        if(!v[i])dfs3(i);
    }
}

int main(){
    int n,m,s; cin>>n>>m>>s;
    while(m--){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        iG[v].push_back(u);
    }
    for(int i=1;i<=n;++i){
        if(!v[i])dfs1(i);
    }
    v.reset();
    int cc=0;
    for(int i=n-1;i>=0;--i){
        if(!v[tp[i]])dfs2(tp[i],++cc);
    }
    for(int i=1;i<=n;++i){
        for(int j:G[i]){
            if(bel[i]!=bel[j])cG[bel[i]].insert(bel[j]);
        }
    }
    v.reset();
    dfs3(bel[s]);
    for(int i=1;i<=cc;++i){
        for(int j:cG[i]){
            ++ind[j];
        }
    }
    int ans=0;
    for(int i=1;i<=cc;++i){
        if(!v[i] && !ind[i])++ans;
    }
    cout<<ans<<endl;
}
