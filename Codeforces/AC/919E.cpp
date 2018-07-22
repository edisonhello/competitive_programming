#include<bits/stdc++.h>
using namespace std;


#define ll long long

ll powa[1000006];
// set<ll> all_powa;

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    }
    return a;
}

int main(){
    ll a,b,p,x; cin>>a>>b>>p>>x;
    powa[0]=1;
    for(int i=1;i<=p;++i)powa[i]=powa[i-1]*a%p;
    // for(int i=0;i<p-1;++i)all_powa.insert(powa[i]);
    
    ll ans=0;
    for(ll i=1;i<=p-1;++i){
        if(x<i)continue;
        ll time_of_use_me=(x-i)/(p-1)+1;
        // cout<<"toum: "<<time_of_use_me<<endl;
        ll want=b*pw(powa[i],p-2,p)%p;
        // cout<<"want: "<<want<<endl;
        // if(all_powa.find(want)!=all_powa.end())ans+=time_of_use_me/p;
        ans+=time_of_use_me/p;
        time_of_use_me%=p;
        if(!time_of_use_me)continue;
        ll start=i;
        ll end=i-time_of_use_me+1;
        bool in=0;
        if(end<=want && want<=start)in=1;
        end+=p; start+=p;
        if(end<=want && want<=start)in=1;
        if(in)++ans;
    }
    cout<<ans<<endl;
}
