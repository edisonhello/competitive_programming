#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct seg{
    int l,r,v;
} s[100005];

int main(){
    int ts; scanf("%d",&ts); while(ts--){
        int n,k; scanf("%d%d",&n,&k);
        for(int i=0;i<n;++i)scanf("%d%d%d",&s[i].l,&s[i].r,&s[i].v);
        sort(s,s+n,[](const seg &a,const seg &b){ return a.l<b.l; });

        ll ans=0,in=0;
        for(int i=0,j=0;i<n;++i){
            if(i)in-=1ll*(s[i-1].r-s[i-1].l+1)*s[i-1].v;
            while(j<n && s[j].r-s[i].l+1<=k){
                in+=1ll*(s[j].r-s[j].l+1)*s[j].v;
                ++j;
            }
            ans=max(ans,in);
            if(j==n)continue;
            int le=k-(s[j].l-s[i].l);
            if(le>0)ans=max(ans,in+1ll*s[j].v*le);
        }
        in=0;
        for(int i=n-1,j=n-1;i>=0;--i){
            if(i!=n-1)in-=1ll*(s[i+1].r-s[i+1].l+1)*s[i+1].v;
            while(j>=0 && s[i].r-s[j].l+1<=k){
                in+=1ll*(s[j].r-s[j].l+1)*s[j].v;
                --j;
            }
            ans=max(ans,in);
            if(j==-1)continue;
            int le=k-(s[i].r-s[j].r);
            if(le>0)ans=max(ans,in+1ll*s[j].v*le);
        }
        printf("%lld\n",ans);
    }
}
