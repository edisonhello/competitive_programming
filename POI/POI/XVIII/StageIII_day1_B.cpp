#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,sz[1000006],bigchild[1000006],mx[1000006];
ll ans[1000006];
vector<int> G[100006];

void dfs(int now,int pa=1){
    sz[now]=1;
    for(int i=0;i<G[now].size();++i){
        if(G[now][i]==pa)continue;
        dfs(G[now][i],now);
        if(sz[G[now][i]]>bigchild[now]){
            bigchild[now]=sz[G[now][i]];
            mx[now]=G[now][i];
        }
        sz[now]+=sz[G[now][i]];
    }
    bigchild[now]=max(bigchild[now],n-sz[now]);
}

void dfs(vector<int> &v,int now,int pa,int dep){
    v.push_back(dep);
    for(int i=0;i<G[now].size();++i){
        if(G[now][i]==pa)continue;
        dfs(v,G[now][i],now,dep+1);
    }
}

vector<vector<int> > dist;
void meow(int now){
    dist.resize(G[now].size());
    int biggestsize=0,biggestnum=-1;
    for(int i=0;i<G[now].size();++i){
        dfs(dist[i],G[now][i],now,1);
        if(dist[i].size()>biggestsize){
            biggestsize=dist[i].size();
            biggestnum=i;
        }
    }
    int mx=0,tot=0;
    for(int i=0;i<G[now].size();++i){
        for(int ii=0;ii<dist[i].size();++ii){
            mx=max(mx,dist[i][ii]);
            tot+=dist[i][ii];
        }
    }
    if(biggestsize>n-1-biggestsize){
        mx=0;
        for(int i=0;i<biggestsize;++i){
            mx=max(mx,dist[biggestnum][i]);
        }
    }
    ans[now]=tot*2-mx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        G[u].push_back(v), G[v].push_back(u);
    }
    dfs(1);
    for(int i=1;i<=n;++i){
        if(bigchild[i]>n-1-bigchild[i]+1)continue;
        meow(i);
    }
    for(int i=1;i<=n;++i){
        if(bigchild[i]>n-1-bigchild[i]+1)cout<<-1<<endl;
        else cout<<ans[i]<<endl;
    }
}
