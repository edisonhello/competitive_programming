#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

#ifndef WEAK
#define endl '\n'
#endif


int n,djs[100005],dia[100005],tofar[100005],dis[100005];
vector<int> G[100005],intree,treemem[100005],alds[100005];
vector<ll> dsp[100005];

ld solve(int u,int v){
    if(treemem[v].size()>treemem[u].size())swap(u,v);
    // cout<<"u tree: "<<u<<" , v tree: "<<v<<endl;
    int sgmax=max(dia[u],dia[v]);
    ld all=0;
    for(int d:alds[v]){
        int ptr=upper_bound(alds[u].begin(),alds[u].end(),sgmax-d-1)-alds[u].begin()-1;
        // cout<<"d: "<<d<<" , ptr: "<<ptr<<endl;
        if(ptr>=0)all+=1ll*(ptr+1)*sgmax;
        all+=dsp[u].back()-(ptr>=0?dsp[u][ptr]:0)+1ll*(alds[u].size()-ptr-1)*(d+1);
    }
    return all/treemem[u].size()/treemem[v].size();
}

void dfs1(int now,int pa){
    intree.push_back(now);
    for(int i:G[now]){
        if(i==pa)continue;
        dis[i]=dis[now]+1;
        dfs1(i,now);
    }
}
void dfs2(int now,int pa){
    for(int i:G[now]){
        if(i==pa)continue;
        dis[i]=dis[now]+1;
        dfs2(i,now);
    }
}

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,q; cin>>n>>m>>q;
    for(int i=1;i<=n;++i)djs[i]=i;
    while(m--){
        int u,v; cin>>u>>v;
        djs[F(u)]=F(v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;++i){
        if(i!=F(i))continue;
        intree.clear();
        dfs1(i,i);
        int far=*max_element(intree.begin(),intree.end(),[&](const int &a,const int &b){return dis[a]<dis[b];});
        dis[far]=0;
        intree.clear();
        dfs1(far,far);
        int far2=*max_element(intree.begin(),intree.end(),[&](const int &a,const int &b){return dis[a]<dis[b];});
        for(int i:intree)tofar[i]=dis[i];
        dis[far2]=0;
        dfs2(far2,far2);
        for(int i:intree)tofar[i]=max(tofar[i],dis[i]);
        dia[i]=dis[far];
        treemem[i]=intree;
        for(int j:treemem[i])alds[i].push_back(tofar[j]);
        sort(alds[i].begin(),alds[i].end());
        // dspre[i].push_back(alds[i][0]);
        for(int j:alds[i]){
            dsp[i].push_back(j+(dsp[i].size()?dsp[i].back():0));
        }
    }
    map<pair<int,int>,long double> rec;
    while(q--){
        int u,v; cin>>u>>v;
        u=F(u), v=F(v);
        if(u==v){
            cout<<-1<<endl;
            continue;
        }
        else{
            if(v<u)swap(u,v);
            auto it=rec.find(make_pair(u,v));
            cout<<fixed<<setprecision(12);
            if(it!=rec.end()){
                cout<<it->second<<endl;
                continue;
            }
            else{
                cout<<(rec[make_pair(u,v)]=solve(u,v))<<endl;
            }
        }
    }
}
