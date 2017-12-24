#include<bits/stdc++.h>
using namespace std;

int a[2000006],dp[102][50005];
int main(){
    int n,k; cin>>n>>k; a[0]=1000000002;
    for(int i=1;i<=n;++i)cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;++i){
        int rdmin=1000000002;
        for(int j=i-1;j>0;--j){
            dp[1][i]=max(dp[1][i],dp[0][j]+max(0,a[i]-rdmin));
            ans=max(ans,dp[1][i]);
            rdmin=min(rdmin,a[j]);
        }
    }
    cout<<ans<<endl;
}
