#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lb(x) ((x)&-(x))

ll bit[12][100005];

ll dp[100005][12];

void add(ll *bit,int x,ll val){
    for(;x<100005;x+=lb(x))bit[x]+=val;
}
ll query(ll *bit,int x,ll rt=0){
    for(;x;x-=lb(x))rt+=bit[x];
    return rt;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k; ++k;
    ll ans=0;
    for(int i=1;i<=n;++i){
        int a; cin>>a;
        dp[i][1]=1;
        for(int j=2;j<=k;++j){
            dp[i][j]=query(bit[j-1],a);
            // cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
        }
        for(int j=1;j<=k;++j){
            add(bit[j],a,dp[i][j]);
        }
        ans+=dp[i][k];
    }
    cout<<ans<<endl;
}
