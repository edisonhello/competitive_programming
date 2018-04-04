#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int,int>> G[100005];

int dfs(int now,int pa,int ww){
    if(now!=pa && G[now].size()==1)return ww;
    int mx=0;
    for(auto i:G[now]){
        if(i.first==pa)continue;
        mx=max(mx,dfs(i.first,now,ww+i.second));
    }
    return mx;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    int tot=0;
    for(int i=1;i<n;++i){
        int u,v,w; cin>>u>>v>>w;
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
        tot+=w;
    }
    tot=tot*2-dfs(1,1,0);
    cout<<tot<<endl;
}
