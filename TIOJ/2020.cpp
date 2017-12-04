#include<bits/stdc++.h>
using namespace std;

int _dp[111][111];
int dp(int n,int m){
    if(m<n)swap(n,m);
    if(n==m)return 1;
    if(n==0)return 0;
    if(_dp[n][m])return _dp[n][m];
    _dp[n][m]=12344555;
    for(int i=1;i<=n;++i){
        _dp[n][m]=min(_dp[n][m],dp(n-i,i)+dp(m-i,n))+1;
        _dp[n][m]=min(_dp[n][m],dp(i,m-i)+dp(n-i,m))+1;
        _dp[n][m]=min(_dp[n][m],dp(i,m)+dp(n-i,m));
        _dp[n][m]=min(_dp[n][m],dp(i,n)+dp(m-i,n));
    }
    for(int i=n+1;i<=m;++i){
        _dp[n][m]=min(_dp[n][m],dp(i,n)+dp(m-i,n));
    }
    return _dp[n][m];
}

int main(){
    int n,m; cin>>n>>m;
    cout<<dp(n,m)<<endl;
}
