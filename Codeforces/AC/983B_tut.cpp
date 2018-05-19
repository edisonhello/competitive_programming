#include<bits/stdc++.h>
using namespace std;

int n,dp[5005][5005],a[5005];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)dp[1][i]=a[i];
    for(int i=2;i<=n;++i){
        for(int j=1;j<=n+1-i;++j){
            dp[i][j]=dp[i-1][j]^dp[i-1][j+1];
        }
    }
    for(int i=2;i<=n;++i){
        for(int j=1;j<=n+i-1;++j){
            dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i-1][j+1]));
        }
    }
    int q; cin>>q; while(q--){
        int l,r; cin>>l>>r;
        cout<<dp[r-l+1][l]<<'\n';
    }
}
