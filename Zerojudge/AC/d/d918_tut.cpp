#include<bits/stdc++.h>
using namespace std;

int a[3553],dp[3553];
int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    while(m--){
        int E,ans=0; cin>>E;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;++i){
            int cnt=0;
            for(int j=i+1;j<=n;++j){
                if(a[j]>=a[i]-E && a[i]>a[j])++cnt;
                else if(a[j]>=a[i])dp[j]=max(dp[j],dp[i]+cnt+1);
            }
            ans=max(ans,dp[i]+cnt);
            // cout<<i<<" "<<dp[i]<<endl;
        }
        cout<<ans+1<<" ";
    } cout<<endl;
}
