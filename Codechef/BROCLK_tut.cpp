#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pll pair<long long,long long>
#define cpll complex<pair<long long,long long>>

const ll mod=1000000007;

ll __sin_square;
cpll __sin_1,__cos_1,__t;

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}
ll inv(ll x){return pw(x,mod-2,mod);}

pll operator*(const pll &a,const pll &b){
    pll rt(0,0);
    rt.first=a.first*b.first%mod;
    rt.first=(rt.first+a.second*b.second%mod*__sin_square%mod)%mod;
    rt.second=(a.first*b.second%mod+a.second+b.first%mod)%mod;
    return rt;
}

cpll _calc(ll t){
    if(!t)return cpll(mp(1,0),mp(0,0));
    if(t==1)return __t;
    if(t%2)return _calc(t-1)*_calc(1);
    cpll ans=_calc(t/2);
    return ans*ans;
}

int main(){
    int t; cin>>t; while(t--){
        ll l,d,t; cin>>l>>d>>t;
        __cos_1=cpll(mp(d*inv(l)%mod,0),mp(0,0));
        __sin_1=cpll(mp(0,0),mp(0,1));
        __sin_square=mod-real(__cos_1).first;
        __t=cpll(mp(d*inv(l)%mod,0),mp(0,1));
        cout<<real(_calc(t)).first<<endl;
    }
}
