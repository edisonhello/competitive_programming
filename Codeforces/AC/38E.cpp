#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[3333],x[3333],c[3333],xpre[3333];
pair<ll,ll> xxxx[3333];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x[i]>>c[i];
        xxxx[i-1]={x[i],c[i]};
    }
    sort(xxxx,xxxx+n);
    for(int i=1;i<=n;++i){
        tie(x[i],c[i])=xxxx[i-1];
        xpre[i]=xpre[i-1]+x[i];

    }

    dp[1]=c[1];
    for(int i=2;i<=n;++i){
        dp[i]=c[i];
        ll mn=1ll<<61;
        for(int j=i-1;j>=1;--j){
            mn=min(mn,dp[j]+xpre[i-1]-xpre[j]-x[j]*(i-j-1));
        }
        dp[i]+=mn;
    }
    ll mn=1ll<<61;
    for(int i=1;i<=n;++i){
        // cout<<"ans of last in "<<i<<" : "<<dp[i]+xpre[n]-xpre[i]-x[i]*(n-i)<<" ( dp is "<<dp[i]<<" ) "<<endl;
        mn=min(mn,dp[i]+xpre[n]-xpre[i]-x[i]*(n-i));
    }
    cout<<mn<<endl;
}
