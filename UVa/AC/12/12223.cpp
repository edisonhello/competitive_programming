#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<int,int>> G[50005];
ll wall[50005],sz[50005];
int got[50005];
ll best;
vector<int> ans;

void pre(int now,int pa){
    for(auto i:G[now]){
        if(i.first==pa)continue;
        pre(i.first,now);
        sz[now]+=sz[i.first];
        wall[now]+=wall[i.first]+i.second*sz[i.first];
    }
    sz[now]+=got[now];
    // cout<<"pre: "<<now<<" "<<sz[now]<<" "<<wall[now]<<endl;
}
void dfs(int now,int pa,ll upt,int upsz){
    // cout<<"dfs: "<<now<<" "<<upt<<" "<<upsz<<endl;
    if(upt+wall[now]<best){
        best=upt+wall[now];
        ans.clear();
        ans.push_back(now);
    }
    else if(upt+wall[now]==best)ans.push_back(now);
    for(auto i:G[now]){
        if(i.first==pa)continue;
        dfs(i.first,now,upt+i.second*1ll*(upsz+sz[now]-sz[i.first])+wall[now]-i.second*sz[i.first]-wall[i.first],upsz+sz[now]-sz[i.first]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    int ts; cin>>ts; while(ts--){
        memset(wall,0,sizeof(wall));
        memset(sz,0,sizeof(sz));
        memset(got,0,sizeof(got));

        int n; cin>>n;
        for(int i=1;i<=n;++i)G[i].clear();

        for(int i=1;i<n;++i){
            int u,v,w; cin>>u>>v>>w;
            G[u].emplace_back(v,w);
            G[v].emplace_back(u,w);
        }
        int viu; cin>>viu;
        while(viu--){
            int p,x; cin>>p>>x;
            got[p]=x;
        }
        best=(1ll<<60);
        pre(1,1);
        dfs(1,1,0,0);
        cout<<best*2<<endl;
        sort(ans.begin(),ans.end());
        for(int i:ans)cout<<i<<" \n"[i==ans.back()];
    }
}
