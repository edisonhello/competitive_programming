#include<bits/stdc++.h>
using namespace std;


int v[300005],dp[300005];
bool hasans(int l,int r){
    if(dp[r-1]-dp[l-2]>0)return 1;
    // for(int i=l-1;i<r;++i){
    //     if(dp[i]-dp[i-1])return 1;
    // }
    // for(int i=l-1;i<r;++i)if(dp[i])return 1;
    return 0;
}
bool can(const int &lim,const int &k,const int &n){
    // cout<<lim<<endl;
    dp[-1]=dp[0]=1;
    for(int i=0;i<k;++i)dp[i]=2;
    int lft=1;
    for(int i=k;i<=n;++i){
        while(v[i]-v[lft]>lim)++lft;
        int rgt=i-k+1;
        if(hasans(lft,rgt))dp[i]=dp[i-1]+1;
        else dp[i]=dp[i-1];
        // if(hasans(lft,rgt))dp[i]=1;
        // else dp[i]=0;
        // cout<<i<<" "<<dp[i]<<" "<<lft<<" "<<rgt<<endl;
    } return dp[n]-dp[n-1];
    // } return dp[n];
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>v[i];
    sort(v+1,v+1+n);
    int L=0,R=1e9+87;
    while(R>L){
        int M=(L+R)>>1;
        if(can(M,k,n))R=M;
        else L=M+1;
    }
    cout<<L<<endl;
}
