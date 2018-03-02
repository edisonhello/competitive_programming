#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;

const ll p1=47017,p2=26539,p3=36529;

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

ll inv(ll x,ll p){
    return pw(x,p-2,p);
}
ll CRT(ll v1,ll p1,ll v2,ll p2){
    return (v1*(p2%p1)%mod*inv(p2%p1,p1)%mod+v2*(p1%p2)%mod*inv(p1%p2,p2)%mod)%mod;
}

ll fac(ll n,ll p){
    ll rt=1;
    for(int i=2;i<=n;++i)rt=rt*i%p;
    return rt;
}
ll ifac(ll n,ll p){
    return inv(fac(n,p),p);
}
ll CC(ll n,ll m,ll p){
    if(m>n)return 0;
    return fac(n,p)*ifac(m,p)%p*ifac(n-m,p)%p;
}

ll C(ll n,ll m){
    // return fac(n,mod)*ifac(m,mod)%mod*ifac(n-m,mod)%mod;
    return CRT(CC(n/p1,m/p1,p1)*CC(n%p1,m%p1,p1)%p1,p1,CC(n/p2,m/p2,p2)*CC(n%p2,m%p2,p2)%p2,p2);
}

int main(){
    ll n,m; cin>>n>>m;
    // cout<<CC(7/p1,5/p1,p1)*CC(7%p1,5%p1,p1)<<endl;
    cout<<CRT(4,7,1,3)<<endl;
    cout<<((C(n+m,n)-C(n+m,n+1))%mod+mod)%mod<<endl;
}
