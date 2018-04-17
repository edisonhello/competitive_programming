#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> G[155];
int dp[155][155],sz[155];

void dfs(int now,int pa){
    sz[now]=1;
    // dp[now][0]=1;
    dp[now][1]=0;
    for(int it=0,i;it<G[now].size();++it){
        i=G[now][it];
        if(i==pa)continue;
        dfs(i,now);
        // ++dp[now][1];
        for(int j=154;j>=0;--j){
            ++dp[now][j];
            for(int kz=1;kz<j;++kz){
                dp[now][j]=min(dp[now][j],dp[i][kz]+dp[now][j-kz]);
            }
        }
    }
    // for(int j=0;j<=11;++j)cout<<"dp["<<now<<"]["<<j<<"]="<<dp[now][j]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,p; cin>>n>>p;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans=1<<30;
    memset(dp,0x3f,sizeof(dp));
    memset(sz,0,sizeof(sz));
    dfs(1,1);
    for(int i=1;i<=n;++i){
        ans=min(ans,dp[i][p]+(i!=1));
    }
    cout<<ans<<endl;
}
