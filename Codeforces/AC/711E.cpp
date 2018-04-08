#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000003;

ll n,k;


ll pw(ll b,ll n,ll m=mod,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

int main(){
    cin>>n>>k;
    if(n<=62 && k>(1ll<<n))return cout<<"1 1\n",0;
    ll _2n=pw(2,n);
    ll zi=[&](){
        if(k>mod)return 0ll;
        ll rt=1;
        for(ll i=1;i<k;++i){
            rt=rt*(((_2n-i)%mod+mod)%mod)%mod;
        }
        return rt;
    }();
    ll mu=pw(_2n,k-1);
    // cout<<"zi/mu: "<<zi<<"/"<<mu<<endl;
    ll ue=pw(2,[&](){
        ll rt=0;
        ll kk=k-1;
        while(kk){
            rt+=kk/2;
            kk/=2;
        }
        return rt;
    }());
    // cout<<"ue: "<<ue<<endl;
    ll iue=pw(ue,mod-2);
    zi=zi*iue%mod;
    mu=mu*iue%mod;
    zi=(mu-zi+mod)%mod;
    cout<<zi<<" "<<mu<<endl;
}
