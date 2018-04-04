#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;
ll f,w,h,fac[200005],ifac[200005];

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}
ll inv(ll x){return pw(x,mod-2,mod);}


ll C(ll a,ll b){
    return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}
ll get(ll x,ll p){
    if(x==0 && p==0)return 1;
    return C(x+p-1,x);
}
ll get(ll f,ll fp,ll w,ll wp){
    if(f<0 || w<0)return 0;
    return get(f,fp)*get(w,wp)%mod;
}
pair<ll,ll> calc(int fp,int wp){
    // if(wp*h>w || fp>f)return {0,0};
    return make_pair(get(f-fp,fp,w-wp,wp),get(f-fp,fp,w-wp*(h+1),wp));
}

int main(){
    fac[0]=1;
    for(int i=1;i<200005;++i)fac[i]=fac[i-1]*i%mod;
    ifac[200004]=inv(fac[200004]);
    for(int i=200003;i>=0;--i)ifac[i]=ifac[i+1]*(i+1)%mod;
    cin>>f>>w>>h;
    ll tot=0,lik=0;
    for(int fp=!!f;fp<=f;++fp){
        for(int wp=max((int)!!w,fp-1);wp<=min(fp+1,(int)w);++wp){
            auto rt=calc(fp,wp);
            if(fp==wp)rt.first<<=1,rt.second<<=1;
            tot+=rt.first;
            lik+=rt.second;
            // cout<<"fp wp rt: "<<fp<<" "<<wp<<" "<<rt.first<<" "<<rt.second<<endl;
        }
    }
    // cout<<lik<<" "<<tot<<endl;
    cout<<lik%mod*inv(tot%mod)%mod<<endl;
}
