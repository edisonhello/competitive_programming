#include<bits/stdc++.h>
using namespace std;

// #include"/home/edison/Coding/cpp/template/debug.cpp"
#define PDE(...) ;

vector<int> G[1231];
int dp[3][1222],w[1232];
// 0: for pa
// 1: self
// 2: for son


void dfs(int now){
    if(G[now].empty()){
        dp[0][now]=0;
        dp[1][now]=w[now];
        dp[2][now]=1<<29;
    }
    dp[1][now]=w[now];
    bool cho=0;
    for(int i:G[now]){
        dfs(i);
        dp[1][now]+=min(dp[0][i],min(dp[1][i],dp[2][i]));
        dp[0][now]+=min(dp[2][i],dp[1][i]);
        dp[2][now]+=min(dp[2][i],dp[1][i]);
        if(dp[1][i]<=dp[2][i])cho=1;
    }
    bool sonleaf=0;
    for(int i:G[now])if(G[i].empty())sonleaf=1;
    if(!cho){
        int mn=1<<30;
        for(int i:G[now]){
            mn=min(dp[2][now]-dp[2][i]+dp[1][i],mn);
        }
        dp[2][now]=mn;
    }
    PDE(now,dp[0][now],dp[1][now],dp[2][now]);
}

int main(){
    int ts; cin>>ts; while(ts--){
        for(int i=0;i<1231;++i)G[i].clear();
        memset(dp,0,sizeof(dp));
        int n; cin>>n>>w[1];
        for(int i=2;i<=n;++i){
            int p; cin>>p>>w[i];
            G[p].push_back(i);
            // PDE(p,i);
        }
        dfs(1);
        if(n>1)cout<<min(dp[2][1],dp[1][1])<<endl;
        else cout<<w[1]<<endl;
    }
}
