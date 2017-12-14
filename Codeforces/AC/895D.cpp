#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
#define ll long long
#define lb(x) ((x)&-(x))
int cnt[9393],pre[28282];
void add(int x,int v=1){
    for(;x<333;x+=lb(x))pre[x]+=v;
}
int qry(int x,int v=0){
    for(;x;x-=lb(x))v+=pre[x];
    return v;
}
ll _fac[1000005],_inv[1000005];
ll fac(ll x){
    if(_fac[0])return _fac[x];
    _fac[0]=1; for(int i=1;i<1000005;++i){
        _fac[i]=_fac[i-1]*i%mod;
    } return _fac[x];
}
ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}
ll inv(ll x){
    static bool first_in_inv=1;
    if(first_in_inv){
        first_in_inv=0;
        _inv[1000004]=pw(_fac[1000004],mod-2,mod);
        for(int i=1000003;i>=0;--i)_inv[i]=_inv[i+1]*(i+1)%mod;
    }
    return _inv[x];
}
int main(){
    string s,t; cin>>s>>t;
    for(char c:s)++cnt[c],add(c,1);
    long long ans=0,mins=0;
    for(int i=0;i<s.size();++i){
        ll son=fac(qry('z')-1)%mod;
        // cout<<"son: "<<son<<endl;
        for(int j='a';j<='z';++j)if(cnt[j])son=son*inv(cnt[j])%mod;
        // cout<<"son: "<<son<<endl;
        for(int j='a';j<t[i];++j){
            if(!cnt[j])continue;
            // cout<<"j: "<<(char)j<<" cnt: "<<cnt[j]<<endl;
            ans=(ans+(son*(cnt[j]))%mod)%mod;
            // cout<<"ans is now "<<ans<<endl;
        }
        if(!cnt[t[i]])break;
        --cnt[t[i]]; add(t[i],-1);
    }
    // cout<<"Get ans "<<ans<<endl;
    memset(pre,0,sizeof(pre));
    memset(cnt,0,sizeof(cnt));
    for(char c:s)add(c,1),++cnt[c];
    t=s;
    for(int i=0;i<s.size();++i){
        // cout<<"now i: "<<i<<endl;
        ll son=fac(qry('z')-1)%mod;
        // cout<<"son: "<<son<<endl;
        for(int j='a';j<='z';++j)if(cnt[j])son=son*inv(cnt[j])%mod;
        // cout<<"son: "<<son<<endl;
        for(int j='a';j<t[i];++j){
            if(!cnt[j])continue;
            // cout<<"j: "<<(char)j<<" cnt: "<<cnt[j]<<endl;
            mins=(mins+(son*(cnt[j]))%mod)%mod;
            // cout<<"mins is now "<<mins<<endl;
        }
        if(!cnt[t[i]])break;
        --cnt[t[i]]; add(t[i],-1);
    }

    cout<<(ans-mins-1+mod*2)%mod<<endl;
}
