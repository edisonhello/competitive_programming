#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,k;
ll a[300005];
ll dp[50005],pre[300005];
bitset<50005> v;
int cf[50005];

ll calc(int l,int r){
    int midl=(l+r)/2-1, midr=(l+r+1)/2+1;
    midl=max(midl,l); midr=min(midr,r);
    ll rt=1ll<<60;
    for(int i=midl;i<=midr;++i){
        ll nw=pre[r]-pre[i]-a[i]*(r-i)+a[i]*(i-l)-(pre[i-1]-pre[l-1]);
        if(nw<rt){
            rt=nw;
        }
    }
    return rt;
}

ll go(int now){
    if(now==0)return 0;
    if(now<k)return 1ll<<60;

    if(v[now])return dp[now];
    v[now]=1;

    ll rt=1ll<<60;
    int tcf=-1;
    for(int i=now-k+1,cnt=0;i>=1 && cnt<=2*k;++cnt,--i){
        ll nw=go(i-1)+calc(i,now);
        if(nw<rt){
            rt=nw;
            tcf=i;
        }
    }
    cf[now]=tcf;
    return dp[now]=rt;
}

int main(){
//    freopen("in.txt","r",stdin);
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+1+n);
//    for(int i=1;i<=n;++i)cout<<a[i]<<" "; cout<<endl;

    for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];



    cout<<go(n)<<endl;
//    for(int i=k;i<=n;++i)if(cf[i])cout<<i<<" "<<dp[i]<<" "<<cf[i]-1<<endl;
}

