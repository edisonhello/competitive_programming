#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;

int dp[1111][22222];

int main(){
    // int n,k; cin>>n>>k;
    dp[1][0]=1;
    for(int i=2;i<=1000;++i){
        ll now=0;
        deque<ll> dq;
        for(int j=0;j<=20000;++j){
            dq.push_back(dp[i-1][j]);
            now+=dp[i-1][j];
            if(dq.size()>i){
                now-=dq.front();
                dq.pop_front();
            }
            dp[i][j]=now%mod;
            // cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
        }
    }
    int t; cin>>t; while(t--){
        int n,k; cin>>n>>k;
        cout<<dp[n][k]<<endl;
    }
}
