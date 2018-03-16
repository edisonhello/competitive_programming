#include<bits/stdc++.h>
using namespace std;

bitset<100005> ans;
int n,djs[100005],tin[100005],tout[100005],dfstimer; 
vector<int> root,specG[100005],partG[100005];
vector<pair<int,int>> Q[100005];

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}

void dfs1(int now){
    tin[now]=++dfstimer;
    for(int i:specG[now])dfs1(i);
    tout[now]=++dfstimer;
}

set<int>* go(int now,set<int> *up){
    set<int> *all=new set<int>();
    all->insert(now);
    for(int i:specG[now]){
        set<int> *rt=go(i,up);
        if(rt->size()>all->size())swap(all,rt);
        for(int i:(*rt))all->insert(i);
        delete rt;
    }
    for(auto p:Q[now])ans[p.second]=(F(now)==now && up->find(p.first)!=up->end());
    if(F(now)==now)for(int i:(*all))up->insert(i);
    for(int i:partG[now])go(i,(F(now)==now?up:all));
    if(F(now)==now)for(int i:(*all))up->erase(i);
    return all;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        djs[i]=i;
        int type,parent; cin>>parent>>type;
        if(type==-1)root.push_back(i);
        else if(!type)specG[parent].push_back(i),djs[i]=F(parent);
        else partG[parent].push_back(i);
    }
    for(int i=1;i<=n;++i)if(djs[i]==i)dfs1(i);
    int q; cin>>q; for(int i=0;i<q;++i){
        int type,u,v; cin>>type>>u>>v;
        if(type==1)ans[i]=(F(u)==F(v) && tin[u]<tin[v] && tout[v]<tout[u]);
        else Q[v].emplace_back(u,i);
    }
    for(int rt:root)go(rt,new set<int>());
    for(int i=0;i<q;++i)cout<<(ans[i]?"YES\n":"NO\n");
}
