#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

const ll mod=1000000007;

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}
ll inv(ll x,ll mod){return pw(x,mod-2,mod);}

map<int,int> mp;
int32_t main(){
    int n; cin>>n;
    while(n--){int t; cin>>t; ++mp[t];}
    ll pro=1;
    for(auto &i:mp)pro=pro*(i.second+1)%mod;
    ll ans=1;
    for(auto &i:mp){
        ans=ans*pw(i.first,i.second*(i.second+1)/2%(mod-1)*pro%(mod-1)*inv(i.second+1,mod-1)%(mod-1),mod)%mod;
    }
    cout<<ans<<endl;
}
