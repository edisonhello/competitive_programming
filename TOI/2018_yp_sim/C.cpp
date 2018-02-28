#include<bits/stdc++.h>
using namespace std;

int a[2002],b[2002],dp[2002][2002];

int main(){
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>b[i];
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
        if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    cout<<dp[n][n]<<endl;
}
