#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;

ll dp[2][410009],pre[2][410009];

int main(){
    int a,b,k,t; cin>>a>>b>>k>>t;
    dp[0][a-b+205000]=1;
    for(int i=4333;i<=410000;++i)pre[0][i]=pre[0][i-1]+dp[0][i];
    for(int i=1;i<=t;++i){
        ll tot=0;
        for(int j=2500-k*2;j<=2500+k*2;++j){
            tot=(tot+dp[i&1^1][j]*(abs(j-2500)+1)%mod)%mod;
        }
        for(int j=2500;j<=408000;++j){
            dp[i&1][j]=tot;
            pre[i&1][j]=(pre[i&1][j-1]+dp[i&1][j])%mod;
            tot=((tot-(pre[i&1^1][j]-pre[i&1^1][j-2*k-1])+(pre[i&1^1][j+2*k+1]-pre[i&1^1][j]))%mod+mod)%mod;
        }
        for(int j=408001;j<=410000;++j)pre[i&1][j]=pre[i&1][j-1];
    }
    ll ans=0;
    for(int i=205001;i<=410000;++i){
        ans+=dp[t&1][i];
        // if(abs(i-202000)<100)cout<<i<<" "<<dp[t&1][i]<<" "<<ans%mod<<endl;
    }
    // cout<<ans<<endl;
    cout<<ans%mod<<endl;
}
