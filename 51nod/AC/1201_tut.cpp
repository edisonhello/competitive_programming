#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int mod=1000000007;

int dp[50005][1000];
int main(){
    int n; cin>>n;
    dp[0][0]=1;

    for(int i=1;i<=n;++i){
        for(int j=1;j*(j+1)/2<=i;++j){
            dp[i][j]=(dp[i-j][j]+dp[i-j][j-1])%mod;
        }
    }

    /* for(int i=1;i<=n;++i){
        for(int j=min(n-i,(i+1)*i/2-i);j>=0;--j){
            // if(i+j>n)break;
            for(int k=0;k<n;++k){
                if(k*(k-1)/2>j)break;
                // cout<<"upd "<<j+i<<" "<<k+1<<" with "<<j<<" "<<k<<" : "<<dp[j][k]<<endl;
                dp[j+i][k+1]=(dp[j+i][k+1]+dp[j][k])%mod;
            }
            // cout<<"-----"<<endl;
        }
    }

    for(int i=0;i<=n;++i){
        for(int j=0;j*(j+1)/2<=n;++j){
            printf("%4d",dp[i][j]);
        }
        cout<<endl;
    } */

    ll ans=0;
    for(int i=1;i<1000;++i)ans+=dp[n][i];
    cout<<ans%mod<<endl; 
}
