#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll pre[500005],suf[500005],a[500005];

int main(){
    int n; cin>>n;
    ll tot=0,tar;
    for(int i=1;i<=n;++i)cin>>a[i],tot+=a[i];
    for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
    for(int i=n;i>=1;--i)suf[i]=suf[i+1]+a[i];
    map<ll,int> mp;
    if(tot%3)return cout<<0<<endl,0;
    tar=tot/3;
    ll ans=0;
    for(int i=2;i<=n;++i){
        if(suf[i]==tar)ans+=mp[tar];
        if(i-1)++mp[pre[i-1]];
    }
    cout<<ans<<endl;
}
