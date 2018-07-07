#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

ll inv(ll x){
    return pw(x,mod-2,mod);
}

ll a[100005],rinv[100005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=1;i<100005;++i)rinv[i]=inv(i);
    int ts; cin>>ts; while(ts--){
        ll all=1;
        int n; cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        for(int i=1;i<=n;++i)all=all*a[i]%mod;
        // cout<<"all: "<<all<<endl;
        ll ans=0;
        for(int i=1;i<=n;++i){
            ans+=all*rinv[a[i]]%mod*(a[i]-1)%mod;
        }
        cout<<ans%mod<<endl;
    }
}
