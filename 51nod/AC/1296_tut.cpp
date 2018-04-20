#include<bits/stdc++.h>
using namespace std;

const long long mod=1000000007;
long long dp[5005],pre[5005],ans;
int rst[5005];

int main(){
    int n,k,l; cin>>n>>k>>l;
    for(int i=0;i<k;++i){
        int t; cin>>t; rst[t+1]|=1; rst[t+2]|=2;
    }
    for(int i=0;i<l;++i){
        int t; cin>>t; rst[t+1]|=2; rst[t+2]|=1;
    }
    pre[1]=pre[2]=pre[3]=pre[4]=1;
    for(int i=2;i<=n;++i){
        if(rst[i]==0){
            for(int j=1;j<=i;++j){
                dp[j]=pre[i-1]-pre[0];
            }
        }
        else if(rst[i]==1){
            for(int j=1;j<=i;++j){
                dp[j]=pre[i-1]-pre[j-1];
            }
        }
        else if(rst[i]==2){
            for(int j=1;j<=i;++j){
                dp[j]=pre[j-1]-pre[0];
            }
        }
        else exit((cout<<0<<endl,0));
        if(i<n)for(int j=1;j<=n;++j){
            pre[j]=(pre[j-1]+dp[j])%mod;
        }
        else for(int j=1;j<=n;++j)ans+=dp[j];
    }
    cout<<(ans%mod+mod)%mod<<endl;
}
