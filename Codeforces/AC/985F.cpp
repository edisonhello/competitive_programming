#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000087;
const ll p=47017;
const ll ip=784886386;

set<int> pos[30];
int val[200005];
ll hsh[200005],ppp[200005],ipp[200005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q; cin>>n>>q;
    string s; cin>>s;
    for(int i=0;i<n;++i){
        int c=s[i];
        c-='a';
        if(pos[c].size())val[i]=i-*--pos[c].end();
        pos[c].insert(i);
    }
    ppp[0]=1;
    for(int i=1;i<200005;++i)ppp[i]=ppp[i-1]*p%mod;
    ipp[0]=1;
    for(int i=1;i<200005;++i)ipp[i]=ipp[i-1]*ip%mod;
    for(int i=0;i<n;++i){
        if(i)hsh[i]=hsh[i-1];
        (hsh[i]+=ppp[i]*val[i])%=mod;
    }
    
    while(q--){
        int x,y,l; cin>>x>>y>>l; --x, --y;
        ll xhh=hsh[x+l-1]-(x?hsh[x-1]:0);
        ll yhh=hsh[y+l-1]-(y?hsh[y-1]:0);
        if(xhh<0)xhh+=mod;
        if(yhh<0)yhh+=mod;
        xhh=xhh*ipp[x]%mod;
        yhh=yhh*ipp[y]%mod;
        for(int i=0;i<26;++i){
            auto it=pos[i].lower_bound(x);
            if(it==pos[i].end())continue;
            if(*it>=x+l)continue;
            ll base=ppp[*it-x];
            xhh-=base*val[*it]%mod;
            if(xhh<0)xhh+=mod;
        }
        for(int i=0;i<26;++i){
            auto it=pos[i].lower_bound(y);
            if(it==pos[i].end())continue;
            if(*it>=y+l)continue;
            ll base=ppp[*it-y];
            yhh-=base*val[*it]%mod;
            if(yhh<0)yhh+=mod;
        }
        if(xhh==yhh)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}
