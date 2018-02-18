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

ll a[1000006],fac[1000006],ifac[1000006],inv[1000006];
map<ll,int> cnt;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n; 
    fac[0]=1; for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i%mod;
    ifac[n]=pw(fac[n],mod-2); for(int i=n-1;i>=0;--i)ifac[i]=ifac[i+1]*(i+1)%mod;
    for(int i=2;i<=n;++i)inv[i]=ifac[i]*fac[i-1]%mod;
    for(int i=0;i<n;++i)cin>>a[i],++cnt[a[i]];
    sort(a,a+n); int nn=unique(a,a+n)-a;
    ll ans=0; 
    int all=n;
    for(int i=0;i<nn-1;++i){
        int app=cnt[a[i]];
        ans+=app*inv[all]%mod*fac[n]%mod*a[i]%mod;
        all-=app;
    }
    cout<<ans%mod<<endl;
}
