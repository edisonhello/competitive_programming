#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct turtle{
    int m,w,cap;
    void Cap(){cap=m-w;}
} a[5678];
int n,dp[5678];

int main(){
    int x,y; while(cin>>x>>y){
        a[n].w=x; a[n].m=y; a[n].Cap();
        if(a[n].cap>=0)++n;
    }
    sort(a,a+n,[](const turtle &a,const turtle &b){return a.m<b.m;});
    memset(dp,0x3f,sizeof(dp)); dp[0]=0;
    // for(int i=0;i<n;++i)dp[1]=min(dp[1],a[i].w);
    for(int i=0;i<n;++i){
        for(int j=n;j>=1;--j){
            if(dp[j-1]+a[i].w>a[i].m)continue;
            dp[j]=min(dp[j],dp[j-1]+a[i].w);
            // dp[i]=min(dp[i],dp[i-1]+a[j].w);
        }
        // cout<<dp[1]<<" "<<dp[2]<<" "<<dp[3]<<" "<<dp[4]<<endl;
    }
    int ans=n; while(dp[ans]==0x3f3f3f3f)--ans;
    cout<<ans<<endl;
}
