#include<bits/stdc++.h>
using namespace std;
#define ld double
#define int long long

pair<int,int> a[555];
int n,w;
ld dp[255][1111];

ld chk(ld x){
    sort(a,a+n,[&](const pair<int,int> &a,const pair<int,int> &b){
        return a.second-x*a.first>b.second-x*b.first;
    });
    ld tt=-(1ll<<61);
    for(int i=0;i<=n;++i)for(int j=0;j<=w;++j)dp[i][j]=-1e15;
    dp[0][0]=0;
    for(int i=1,j;i<=n;++i){
        for(int j=0;j<=w;++j)dp[i][j]=dp[i-1][j];
        ld val=a[i-1].second-x*a[i-1].first;
        for(j=0;j+a[i-1].first<=w;++j){
            dp[i][j+a[i-1].first]=max(dp[i][j+a[i-1].first],dp[i-1][j]+val);
        }
        for(;j<=w;++j)tt=max(tt,dp[i-1][j]+val);
    }
    tt=max(tt,dp[n][w]);

    return tt;
}

int32_t main(){
#ifndef WEAK
    freopen("talent.in","r",stdin);
    freopen("talent.out","w",stdout);
#endif
    cin>>n>>w;
    for(int i=0;i<n;++i){
        cin>>a[i].first>>a[i].second;
    }
    ld L=0,R=1e14;
    while(R-L>1e-10){
        ld m=(L+R)/2;
        if(chk(m)>=-1e-8)L=m;
        else R=m;
    }
    cout<<fixed<<setprecision(0)<<floor(L*1000)<<endl;
}
