#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

vector<int> G[111];
int x[111],dp[2][111][222],K;

void dfs(int now,int pa){
    dp[0][now][0]=dp[1][now][0]=x[now];
    for(int it=0,i;it<G[now].size();++it){
        i=G[now][it];
        if(i==pa)continue;
        dfs(i,now);
        for(int j=K;j>=1;--j){
            for(int k=0;k<j-1;++k){
                dp[1][now][j]=max(dp[1][now][j],dp[1][now][k]+dp[1][i][j-k-2]);
                dp[0][now][j]=max(dp[0][now][j],dp[0][now][k]+dp[1][i][j-k-2]);
            }
            for(int k=0;k<j;++k){
                dp[0][now][j]=max(dp[0][now][j],dp[1][now][k]+max(dp[0][i][j-k-1],dp[1][i][j-k-1]));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; while(cin>>n>>K){
        for(int i=1;i<=n;++i)cin>>x[i];
        for(int i=1;i<=n;++i)G[i].clear();
        for(int i=1,u,v;i<n;++i){
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        memset(dp,0,sizeof(dp));
        dfs(1,1);
        int ans=0;
        for(int i=0;i<=K;++i)ans=max(ans,max(dp[0][1][i],dp[1][1][i]));
        cout<<ans<<endl;
    }
}
