#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll _(ll base,ll p){
    ll r=1;
    while(p){
        if(p&1)r=r*base%1000000ll;
        base=base*base%1000000ll;
        p>>=1;
    }
    return r;
}

int main(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans=0;
    for(ll i=0;a+i*b<=d;i++){
        ans+=_(a+i*b,c);
        ans%=1000000ll;
    }
    cout<<ans<<'\n';
}
