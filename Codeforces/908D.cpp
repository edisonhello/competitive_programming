#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;

ll pw(ll b,ll n,ll m=mod,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

ll inv(ll x){return pw(x,mod-2,mod);}

ll dp[2231][1231];

int main(){
    int k; cin>>k;
    int ipa,ipb; cin>>ipa>>ipb;
    ll __inv=inv(ipa+ipb);
    ll a=__inv*ipa%mod,b=__inv*ipb%mod;
    cout<<"inv,a,b: "<<__inv<<" "<<a<<" "<<b<<endl;
    dp[0][0]=1;
    // for(int i=1;i<=k;++i)dp[0][i]=dp[0][i-1]*a%mod;
    for(int i=0;i<=k;++i){
        for(int j=0;j<=k;++j){
            // dp[i][j]=dp[i][j-1]*a%mod+dp[i-j][j]*b%mod;
            dp[i][j+1]=(dp[i][j+1]+dp[i][j]*a%mod)%mod;
            dp[i+j][j]=(dp[i+j][j]+dp[i][j]*b%mod)%mod;
        }
    }
    cout<<dp[0][1]<<endl;
    ll ans=0;
    for(int i=0;i<k;++i){
        int j=k-i;
        ans=(ans+dp[i][j])%mod;
    }
    cout<<ans<<endl;
    ans=ans*(k*b%mod+b*a%mod*inv(1-a+mod)%mod)%mod*inv(1-a+mod)%mod;
    cout<<ans<<endl;
}
