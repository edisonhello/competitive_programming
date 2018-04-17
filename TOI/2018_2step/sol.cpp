#include<bits/stdc++.h>
using namespace std;

int dp[102][1002];
int h[101],g[101],dta[201];

int main(){
    int p,q,n; cin>>p>>q>>n;
    for(int i=1;i<=200;++i){
        dta[i]=-192393;
        for(int j=0;j*q<i;++j){
            dta[i]=max(dta[i],j-(i-j*q-1)/p-1);
        }
        // cout<<"dta["<<i<<"]="<<dta[i]<<endl;
    }
    for(int i=1;i<=n;++i)cin>>h[i]>>g[i];
    memset(dp,0xa0,sizeof(dp));
    dp[0][1]=0;
    for(int i=1;i<=n;++i){
        #define get_this
        // cout<<i<<" dta: "<<dta[i]<<endl;
        for(int j=0;j<1002;++j){
            if(0>j+dta[h[i]] || j+dta[h[i]]>=1002)continue;
            dp[i][j+dta[h[i]]]=max(dp[i][j+dta[h[i]]],dp[i-1][j]+g[i]);
        }
        #define if_give_up_this
        int store=(h[i]-1)/q+1;
        // cout<<i<<" store "<<store<<endl;
        for(int j=0;j+store<1002;++j){
            dp[i][j+store]=max(dp[i][j+store],dp[i-1][j]);
        }
        // for(int j=0;j<=10;++j)cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    }
    int ans=-12838;
    for(int i=0;i<1002;++i)ans=max(dp[n][i],ans);
    cout<<ans<<endl;
}
