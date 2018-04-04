// copy from 662C
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll cnt[1<<20],cb[1<<20];
string mp[20];

#define mid ((l+r)>>1)
void xorfwt(ll *a,int l,int r){
    if(l==r)return;
    xorfwt(a,l,mid); xorfwt(a,mid+1,r);
    for(int i=l,j=mid+1;i<=mid;++i,++j){
        tie(a[i],a[j])=make_pair(a[i]+a[j],a[i]-a[j]);
    }
}
void xorifwt(ll *a,int l,int r){
    if(l==r)return;
    for(int i=l,j=mid+1;i<=mid;++i,++j){
        tie(a[i],a[j])=make_pair((a[i]+a[j])>>1,(a[i]-a[j])>>1);
    }
    xorifwt(a,l,mid); xorifwt(a,mid+1,r);
}

int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<n;++i)cin>>mp[i];
    for(int j=0;j<m;++j){
        int t=0;
        for(int i=0;i<n;++i){
            t^=(mp[i][j]=='1')<<i;
        }
        ++cnt[t];
    }
    auto _cb=[](int x,int c=0){while(x)++c,x-=x&-x; return c;};
    for(int i=0;i<(1<<n);++i)cb[i]=min(_cb(i),_cb((~i)&((1<<n)-1)));

    xorfwt(cnt,0,(1<<n)-1); xorfwt(cb,0,(1<<n)-1);
    for(int i=0;i<(1<<n);++i)cnt[i]*=cb[i];
    xorifwt(cnt,0,(1<<n)-1);

    int ans=1<<30;
    for(int i=0;i<(1<<n);++i)ans=min(ans,int(cnt[i]));
    cout<<ans<<endl;
}
