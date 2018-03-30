#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;

int a[2222],dp[2222][2222];

#define up(a,b) (a=a+b, (a>=mod?a-=mod:0))

int main(){
    int n,h; cin>>n>>h;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]>h)return cout<<0<<endl,0;
    }
    dp[0][0]=1;
    for(int i=1;i<=n;++i){
        up(dp[i][h-a[i]],dp[i-1][h-a[i]]);
        up(dp[i][h-a[i]-1],dp[i-1][h-a[i]]*1ll*(h-a[i])%mod);
        up(dp[i][h-a[i]],dp[i-1][h-a[i]-1]);
        up(dp[i][h-a[i]-1],dp[i-1][h-a[i]-1]*1ll*(h-a[i]-1)%mod);
        up(dp[i][h-a[i]-1],dp[i-1][h-a[i]-1]);
    }
    cout<<dp[n][0]<<endl;
}
