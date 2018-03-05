#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[55];
ll fac[55];
map<ll,int> dp[30][30];
int main(){
    int n,k; ll s; cin>>n>>k>>s;
    fac[0]=1;
    for(int i=1;i<=18;++i)fac[i]=fac[i-1]*i;
    dp[0][0][0]=1;
    if(n<=3){
        for(int i=1;i<=n;++i){
            cin>>a[i];
            for(int j=0;j<=k;++j){
                // cout<<i<<" "<<j<<endl;
                for(auto p:dp[i-1][j]){
                    dp[i][j][p.first]+=p.second;
                    if(p.first+a[i]<=s)dp[i][j][p.first+a[i]]+=p.second;
                }
                if(j && a[i]<=18)for(auto p:dp[i-1][j-1]){
                    if(p.first+fac[a[i]]<=s)dp[i][j][p.first+fac[a[i]]]+=p.second;
                }
            }
            for(int j=0;j<=k;++j)dp[i-1][j].clear();
        }
        ll ans=0;
        for(int i=0;i<=k;++i)ans+=dp[n][i][s];
        cout<<ans<<endl;
        return 0;
    }
    else{
        for(int i=1;i<=n/2;++i){
            cin>>a[i];
            for(int j=0;j<=k;++j){
                // cout<<i<<" "<<j<<endl;
                for(auto p:dp[i-1][j]){
                    dp[i][j][p.first]+=p.second;
                    if(p.first+a[i]<=s)dp[i][j][p.first+a[i]]+=p.second;
                }
                if(j && a[i]<=18)for(auto p:dp[i-1][j-1]){
                    if(p.first+fac[a[i]]<=s)dp[i][j][p.first+fac[a[i]]]+=p.second;
                }
            }
            for(int j=0;j<=k;++j)dp[i-1][j].clear();
        }
        // for(int j=0;j<=k;++j)for(auto p:dp[2][j])cout<<"("<<p.first<<","<<p.second<<")"<<endl;
        dp[n/2+1][0][0]=1;
        ll ans=0;
        for(int i=n/2+2;i<=n+1;++i){
            cin>>a[i];
            for(int j=0;j<=k;++j){
                // cout<<i<<" "<<j<<endl;
                for(auto p:dp[i-1][j]){
                    dp[i][j][p.first]+=p.second;
                    if(p.first+a[i]<=s)dp[i][j][p.first+a[i]]+=p.second;
                }
                if(j && a[i]<=18)for(auto p:dp[i-1][j-1]){
                    if(p.first+fac[a[i]]<=s)dp[i][j][p.first+fac[a[i]]]+=p.second;
                }
            }
            for(int j=0;j<=k;++j)dp[i-1][j].clear();
            if(i==n+1)for(int j=0;j<=k;++j){
                for(auto p:dp[i][j]){
                    for(int jj=0;jj+j<=k;++jj){
                        // printf("%d %d
                        ans+=dp[n/2][jj][s-p.first]*p.second;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
