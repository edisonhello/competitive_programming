#include<bits/stdc++.h>
using namespace std;

bitset<100005> style;
int indeg[100005];
vector<int> G[100005];
int dp[100005];
int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i){
        int t; cin>>t;
        style[i]=t;
    }
    while(m--){
        int u,v; cin>>u>>v; ++u, ++v;
        ++indeg[v];
        G[u].push_back(v);
    }
    style[0]=0;
    for(int i=1;i<=n;++i)if(!indeg[i])++indeg[i],G[0].push_back(i);
    queue<int> q; q.push(0);
    int ans=0;
    while(q.size()){
        int now=q.front(); q.pop();
        for(int i:G[now]){
            ans=max(ans,dp[i]=max(dp[i],dp[now]+(!style[now] && style[i])));
            --indeg[i];
            if(!indeg[i])q.push(i);
        }
    }
    cout<<ans<<endl;
}
