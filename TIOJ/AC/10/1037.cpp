#include<bits/stdc++.h>
using namespace std;
bool dp[10002][103][103];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;cin>>n>>m;
    int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    dp[0][x1][y1]=1;
    int ss;cin>>ss;
    for(int i=1;i<=ss;++i){
        int step;cin>>step;
        for(int j=0;j<=n;++j){
            for(int k=0;k<=m;++k){
                if(dp[i-1][j][k]){
                    dp[i][j][(k+step+m)%m]=dp[i][j][(k-step+100*m)%m]=dp[i][(j+step+n)%n][k]=dp[i][(j-step+100*n)%n][k]=1;
                }
            }
        }
    }
    if(dp[ss][x2][y2]){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
}
