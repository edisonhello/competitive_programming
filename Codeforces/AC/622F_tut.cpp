#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;

ll pw(ll b,ll n,ll m=mod,ll a=1){
    b=(b%m+m)%m;
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return (a%m+m)%m;
}
ll inv(ll x){return pw((x%mod+mod)%mod,mod-2,mod);}

ll val[1000006];

int main(){
    ll n,k; cin>>n>>k;
    if(n<=1000006){
        ll ans=0;
        for(int i=1;i<=n;++i)ans+=pw(i,k);
        exit((cout<<ans%mod<<endl,0));
    }
    for(int i=1;i<k+5;++i){
        val[i]=pw(i,k);
        val[i]+=val[i-1];
        val[i]%=mod;
        // cout<<i<<" val "<<val[i]<<endl;
    }
    ll zi=1,mu=1;
    for(int i=2;i<=k+2;++i){
        zi=(zi*(n-i))%mod;
        mu=(mu*(1-i)%mod+mod)%mod;
    }
    ll ans=0;
    for(int i=1;i<=k+2;++i){
        // cout<<i<<" "<<zi<<" "<<mu<<endl;
        ans+=val[i]*zi%mod*inv(mu)%mod;
        zi=zi*inv(n-(i+1))%mod*(n-i)%mod;
        mu=mu*inv(1-(k+3-i))%mod*i%mod;
    }
    cout<<ans%mod<<endl;
}
