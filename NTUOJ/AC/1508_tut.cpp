#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

int c[105],dp[105][105];

#define fgo(i,j) ((dp[i][j]?dp[i][j]:(i)>(j)?0:(i)==(j)?1:go(i,j)))

int go(int l,int r){
    // if(dp[l][r])return dp[l][r];
    int &ans=dp[l][r]=r-l+1;
    ans=min(ans,1+fgo(l+1,r));
    ans=min(ans,1+fgo(l,r-1));
    for(int i=l+1;i<=r;++i){
        if(c[l]!=c[i])continue;
        ans=min(ans,fgo(l,i-1)+fgo(i+1,r));
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,k=0; cin>>t; while(t--){
        memset(dp,0,sizeof(dp));
        int n,m; cin>>n>>m;
        for(int i=1;i<=n;++i)cin>>c[i];
        cout<<"Case "<<(++k)<<": ";
        cout<<fgo(1,n)<<'\n';
    }
}
