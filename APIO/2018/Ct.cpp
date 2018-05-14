#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll tot;
vector<int> oG[100005],bel[100005],G[100005];

int n,sz[100005],cnt[100005],djs[100005];

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}

void dfs(int now,int pa,int cnt){
    sz[now]=1;
    for(int i:G[now]){
        if(i==pa)continue;
        dfs(i,now,cnt);
        sz[now]+=sz[i];
    }
    for(int i:G[now]){
        if(i==pa)continue;
        tot+=1ll*sz[i]*(cnt-sz[i]-1);
    }
    tot+=1ll*(cnt-sz[now])*(sz[now]-1);
}

int main(){
    int m; cin>>n>>m;
//    if(m!=n-1)exit(1);
    for(int i=1;i<=n;++i)djs[i]=i;
    for(int i=0;i<m;++i){
        int u,v; cin>>u>>v;
        oG[u].push_back(v);
        oG[v].push_back(u);
        djs[F(u)]=F(v);
    }
    for(int i=1;i<=n;++i){
        ++cnt[F(i)];
        bel[F(i)].push_back(i);
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int k=1;k<=n;++k){
                if(i==j || i==k || j==k)continue;

            }
        }
    }
//    dfs(1);
    cout<<tot<<endl;
}
