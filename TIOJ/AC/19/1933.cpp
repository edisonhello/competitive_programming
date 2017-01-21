#include<cstdio>
#include<algorithm>
using namespace std;

struct _{
    long long x,t;
} a[100005];

bool cmp_xt(const _ &a,const _ &b){
    return a.x+a.t<b.x+b.t;
}

signed main(){
    long long ans;
    int ts,i,n,l,c,t;scanf("%d",&ts);while(ts--){
        ans=0;
        scanf("%d%d%d",&n,&l,&c);
        for(i=0;i<n;++i){scanf("%lld%lld",&a[i].x,&a[i].t);}
        sort(a,a+n,cmp_xt);
        for(i=0,t=-1;i<n;++i){
            if(a[i].x<t)continue;
            t=a[i].x+a[i].t;
            ans+=c-t;
        }
        printf("%lld\n",ans);
    }
}
