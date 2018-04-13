#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;
const ll p=100;

int a[300005];
ll pp[300005],bit[300005],tmp[300005];

void add(int x,ll v){
    // cout<<"add "<<v<<" at "<<x<<endl;
    for(;x<300005;x+=x&-x)bit[x]=(bit[x]+v)%mod;
}
ll query(int x,ll v=0){
    for(;x;x-=x&-x)v+=bit[x];
    return v%mod;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    pp[0]=1;
    for(int i=1;i<300005;++i)pp[i]=pp[i-1]*p%mod;
    // for(int i=0;i<=n;++i)cout<<i<<" pp "<<pp[i]<<endl;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    auto get=[&](int l,int r){
        return (query(r)-query(l-1)+mod)%mod*pp[n-r]%mod;
    };
    for(int i=1;i<=n;++i){
        add(a[i],pp[a[i]]);
        int w=min(a[i]-1,n-a[i]);
        // cout<<i<<" "<<a[i]<<" "<<w<<" "<<get(a[i],a[i]+w)<<endl;
        tmp[i]=get(a[i],a[i]+w);
    }
    memset(bit,0,sizeof(bit));
    /* for(int i=1;i<=n;++i){
        a[i]=n+1-a[i];
    } */
    for(int i=1;i<=n;++i){
        add(n+1-a[i],pp[n+1-a[i]]);
        int w=min(a[i]-1,n-a[i]);
        // cout<<i<<" "<<a[i]<<" "<<w<<" "<<get(n+1-a[i],n+1-a[i]+w)<<endl;
        if(tmp[i]!=get(n+1-a[i],n+1-a[i]+w))exit((cout<<"YES"<<endl,0));
    }

    cout<<"NO"<<endl;
}
