#include<bits/stdc++.h>
using namespace std;

int dp[1000006];
bitset<1000006> ap;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0,t;i<n;++i){
        cin>>t;
        ap[t]=1;
    }
    int mx=0;
    for(int i=1000000;i>=1;--i){
        if(!ap[i])continue;
        for(int j=i*2;j<=1000000;j+=i){
            dp[i]=max(dp[i],dp[j]);
        }
        dp[i]++;
        mx=max(mx,dp[i]);
    }
    cout<<mx<<endl;
}
