#include<bits/stdc++.h>
using namespace std;

bitset<300005> v;
vector<int> G[300005],work;
int djs[300005],dia[300005],dis[300005];

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}

void dfs(int now,int pa,int add=1){
    if(add)work.push_back(now);
    for(int i:G[now]){
        if(i==pa)continue;
        dis[i]=dis[now]+1;
        dfs(i,now,add);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,q; cin>>n>>m>>q;
    for(int i=1;i<=n;++i)djs[i]=i;
    while(m--){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        djs[F(u)]=F(v);
    }
    for(int i=1;i<=n;++i)if(!v[i]){
        work.clear();
        dfs(i,i);
        int mx=0,fr=-1;
        for(int i:work)mx=max(mx,dis[i]);
        for(int i:work)if(mx==dis[i])fr=i;
        dis[fr]=0;
        dfs(fr,fr,0);
        mx=0;
        for(int i:work)mx=max(mx,dis[i]);
        dia[F(i)]=mx;
        for(int i:work)v[i]=1;
    }
    while(q--){
        int c; cin>>c;
        if(c==1){
            int x; cin>>x;
            cout<<dia[F(x)]<<'\n';
        }
        else{
            int x,y; cin>>x>>y;
            x=F(x); y=F(y);
            if(x==y)continue;
            int dx=dia[x],dy=dia[y];
            djs[y]=x;
            dia[x]=max(max(dx,dy),(dx+1)/2+(dy+1)/2+1);
        }
    }
}
