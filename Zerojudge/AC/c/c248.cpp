#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;
ll fac[(1<<21)+5],ifac[(1<<21)+5];

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

int main(){
    // cout<<pw(3,mod-2,mod)<<endl;
    ios_base::sync_with_stdio(0); cin.tie(0);
    fac[0]=1;
    for(int i=1;i<(1<<21)+5;++i){
        fac[i]=fac[i-1]*i%mod;
    }
    ifac[(1<<21)+4]=pw(fac[(1<<21)+4],mod-2,mod);
    for(int i=(1<<21)+3;i>=0;--i){
        ifac[i]=ifac[i+1]*(i+1)%mod;
        // if(i<10)cout<<ifac[i]<<endl;
    }
    int ts; cin>>ts; while(ts--){
        int a; cin>>a;
        cout<<fac[2*a]*ifac[a]%mod*ifac[a+1]%mod<<'\n';
    }
}
