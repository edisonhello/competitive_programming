#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=123456789;
ll dp[1000006],pre[1000006];

int main(){
    int n,itv; cin>>n>>itv;
    dp[1]=pre[1]=1;
    for(int i=2;i<=n;++i){
        dp[i]=pre[i-1]-pre[max(0,i-itv-1)];
        pre[i]=(pre[i-1]+dp[i])%mod;
    }
    ll ans=0;
    for(int i=1,ptr=n;i<=itv;--ptr,++i){
        ans+=dp[ptr]*i%mod;
    }
    cout<<(ans%mod+mod)%mod<<endl;
}
