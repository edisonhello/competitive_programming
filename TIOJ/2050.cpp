#include<bits/stdc++.h>
using namespace std;

set<int> G[2005];
int djs[2005],low[2005],in[2005],sz[2005],ang,dt;
bitset<2005> v,tG[2005];

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}

void dfs(int now,int pa){
    // cout<<"dfs: "<<now<<endl;
    low[now]=in[now]=++dt;
    int ch=0,ag=0;
    for(int i:G[now]){
        if(i==pa)continue;
        if(in[i]){
            low[now]=min(low[now],in[i]);
        }
        else{
            dfs(i,now);
            low[now]=min(low[now],low[i]);
            ++ch;
            if(low[i]>=in[now])ag=1;
        }
    }
    if(ag){
        if(pa==-1){
            if(ch>1){
                ++ang;
                // cout<<now<<" , ++"<<endl;
            }
        }
        else if(ch){
            ++ang;
            // cout<<now<<" , ++"<<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)djs[i]=i;
    while(m--){
        int u,v; cin>>u>>v;
        tG[u][v]=tG[v][u]=1;
        djs[F(u)]=F(v);
    }
    for(int i=2;i<=n;++i)assert(F(i-1)==F(i));
    for(int z=0;z<3;++z){
        v.reset();
        for(int i=1;i<=n;++i){
            if(!v[i]){
                queue<int> q; q.push(i); v[i]=1;
                while(q.size()){
                    int now=q.front(); q.pop();
                    for(int i=1;i<=n;++i){
                        if(v[i])continue;
                        if(!tG[now][i])continue;
                        v[i]=1;
                        tG[now][i]=tG[i][now]=0;
                        G[now].insert(i);
                        G[i].insert(now);
                        q.push(i);
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        vector<int> clrs;
        for(int j:G[i]){
            clrs.push_back(j);
        }
        for(int j:clrs){
            G[i].erase(j);
            G[j].erase(i);
        }
        for(int i=1;i<=n;++i)djs[i]=i,low[i]=in[i]=sz[i]=0;
        int blk=n-1;
        for(int i=1;i<=n;++i){
            for(int j:G[i]){
                if(F(i)==F(j))continue;
                --blk;
                djs[F(i)]=F(j);
            }
        }
        for(int j=1;j<=n;++j){
            if(j==i)continue;
            ++sz[F(j)];
        }
        ang=0;
        // cout<<"i: "<<i<<" , blk: "<<blk<<endl;
        if(blk==1){
            dfs(i==1?2:1,-1);
        }
        else if(blk>=3){
            ang=n-1;
        }
        else{
            bool one=0;
            for(int j=1;j<=n;++j){
                if(j==i)continue;
                if(sz[j]==1)one=1;
            }
            // cout<<"one: "<<one<<" , "<<F(4)<<endl;
            ang=n-1-one;
        }
        ans+=ang;
        for(int j:clrs){
            G[i].insert(j);
            G[j].insert(i);
        }
        // cout<<i<<" : "<<ang<<endl;
    }
    cout<<ans/2<<endl;
}
