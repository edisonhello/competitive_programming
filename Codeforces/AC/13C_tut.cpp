#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[5005],b[5005];

/* bitset<5005> v[5005];
ll rec[5005][5005];
ll dfs(int ptr,int mx){
    if(mx<=0)return 1ll<<60;
    if(ptr==1)return min((ll)abs(b[mx]-a[ptr]),dfs(ptr,mx-1));
    if(v[ptr][mx])return rec[ptr][mx];
    v[ptr][mx]=1;
    return rec[ptr][mx]=min(dfs(ptr,mx-1),dfs(ptr-1,mx)+abs(b[mx]-a[ptr]));
} */

ll dp[2][5005];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+n);
    // cout<<dfs(n,n)<<endl;
    dp[1][0]=1ll<<60;
    for(int i=1;i<=n;++i)dp[1][i]=min((ll)abs(b[i]-a[1]),dp[1][i-1]);
    ll an=1ll<<60;
    for(int i=2;i<=n;++i){
        dp[i&1][0]=1ll<<60;
        for(int j=1;j<=n;++j){
            dp[i&1][j]=min(dp[i&1][j-1],dp[(i-1)&1][j]+abs(a[i]-b[j]));
            if(i==n)an=min(an,dp[i&1][j]);
        }
    }
    if(n==1)an=0;
    cout<<an<<endl;
}
