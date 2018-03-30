#include<bits/stdc++.h>
using namespace std;

const long long mod=1000000007;

int a[1000006];
int dp[22][1000006];

long long pw(long long b,int n,long long m,long long a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

int main(){
    ios_base::sync_with_stdio(0);
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        ++dp[0][a[i]];
    }
    for(int i=0;i<20;++i){
        for(int j=0;j<=1000000;++j){
            if(j&(1<<i))dp[i+1][j^(1<<i)]+=dp[i][j];
            dp[i+1][j]+=dp[i][j];
        }
    }
    // for(int i=0;i<=10;++i)cout<<i<<" "<<dp[20][i]<<endl;
    long long ans=0;
    for(int i=0;i<=1000000;++i){
        int cbit=0;
        for(int j=0;j<20;++j)if(i&(1<<j))++cbit;
        ans+=(cbit&1?-1ll:1ll)*pw(2,dp[20][i],mod)%mod;
    }
    cout<<((ans+1)%mod+mod)%mod<<endl;
}
