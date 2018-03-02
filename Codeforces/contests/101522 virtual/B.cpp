#include<bits/stdc++.h>
using namespace std;

int d[500005];
vector<int> G[500005];

void dfs(int now,int pa,int dep){
    d[now]=dep;
    for(int i:G[now]){
        if(i==pa)continue;
        dfs(i,now,dep+1);
    } 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1,0);
    int dmxp=-1,dmx=0;
    for(int i=1;i<=n;++i){
        if(d[i]>dmx){
            dmx=d[i];
            dmxp=i;
        }
    }
    d[dmxp]=0;
    dfs(dmxp,dmxp,0);
    dmx=0;
    for(int i=1;i<=n;++i)dmx=max(dmx,d[i]);
    int ans=0;
    --dmx;
    while(dmx)dmx>>=1,++ans;
    cout<<ans<<endl;
}
