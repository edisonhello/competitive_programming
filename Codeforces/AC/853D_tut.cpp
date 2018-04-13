#include<bits/stdc++.h>
using namespace std;

int dp[300005][333];
int a[300005];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],a[i]/=100;
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    int ans=INT_MAX;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=300;++j){
            if(dp[i-1][j]==0x3f3f3f3f)continue;
            int to=min(300,j+a[i]/10);
            dp[i][to]=min(dp[i][to],dp[i-1][j]+a[i]);
            int us=min(j,a[i]);
            dp[i][j-us]=min(dp[i][j-us],dp[i-1][j]+a[i]-us);
        }
    }
    for(int j=0;j<=300;++j)ans=min(ans,dp[n][j]);
    cout<<ans*100;
}
