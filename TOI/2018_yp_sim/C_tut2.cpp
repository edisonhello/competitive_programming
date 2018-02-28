#include<bits/stdc++.h>
using namespace std;

int a[5][2002],dp[2002],G[2002][2002];
int n,k;

int dfs(int now){
    if(dp[now])return dp[now];
    for(int i=1;i<=n;++i){
        if(G[i][now]==k){
            dp[now]=max(dp[now],dfs(i));
        }
    }
    return dp[now]=dp[now]+1;
}


int main(){
    cin>>n>>k;
    for(int i=0;i<k;++i)for(int j=1;j<=n;++j){
        cin>>a[i][j];
    }
    for(int i=0;i<k;++i){
        for(int j=1;j<=n;++j){
            for(int z=j+1;z<=n;++z){
                ++G[a[i][j]][a[i][z]];
            }
        }
    }
    int mx=0;
    for(int i=1;i<=n;++i){
        mx=max(mx,dfs(i));
    }
    cout<<mx<<endl;
}
// AC
