#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;

map<ll,ll> sinrec,cosrec,invrec;

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

ll inv(ll x){
    ll &xx=invrec[x];
    if(xx)return xx;
    else return xx=pw(x,mod-2,mod);
}

ll getval(ll a,ll b){
    ll g=__gcd(a,b);
    a/=g,b/=g;
    return a*inv(b);
}

ll cos(

int main(){
    int t; cin>>t; while(t--){
        int d,l; cin>>d>>l;
        ll t; cin>>t;
        sinrec.clear(); cosrec.clear(); cosrec[1]=getval(d,l);
        cos(t);
    }
}
