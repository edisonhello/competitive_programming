#include<bits/stdc++.h>
using namespace std;

// #include"/home/edison/Coding/cpp/template/debug.cpp"
#define PDE(...) ;

vector<int> G[1231];
int dp[2][1222],w[1232];


void dfs(int now){
    dp[1][now]=w[now];
    for(int i:G[now]){
        dfs(i);
        dp[1][now]+=dp[0][i];
        dp[0][now]+=max(dp[0][i],dp[1][i]);
    }
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
        if(n>1)cout<<max(dp[0][1],dp[1][1])<<endl;
        else cout<<w[1]<<endl;
    }
}
