#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod=1000000007;
ll rep[100005],dp[100005];
int main(){
    int n; cin>>n;
    ll pre=1;
    for(int i=1;i<=n;++i){
        int t; cin>>t;
        dp[i]=(pre-rep[t]+mod)%mod;
        rep[t]=pre;
        pre=(pre+dp[i])%mod;
    }
    cout<<(pre-1)%mod<<endl;
}
