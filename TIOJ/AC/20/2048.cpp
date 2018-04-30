#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[1000006],dp[4][1000006];
// dp[1]= take not stop (max cont suf)
// dp[0]= take and stop (stop after 1)
// dp[2]= start after 0 (only come from another 0 or 2, not 1)

int main(){
    int n; cin>>n; 
    for(int i=1;i<=n;++i)cin>>a[i];
    memset(dp,0xb0,sizeof(dp));
    for(int i=1;i<=n;++i){
        dp[1][i]=max({a[i],dp[1][i-1]+a[i]});
        dp[0][i]=max({dp[1][i-1],dp[0][i-1]});
        dp[2][i]=max({dp[0][i-1]+a[i],dp[2][i-1]+a[i],dp[2][i-1]});
    }
    cout<<dp[2][n]<<endl;
}
