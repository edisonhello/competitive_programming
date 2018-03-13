#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[44][44],ans;

int main(){
    int n,h; cin>>n>>h;
    dp[0][0]=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
                // left height: j-1
                // right height k: 0 to j-2
                // left tree size l: j-1 to i
                // right tree size: i-1-l
            for(int k=0;k<j-1;++k){
                for(int l=j-1;l<i;++l){
                    dp[i][j]+=dp[l][j-1]*dp[i-1-l][k];
                }
            }
            dp[i][j]<<=1;
            // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                // both height: j-1
                // left size k: j-1 to i
                // right size: i-1-k
            for(int k=j-1;k<i;++k){
                if(i-1-k<0)break;
                dp[i][j]+=dp[k][j-1]*dp[i-1-k][j-1];
            }
            // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            if(i==n && j>=h)ans+=dp[i][j];
        }
    }
    cout<<ans<<endl;    
}
