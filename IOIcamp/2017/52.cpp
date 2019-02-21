#include<iostream>
using namespace std;
#define ll long long

ll mp(ll b,ll n,ll m){
    if(!b)return 0;
    ll a=1;
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m;
        n>>=1;
    }
    return a;
}

bool isP(ll n){
    for(ll i=2;i*i<=n;++i){
        if(n%i==0)return 0;
    }
    return 1;
}
ll phi(ll n){
    ll ans=n;
    for(ll i=2;i<=n;++i){
        if(n%i)continue;
        if(!isP(i))continue;
        // cout<<i<<endl;
        ans=ans/i*(i-1);
        while(n%i==0)n/=i;
    }
    return ans;
}

int main(){
    // cout<<phi(77);
    int ts;cin>>ts;while(ts--){
        ll a0,a1,a2,a3,m,n,o;
        cin>>a0>>a1>>a2>>a3>>m;
        n=phi(m);
        o=phi(n);
        a2=mp(a2%o,a3,o);
        a1=mp(a1%n,a2,n);
        a0=mp(a0%m,a1,m);
        cout<<a0<<endl;
    }
}
