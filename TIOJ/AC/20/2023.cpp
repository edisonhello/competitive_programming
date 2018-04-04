#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;
ll dp[1<<22]; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    while(m--){
        string s; int v;
        cin>>s>>v;
        int val=0;
        for(int i=0;i<n;++i){
            val^=((1&(s[i]=='1'))<<i);
        }
        dp[val]+=v;
    }
    for(int i=1;i<=n;++i){
        for(int j=(1<<n)-1;j>=0;--j){
            // dp[i][j]=dp[i-1][j];
            if(j&(1<<(i-1)))dp[j]+=dp[j^(1<<(i-1))];
        }
    }
    vector<int> cost(1<<n);
    for(int i=0;i<(1<<n);++i)cost[i]=dp[i];
    sort(cost.begin(),cost.end());

    // for(int i=0;i<(1<<n);++i)cout<<i<<" "<<dp[n][i]<<endl;

    ll ans=0,mul=1;
    bool skip=0;
    for(int i=0;i<(1<<n);++i){
        if(cost[i]==0 && !skip){
            skip=1;
            continue;
        }
        ans+=(cost[i]*mul);
        ++mul;
    }
    cout<<ans<<endl;
}
