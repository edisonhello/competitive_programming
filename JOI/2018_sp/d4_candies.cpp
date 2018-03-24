#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];
int nxt[200005],prv[200005];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)nxt[i]=i+1,prv[i]=i-1;
    nxt[n]=-1; prv[1]=-1;
    ll ans=0;
    multiset<pair<ll,int>> st;
    for(int i=1;i<=n;++i)st.insert({a[i],i});
    int cnt=0;
    while(cnt<(n+1)/2){
        ++cnt;
        auto rec=*--st.end();
        st.erase(--st.end());
        ans+=rec.first;
        cout<<ans<<'\n';
        int pos=rec.second;
        ll nv=(nxt[pos]==-1?-(1ll<<61):a[nxt[pos]])+(prv[pos]==-1?-(1ll<<61):a[prv[pos]])-a[pos];
        if(nv<-(1ll<<61))nv=-(1ll<<61);
        a[pos]=nv;
        auto kill=[&](int now){
            if(now==-1)return;
            st.erase({a[now],now});
            nxt[prv[now]]=nxt[now];
            prv[nxt[now]]=prv[now];
        };
        kill(nxt[pos]); kill(prv[pos]);
        st.insert({a[pos],pos});
    }
}
 /* tutorial by IKC */
 // first submit AC
