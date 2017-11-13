#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pow10 jizcjocodioiocdoo

int dp[1111][1111],dp_lim[1111][1111],pow10[1111];

int32_t main(){
    int n,k,m; cin>>n>>k>>m;
    dp[0][0]=1; pow10[1]=1;
    for(int i=1;i<=n;++i){
        pow10[i+1]=pow10[i]*10%k;
        for(int j=0;j<k;++j){
            for(int nu=i==n;nu<10;++nu){
                int nj=(j+nu*pow10[i])%k;
                if(!nj and nu)dp_lim[i][nj]+=dp[i-1][j];
                else dp[i][nj]+=dp[i-1][j];
                dp_lim[i][nj]+=dp_lim[i-1][j];
                /* if(j!=0 or i==1)dp[i][nj]+=dp[i-1][j];
                else dp_lim[i][nj]+=dp[i-1][j];
                if(j and nj)dp_lim[i][nj]+=dp_lim[i-1][j]; */
                /* if(j){
                    if(nj==0){
                        dp[i][0]+=dp[i-1][j];
                    }
                    else{
                        dp[i][nj]+=dp[i-1][j];
                        dp_lim[i][nj]+=dp_lim[i-1][j];
                    }
                }
                else{
                    if((j+nu*pow10[i])%k==0){
                        (i==1?dp[i][0]+=dp[i-1][j]:dp_lim[i][0]+=dp[i-1][j]);
                    }
                    else{
                        if(i==1)dp[i][nj]+=dp[i-1][j];
                        else dp_lim[i][nj]+=dp[i-1][j];
                    }
                } */
                dp[i][nj]%=m;
                dp_lim[i][nj]%=m;
            }
        }
    }
    int ans=0;
    for(int i=0;i<k;++i)ans+=dp_lim[n][i];

/* cout<<"dp:\n";
for(int j=k-1;j>=0;--j){
    for(int i=n;i>=0;--i){
        cout<<dp[i][j]<<" ";
    } cout<<endl;
}
cout<<"dplim:\n";
for(int j=k-1;j>=0;--j){
    for(int i=n;i>=0;--i){
        cout<<dp_lim[i][j]<<" ";
    } cout<<endl;
} */

    cout<<(ans%m+m)%m<<endl;
}
// debug ref by StillFantasy: 28272718
