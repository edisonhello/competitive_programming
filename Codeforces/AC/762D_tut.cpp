#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[100005][5],a[100005][5];

int main(){
    int n; cin>>n;
    for(int i=1;i<=3;++i){
        for(int j=1;j<=n;++j)cin>>a[j][i];
    }
    memset(dp,0xa0,sizeof(dp));
    dp[0][1]=0;
    for(int i=1;i<=n;++i){
        auto get=[&](int z,int x){ll rt=0; if(z>x)swap(z,x); for(int c=z;c<=x;++c)rt+=a[i][c]; return rt;};
        for(int pj=1;pj<=3;++pj){
            for(int nj=1;nj<=3;++nj){
                dp[i][nj]=max(dp[i][nj],dp[i-1][pj]+get(pj,nj));
            }
        }
        if(i>=2){
            ll gooo=0;
            for(int j=1;j<=3;++j)gooo+=a[i-1][j]+a[i][j];
            dp[i][3]=max(dp[i][3],dp[i-2][1]+gooo);
            dp[i][1]=max(dp[i][1],dp[i-2][3]+gooo);
        }
    }
    cout<<dp[n][3]<<endl;
}
