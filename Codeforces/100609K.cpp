#include<cstdio>
#include<algorithm>
#include<tuple>
#include<cmath>
#include<utility>
#include <bitset>
using namespace std;

struct point{
    int x,y;
    int i;
} p[5001];

void sort(int n){
    double mx=0,my=0;
    for(int i=1;i<=n;++i)mx+=p[i].x,my+=p[i].y;
    mx/=n, my/=n;
    sort(p+1,p+1+n,[&](const auto &a,const auto &b){ return atan2(a.x-mx,a.y-my)<atan2(b.x-mx,b.y-my); });
}

// long long dp[5001][5001];
bitset<5001> v[5001];
tuple<short,short,short> cf[5001][5001];

long long area(point i,point j,point k){
    return abs(1ll*i.x*j.y+1ll*j.x*k.y+1ll*k.x*i.y-1ll*i.y*j.x-1ll*j.y*k.x-1ll*k.y*i.x);
}
long long area(int i,int j,int k){
    return area(p[i],p[j],p[k]);
}
long long area(tuple<short,short,short> &t){
    return area(get<0>(t),get<1>(t),get<2>(t));
}

int n;

pair<long long,tuple<short,short,short>> dfs(int l, int r) {
    if (v[l][r]) return make_pair(area(cf[l][r]),cf[l][r]);
    int len = (l < r ? r - l + 1 : (n + r) - l + 1);
    if (len < 3) return make_pair(-10000000000000000ll,cf[l][r]);
    if (len == 3) {
        cf[l][r]=make_tuple(l,l%n+1,r);
        if (l < r) return make_pair(area(l, l + 1, r),cf[l][r]);
        else return make_pair(area(l, l % n + 1, r),cf[l][r]);
    }
    long long dp = -10000000000000000ll;
    if(dfs(l%n+1,r).first>dp){
        dp=dfs(l%n+1,r).first;
        cf[l][r]=dfs(l%n+1,r).second;
    }
    if(dfs(l,(r==1?n:r-1)).first>dp){
        dp=dfs(l,(r==1?n:r-1)).first;
        cf[l][r]=dfs(l,(r==1?n:r-1)).second;
    }
    if(area(l,l%n+1,r)>dp){
        dp=area(l,l%n+1,r);
        cf[l][r]=make_tuple(l,l%n+1,r);
    }
    if(area(r,r==1?n:r-1,l)>dp){
        dp=area(r,r==1?n:r-1,l);
        cf[l][r]=make_tuple(r,r==1?n:r-1,l);
    }
    // dp[l][r] = min(dp[l][r], min(dfs(l % n + 1, r), area(l, l % n + 1, r)));
    // dp[l][r] = min(dp[l][r], min(dfs(l, (r == 1 ? n : r - 1)), area(r, (r == 1 ? n : r - 1), l)));
    v[l][r] = true;
    return make_pair(dp,cf[l][r]);
}

int main(){
    freopen("kids.in","r",stdin);
    freopen("kids.out","w",stdout);
    scanf("%d", &n);
    for(int i=1;i<=n;++i)scanf("%d %d", &p[i].x, &p[i].y), p[i].i = i;
    sort(n);
    /* for(int i=1;i<=n;++i){
        int nx1=i%n+1;
        int nx2=(i+1)%n+1;
        dp[i][nx2]=area(i,nx1,nx2);
    } */
    long long ans=-7122;
    int ani=-1,anj=-1;
    for(int i=1;i<=n;++i){
        for(int j=i%n+1,z=0;z<n-2;++z,j=(j==n?1:j+1)){
            long long val=max(dfs(i,j).first,dfs(j%n+1,i).first)-area(i,j,j%n+1);
            if(val>ans){
                ans=val;
                ani=i;
                anj=j;
            }
        }
    }
    printf("%lld.%d\n", ans / 2, (ans & 1 ? 5 : 0));
    if(dfs(ani,anj).first>dfs(anj+1,ani).first){
        int a,b,c; tie(a,b,c)=dfs(ani,anj).second;
        printf("%d %d %d\n", p[a].i, p[b].i, p[c].i);
    }
    else{
        int a,b,c; tie(a,b,c)=dfs(anj+1,ani).second;
        printf("%d %d %d\n", p[a].i, p[b].i, p[c].i);
    }
    printf("%d %d %d\n", p[ani].i, p[anj].i, p[anj % n + 1].i);
}
