#pragma GCC optimize("O3")
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long

struct frac{
    ll u,d;
    void meow(){
        ll g=__gcd(u,d);
        u/=g, d/=g;
    }
};
bool operator<(const frac &a,const frac &b){return a.u*b.d<b.u*a.d;}
bool operator>(const frac &a,const frac &b){return a.u*b.d>b.u*a.d;}

ll d[1003][1003];
ll dp[1003][1003];

int main(){
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%lld",&d[i][j]);
            if(d[i][j]==0)d[i][j]=0x3f3f3f3f3f3f3f3f;
        }
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++)dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dp[i][k]=min(dp[i-1][j]+d[j][k],dp[i][k]);
            }
        }
    }
    frac ans={1ll<<32,1};
    for(int i=1;i<=n;i++){
        if(dp[n][i]==0x3f3f3f3f3f3f3f3f)continue;
        frac mx={0,1};
        for(int j=n-1;j>=0;j--){
            if((dp[n][i]-dp[j][i])*mx.d>mx.u*(n-j)){
                mx.u=dp[n][i]-dp[j][i];
                mx.d=n-j;
            }
        }
        ans=min(ans,mx);
    }
    ans.meow();
    if(ans.u==1ll<<32)puts("-1 -1");
    else printf("%lld %lld\n",ans.u,ans.d);
}
