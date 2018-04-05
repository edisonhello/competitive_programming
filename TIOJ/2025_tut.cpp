#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll w[3333],p[3333];
ll dp[3333][3333];

int main(){
    int ts; cin>>ts; while(ts--){
        memset(dp,0,sizeof(dp));
        int n,k; cin>>n>>k;
        for(int i=1;i<=n;++i)cin>>w[i];
        for(int i=1;i<=k;++i)cin>>p[i];
        reverse(p+1,p+1+k);
        for(int i=1;i<=k;++i){
            // i-th wind
            for(int j=0;j<=n;++j){
                // already sep j cats to left

            }
        }
    }
}
