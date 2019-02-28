#include<bits/stdc++.h>
using namespace std;

int a[1034],dp[2][1034][1034];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    if(k>n)exit((cout<<0<<endl,0));
    memset(dp,0xc0,sizeof(dp));
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        int cur=i&1,kk=min(i,k);
        // memset(dp[cur],0xc0,(1034*1034)<<2);
        memcpy(dp[cur],dp[cur^1],(1034*1034)<<2);
        /* for(int j=0;j<i;++j){
            for(int z=0;z<kk;++z){
                dp[cur][j][z]=dp[cur^1][j][z];
            }
        } */
        dp[cur][i][1]=max(dp[cur][i][1],0);
        for(int j=0;j<i;++j){
            for(int z=0;z<kk;++z){
                dp[cur][i][z+1]=max(dp[cur][i][z+1],dp[cur^1][j][z]+(a[j]^a[i]));
            }
        }
    }
    int mx=0;
    for(int i=1;i<=n;++i){
        mx=max(dp[n&1][i][k],mx);
    }
    cout<<mx<<endl;
}
