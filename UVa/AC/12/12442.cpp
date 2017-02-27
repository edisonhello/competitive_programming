#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;

bool v[50005];
int dp[50005],d[50005];
vector<int> G[50005];

int ringside,inring;
int dfs(int now,int dep){
    // cout<<"dfs in "<<now<<" "<<dep<<endl;
    if(v[now]){
        inring=1;
        ringside=now;
        return dep-d[now];
    }
    v[now]=1;
    d[now]=dep;
    for(int i:G[now]){
        dp[now]=max(dp[now],dfs(i,dep+1)+(inring?0:1));
    }
    v[now]=0;
    if(now==ringside)inring=0;
    return dp[now];
}

int main(){
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    ios_base::sync_with_stdio(0);
    int ts;cin>>ts;for(int cs=1;cs<=ts;++cs){
        int n;cin>>n;
        for(int i=1;i<=n;++i){
            // G[0].push_back(i);
            G[i].clear();
            dp[i]=0;
            v[i]=0;
        }
        for(int i=1,u,v;i<=n;++i){
            cin>>u>>v;
            G[u].push_back(v);
        }
        int mx=0;
        // for(int i=1;i<=n;++i){dfs(i,0);if(i!=ringside)dp[i]=dp[G[i][0]]+1;}
        for(int i=1;i<=n;++i){
            if(!v[i] && !dp[i]){
                // cout<<"dfs start from "<<i<<endl;
                ringside=-1,inring=0;
                dfs(i,0);
            }
            mx=max(mx,dp[i]);
        }
        // for(int i=1;i<=n;++i)cout<<dp[i]<<" ";cout<<endl;
        for(int i=1;i<=n;++i)if(dp[i]==mx){
            cout<<"Case "<<cs<<": "<<i<<endl;
            break;
        }
    }
}
