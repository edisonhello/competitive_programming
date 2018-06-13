#include<bits/stdc++.h>
using namespace std;

int a[100005],nxt[100005],prv[100005];

int main(){
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<n;++i)a[i]=a[i+1]-a[i]; --n;
    a[0]=a[n+1]=1e9;
    for(int i=0;i<=n+1;++i)prv[i]=i-1,nxt[i]=i+1;
    set<pair<int,int>> st;
    for(int i=1;i<=n;++i)st.insert({a[i],i});
    int ans=0;
    while(k--){
        auto p=*st.begin(); st.erase(st.begin());
        // cout<<p.first<<" "<<p.second<<endl;
        ans+=p.first;
        st.erase({a[nxt[p.second]],nxt[p.second]});
        st.erase({a[prv[p.second]],prv[p.second]});
        a[p.second]=a[nxt[p.second]]+a[prv[p.second]]-a[p.second];
        prv[nxt[nxt[p.second]]]=p.second;
        nxt[prv[prv[p.second]]]=p.second;
        nxt[p.second]=nxt[nxt[p.second]];
        prv[p.second]=prv[prv[p.second]];
        st.insert({a[p.second],p.second});
    }
    cout<<ans<<endl;
}
