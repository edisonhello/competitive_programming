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
ll inv(ll x){return pw(x,mod-2);}

ll fac[200005],ifac[200005];

int main(){
    fac[0]=1;
    for(int i=1;i<200005;++i)fac[i]=fac[i-1]*i%mod;
    ifac[200004]=inv(fac[200004]);
    for(int i=200003;i>=0;--i)ifac[i]=ifac[i+1]*(i+1)%mod;
    ll ans=0;
    ll n,m; cin>>n>>m; --n, --m;
    for(int i=1;i<=min(n,m);++i){
        ll nn=n-i,mm=m-i;
        ll add=fac[nn+i-1]*ifac[nn]%mod*ifac[i-1]%mod*fac[mm+i-1]%mod*ifac[mm]%mod*ifac[i-1]%mod;
        ans+=add;
    }
    cout<<ans%mod<<endl;
}
